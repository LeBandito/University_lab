#include <iostream>
#include <fstream>
#include <string>

struct Menu {
    int length;
    char text[25];
};

Menu encryption(const std::string& s) {
    Menu all;
    
    all.length = s.size();
    
    for (int i = 0; i < s.size(); i++)
        all.text[i] = s[i];// - 2; // то самое "шифрование"
    
    return all;
}

void WriteInf(std::ofstream& f, Menu s) {
    f.write((char*)&s.length, sizeof(s.length));
    f.write(s.text, 50);
}

int main() {
    std::ofstream f("menu.dat", std::ios::binary);
    
    WriteInf(f, encryption("Программа просмотра"));
    WriteInf(f, encryption("Автор: Василий Баганов")); 
    WriteInf(f, encryption("Меню:"));
    WriteInf(f, encryption("1. Просмотр"));
    WriteInf(f, encryption("2. Поиск"));
    WriteInf(f, encryption("3. Добавление"));
    WriteInf(f, encryption("4. Удаление"));
    WriteInf(f, encryption("5. Выход"));
    
    f.close();
    return 0;
}
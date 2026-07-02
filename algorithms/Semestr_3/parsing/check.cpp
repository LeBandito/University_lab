#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

struct Menu {
    int length;
    char text[25];
};

void ReadMenu(std::ifstream& g) {
    Menu OurMenu;
    
    while(g.read((char*)&OurMenu, sizeof(Menu))) {
        std::string text;
        
        for (int i = 0; i < OurMenu.length; i++) {
            text += OurMenu.text[i] + 2;
        }
        
        std::cout << text << std::endl;
    }
    
    std::cout << "Выберите пункт: ";
}

int main() {
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    std::ifstream f("menu.dat", std::ios::binary);
    ReadMenu(f);
    f.close();
    return 0;
}
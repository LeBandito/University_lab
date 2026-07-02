/*Описать структуру с именем NOTE, содержащую следующие поля:
NAME — фамилия, имя;
TELE — номер телефона;
GROUP - категория, к которой относится контакт (семья, работа и т.д.)
BDAY — день рождения (массив из трех чисел).
Написать программу, выполняющую следующие действия:
•	ввод с клавиатуры данных в массив BLOCKNOTE, состоящий из восьми элементов типа NOTE;
•	вывод на экран информации о человеке, номер телефона которого введен с клавиатуры;
•	если такого нет, выдать на дисплей соответствующее сообщение.*/

#include <iostream>
#include <string>

struct NOTE{
    std::string NAME;
    std::string TELE;
    std::string GROUP;
    int BDAY[3];
};

/*
bob
88005553535
bruh
1 2 2000
*/

int main() {
    NOTE BLOKNOTE[8];
    
    for (int i = 0; i < 8; ++i) {
        std::cout << "Eter name:" << std::endl;
        std::getline(std::cin, BLOKNOTE[i].NAME);
        
        std::cout << "Eter telephone:" << std::endl;
        std::getline(std::cin, BLOKNOTE[i].TELE);
        
        std::cout << "Eter group:" << std::endl;
        std::getline(std::cin, BLOKNOTE[i].GROUP);
        
        std::cout << "Eter group (for example - day month year): " << std::endl;
        std::cin >> BLOKNOTE[i].BDAY[0] >> BLOKNOTE[i].BDAY[1] >> BLOKNOTE[i].BDAY[2];
        std::cin.ignore();
    }
    
    std::cout << "Enter telephone: " << std::endl;
    std::string TelSearch;
    std::getline(std::cin, TelSearch);
    
    bool flag = true;
    
    for (int i = 0; i < 8; ++i) {
        if (BLOKNOTE[i].TELE == TelSearch) {
            std::cout << BLOKNOTE[i].NAME << std::endl;
            std::cout << BLOKNOTE[i].TELE << std::endl;
            std::cout << BLOKNOTE[i].GROUP << std::endl;
            std::cout << BLOKNOTE[i].BDAY[0] << 
            " " << BLOKNOTE[i].BDAY[1] << 
            " " << BLOKNOTE[i].BDAY[2] << std::endl;
            flag = false;
        }
    }
    
    if (flag)
        std::cout << "Not Found." << std::endl;
    
    return 0;
}
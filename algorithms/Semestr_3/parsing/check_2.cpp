#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

struct Menu {
    int length;
    char text[25];
};

struct word {
    char word1[100];
    char word2[100];
};

int ReadMenu() {
    std::cout << "Программа просмотра" << std::endl;
    std::cout << "Автор: Василий Баганов" << std::endl;
    std::cout << "Меню:" << std::endl;
    std::cout << "1. Просмотр" << std::endl;
    std::cout << "2. Поиск" << std::endl;
    std::cout << "3. Добавление" << std::endl;
    std::cout << "4. Удаление" << std::endl;
    std::cout << "5. Выход" << std::endl;
    
    int a;
    std::cout << "Выберите пункт: ";
    std::cin >> a;
    
    return a;
}

void ViewWords() {
    std::ifstream g;
    g.open("DataBum.dat", std::ios::in | std::ios::binary);
    word vrem;
    
    while(g.read((char*)&vrem, sizeof(word))) {        
        for (int i = 0; vrem.word1[i] != '\0'; i++) {
            std::cout << vrem.word1[i];
        }
        
        std::cout << " - ";
        
        for (int i = 1; vrem.word2[i] != '\0'; i++) {
            std::cout << vrem.word2[i];
        }
        
        std::cout << std::endl;
    }
}

int main() {
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    ViewWords();
    
    return 0;
}
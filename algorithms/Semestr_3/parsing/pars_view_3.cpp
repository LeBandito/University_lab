#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

struct word {
    char word1[100];
    char word2[100];
};

int ReadMenu() {
    std::wcout << L"Программа просмотра" << std::endl;
    std::wcout << L"Автор: Василий Баганов" << std::endl;
    std::wcout << L"Меню:" << std::endl;
    std::wcout << L"1. Просмотр" << std::endl;
    std::wcout << L"2. Поиск" << std::endl;
    std::wcout << L"3. Добавление" << std::endl;
    std::wcout << L"4. Удаление" << std::endl;
    std::wcout << L"5. Выход" << std::endl;
    
    int a;
    std::wcout << L"Выберите пункт: ";
    std::cin >> a;
    
    return a;
}

void ViewWords() {
    std::ifstream g;
    g.open("DataBum.dat", std::ios::in | std::ios::binary);
    word vrem;
    
    while(g.read((char*)&vrem, sizeof(word))) {        
        std::cout << vrem.word1 << " - " << vrem.word2 << std::endl;
    }
}

void SearchWords() {
    std::ifstream g;
    g.open("DataBum.dat", std::ios::in | std::ios::binary);
    word vrem;
    
    int choice;
    std::wcout << L"По какому слову вы хотите провести поиск? \nПо 1 или 2?" << std::endl;
    std::cin >> choice;
    
    if ((choice != 1) && (choice != 2)) {
        std::wcout << L"Только 1 или 2!" << std::endl;
        return;
    }
    
    std::string OurWord;    
    std::wcout << L"Хорошо! Тогда какое слово ищем?" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, OurWord);
    
    std::wcout << L"Ищем слово: ";
    std::cout << OurWord << std::endl;

    std::string word_1, word_2;
    bool found = false;
    
    while(g.read((char*)&vrem, sizeof(word))) {
        word_1 = vrem.word1;
        word_2 = vrem.word2;
        
        if (((choice == 1) && (word_1 == OurWord)) || ((choice == 2) && (word_2 == OurWord))) {
            std::cout << word_1 << " - " << word_2 << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::wcout << L"Слово не найдено!" << std::endl;
    }
}

void AddWord() {
    std::ofstream g;
    g.open("DataBum.dat", std::ios::app | std::ios::binary);
    
    std::string word_1, word_2;
    
    std::wcout << L"Напишите словоформу и базовую словоформу: " << std::endl;
    std::cin >> word_1 >> word_2;
    
    word vrem;
    
    for (int i = 0; i < 100; i++) {
        vrem.word1[i] = 0;
        vrem.word2[i] = 0;
    }
    
    for (int i = 0; i < word_1.size(); i++)
        vrem.word1[i] = word_1[i];
    vrem.word1[word_1.size()] = '\0';
    
    for (int i = 0; i < word_2.size(); i++)
        vrem.word2[i] = word_2[i];
    vrem.word2[word_2.size()] = '\0';
    
    g.write((char*)&vrem, sizeof(word));
    g.close();  
}

void DeleteWord() {
    std::ifstream g("DataBum.dat", std::ios::binary);
    std::ofstream f("temp.dat", std::ios::binary);
    word vrem;
    
    int choice;
    std::wcout << L"По какому слову вы хотите провести удаление? \nПо 1 или 2?" << std::endl;
    std::cin >> choice;
        
    if ((choice != 1) && (choice != 2)) {
        std::wcout << L"Только 1 или 2!" << std::endl;
        return;
    }
    
    std::string OurWord;    
    std::wcout << L"Хорошо! Тогда какое слово удаляем?" << std::endl;
    std::cin >> OurWord;
    
    bool found = false;

    while(g.read((char*)&vrem, sizeof(word))) {
        std::string word1 = vrem.word1;
        std::string word2 = vrem.word2;
        
        if (((choice == 1) && (word1 == OurWord)) || ((choice == 2) && (word2 == OurWord))) {
            std::wcout << L"УДАЛЕНО: ";
            std::cout << word1 << " - " << word2 << std::endl;
            found = true;
        } else {
            f.write((char*)&vrem, sizeof(word));
        }
    }
    
    if (found) {
        std::wcout << L"Удаление завершено!" << std::endl;
    } else {
        std::wcout << L"Слово не найдено!" << std::endl;
    }
    
    g.close();  
    f.close();  
    remove("DataBum.dat");
    rename("temp.dat", "DataBum.dat");
    
    std::wcout << L"Удалено!" << std::endl;    
}

void Exit() {
    std::wcout << L"Ну всё..." << std::endl;
}

void variants(int OurChoice) {      
    switch(OurChoice)
    {
        case 1:
            ViewWords();
            break;
        case 2: 
            SearchWords();
            break;
        case 3: 
            AddWord();
            break;
        case 4: 
            DeleteWord();
            break;
        case 5: 
            Exit();
            break;
        default: 
            std::wcout << L"Чего? Такого x нету!" << "\n";
            break;
    }
}

int main() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int OurChoice;
    
    do {
        OurChoice = ReadMenu();
        
        variants(OurChoice);
        std::cout << std::endl;
    } while (OurChoice != 5);
    
    return 0;
}


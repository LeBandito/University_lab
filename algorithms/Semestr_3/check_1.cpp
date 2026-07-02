#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void BumIn(std::fstream& f) {
    f.open("qqq.txt", std::ios::in);
    if (!f.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
    }
}

void BumOut(std::fstream& g) {
    g.open("DataBum.dat", std::ios::out);
}

struct word {
    char word1[100];
    char word2[100];
};

void InData(std::fstream& f, std::vector<word>& BomDataBum) {
    if (!f.is_open()) {
        std::cout << "Файл не открыт!" << std::endl;
        return;
    }
    
    std::string words;
    std::cout << "Начало чтения файла..." << std::endl;
    
    while (std::getline(f, words)) {
        std::cout << "Прочитана строка: " << words << std::endl;
        
        if (words.empty()) {
            std::cout << "Пустая строка, пропускаем" << std::endl;
            continue;
        }
        
        word vrem;
        
        // Инициализация
        for (int i = 0; i < 100; i++) {
            vrem.word1[i] = 0;
            vrem.word2[i] = 0;
        }
        
        int i = 0, j = 0, k = 0;
        
        // Первое слово (до пробела)
        while (i < words.length() && words[i] != ' ' && i < 99) {
            vrem.word1[i] = words[i];
            i++;
        }
        vrem.word1[i] = '\0';
        
        // Проверяем, есть ли разделитель " - "
        if (i + 3 >= words.length()) {
            std::cout << "Нет разделителя ' - ', пропускаем строку" << std::endl;
            continue;
        }
        
        j = i + 3; // Пропускаем " - "
        
        // Второе слово
        while (j < words.length() && k < 99) {
            vrem.word2[k] = words[j];
            j++;
            k++;
        }
        vrem.word2[k] = '\0';
        
        BomDataBum.push_back(vrem);
        std::cout << "Добавлена запись: '" << vrem.word1 << "' - '" << vrem.word2 << "'" << std::endl;
    }
    
    std::cout << "Чтение файла завершено. Прочитано записей: " << BomDataBum.size() << std::endl;
}

int main() {
    setlocale(LC_ALL, "");
    std::fstream f;
    BumIn(f);
    
    std::vector<word> BomDataBum;
    
    std::cout << "Вызов InData..." << std::endl;
    InData(f, BomDataBum);
    std::cout << "InData завершена!" << std::endl;
    
    std::cout << "Размер вектора: " << BomDataBum.size() << std::endl;
    
    // Упрощенный вывод
    for (int i = 0; i < BomDataBum.size(); i++) {
        std::cout << "Word1: " << BomDataBum[i].word1 << std::endl;
        std::cout << "Word2: " << BomDataBum[i].word2 << std::endl;
        std::cout << "---" << std::endl;
    }
    
    f.close();
    std::wcout << L"Программа завершена!" << std::endl;
    return 0;
}
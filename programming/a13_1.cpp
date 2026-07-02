/*Введите строку символов с клавиатуры. Измените регистр символа: про-писные заменить на строчные, а строчные на прописные.*/


#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>

void In(std::string& bob) {
    std::cout << "Enter words: ";
    std::getline(std::cin, bob);
}

std::string ChangeWords(std::string& wordsF) {
    int N = wordsF.length();

    for (int i = 0; i < N; i++) {
        if ((islower(wordsF[i]) && isalpha(wordsF[i])) || ((wordsF[i] >= 'а') && (wordsF[i] <= 'я')) || (wordsF[i] == 'ё'))
            wordsF[i] = toupper(wordsF[i]);

        else if ((isupper(wordsF[i]) && isalpha(wordsF[i])) || ((wordsF[i] >= 'А') && (wordsF[i] <= 'Я')) || (wordsF[i] == 'Ё'))
            wordsF[i] = tolower(wordsF[i]);
    }

    return wordsF;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string words;
    In(words);

    std::cout << "\nYour words: \n" << ChangeWords(words) << std::endl;

    return 0;
}
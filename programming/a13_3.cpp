/*5.	Дана строка, состоящая из русских слов, разделенных пробелами (одним или несколькими) и знаками препинания. Найти длину самого короткого слова.*/

#include <iostream>
#include <string>
#include <windows.h>

void In(std::string& wordS) {
    std::cout << "Enter words: ";
    std::getline(std::cin, wordS);
}

int SearchMin(std::string& wordS) {
    int MinLen = 10000000;

    int Len = 0;

    int N = wordS.length();

    for (int i = 0; i < N + 1; i++) {
        if (isalpha(wordS[i]) || ((wordS[i] >= 'а') && (wordS[i] <= 'я')) || ((wordS[i] >= 'А') && (wordS[i] <= 'Я')) || (wordS[i] == 'Ё') || (wordS[i] == 'ё')) {
            Len += 1;
        }

        else {
            if ((Len <= MinLen) && (Len != 0)) {
                MinLen = Len;
            }
            Len = 0;
        }
    }

    if (MinLen == 10000000) {
        return 0;
    }

    else
        return MinLen;
}

void Out(int len, std::string& wordS) {
    std::cout << "MinLen = " << len << std::endl;

    int N = wordS.length();
    int LenNew = 0;

    for (int i = 0; i < N + 1; i++) {
        if (isalpha(wordS[i]) || ((wordS[i] >= 'а') && (wordS[i] <= 'я')) || ((wordS[i] >= 'А') && (wordS[i] <= 'Я')) || (wordS[i] == 'Ё') || (wordS[i] == 'ё')) {
            LenNew += 1;
        }

        else {
            if (LenNew == len) {
                for (int j = i - LenNew; j < i + 1; j++) {
                    std::cout << wordS[j];
                }
                std::cout << " ";
            }
            LenNew = 0;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string words;
    In(words);

    int Len = SearchMin(words);

    Out(Len, words);

    return 0;
}

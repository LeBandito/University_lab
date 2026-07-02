/*Алфавит племени «ням-ням» состоит из следующих символов: ч, н, а, щ, я, т.
Имеется массив слов этого племени.
Обеспечить сортировку массива в указанном алфавитном порядке.*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

void EnterData(std::vector<std::string>& vecStr) {
    std::cout << "Enter words:" << std::endl;

    std::string str;
    std::getline(std::cin, str);

    std::string tempStr;

    int j = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            j = i;

            for (j; (str[j] != ' ') && (j < str.size()); j++) {
                tempStr.push_back((str[j]));
            }

            vecStr.push_back(tempStr);

            tempStr = "";
            i = j;
        }
    }
}

int SearchLetter(char word) {
    char arr[6] = { 'h', 'n', 'a', 's', 'u', 't' };

    for (int i = 0; i < 6; i++) {
        if (word == arr[i]) {
            return i;
        }
    }

    return 0;
}

int SearchMin(std::string wordsF, std::string wordsS) {
    if (wordsF.size() >= wordsS.size())
        return wordsS.size();
    else
        return wordsF.size();
}

int WordsSort(std::string wordsF, std::string wordsS, int ss, int sMin) {
    if (ss < sMin) {
        if (SearchLetter(wordsF[ss]) == SearchLetter(wordsS[ss]))
            return WordsSort(wordsF, wordsS, ss + 1, sMin);

        else if (SearchLetter(wordsF[ss]) < SearchLetter(wordsS[ss]))
            return 2;

        else
            return 1;
    }

    else if (wordsF.size() < wordsS.size()) {
        return 2;
    }

    else if (wordsF.size() > wordsS.size()) {
        return 1;
    }

    else
        return 0;
}

void Absolutely(std::vector<std::string>& vecStr) {
    int n = vecStr.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            std::string vrem;
            if (WordsSort(vecStr[j], vecStr[j + 1], 0, SearchMin(vecStr[j], vecStr[j + 1])) == 1) {
                vrem = vecStr[j];
                vecStr[j] = vecStr[j + 1];
                vecStr[j + 1] = vrem;
            }
        }
    }
}

int main() {
    std::vector<std::string> vecStr;

    EnterData(vecStr);

    std::cout << std::endl;

    int N = vecStr.size();

    for (int i = 0; i < N; i++) {
        std::cout << i + 1 << ": " << vecStr[i] << std::endl;
    }
    
    std::cout << "\nAfter sort:\n" << std::endl;

    Absolutely(vecStr);

    for (int i = 0; i < N; i++) {
        std::cout << i + 1 << ": " << vecStr[i] << std::endl;
    }

    return 0;
}

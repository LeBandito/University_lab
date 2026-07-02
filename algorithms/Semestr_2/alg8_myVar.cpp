/*Алфавит племени «ням-ням» состоит из следующих символов: h, n, a, s, y, t. 
Имеется массив слов этого племени. Обеспечить сортировку массива в указанном алфавитном порядке*/
#include <iostream>
#include <vector>
#include <string>

void InData(std::vector<std::string>& Words) {
    std::string word;
    std::cout << "Enter the words: " << std::endl;
    std::getline(std::cin, word);

    std::string temporary;
    
    for (int i = 0; i < word.size(); i++) {
        if (word[i] != ' ') {
            temporary.push_back(word[i]);
        }

        else {
            Words.push_back(temporary);
            temporary.clear();
        }
    }

    if (!temporary.empty()) {
        Words.push_back(temporary);
    }
    
    temporary.clear();
    
}

int CheckLen(std::string A, std::string B) {
    if (A.size() < B.size()) {
        return A.size();
    }

    else if (A.size() > B.size()) {
        return B.size();
    }
    
    return B.size();
}

int SearchLetter(char Letter) {
    char arr[6] = {'h', 'n', 'a', 's', 'y', 't'};

    for (int i = 0; i < 6; i++) {
        if (Letter == arr[i]) {
            return i;
        }
    }

    return 0;
}

int WordsSort(std::string wordA, std::string wordB) {
    for (int i = 0; i < CheckLen(wordA, wordB); i++) {
        if (SearchLetter(wordA[i]) > SearchLetter(wordB[i])) {
            return 1;
        }

        else if (SearchLetter(wordA[i]) < SearchLetter(wordB[i])) {
            return 0;
        }
    }

    if (wordA.size() > wordB.size()) {
        return 1;
    }

    else if (wordA.size() < wordB.size()) {
        return 0;
    }

    return 0;
}

void BubbleSort(std::vector<std::string>& Words) {
    for (int i = 0; i < Words.size(); i++) {
        for (int j = 0; j < Words.size() - i - 1; j++) {
            if (WordsSort(Words[j], Words[j + 1])) {
                std::string vrem = Words[j];
                Words[j] = Words[j + 1];
                Words[j + 1] = vrem;
            }
        }
    }
}

// ashn ash ahs hha hah

int main() {
    std::vector<std::string> words;
    InData(words);
    
    std::cout << "\nThe words: " << std::endl;

    for (int i = 0; i < words.size(); i++) {
        std::cout << words[i] << " ";
    }

    BubbleSort(words);

    std::cout << "\nAftr BubbleSort: " << std::endl;

    for (int i = 0; i < words.size(); i++) {
        std::cout << words[i] << " ";
    }

    return 0;
}
/*14.	Дана строка-предложение на русском языке. Вывести самое длинное слово в предложении. Если таких слов несколько, то вывести первое из них. 
Словом считать набор символов, не содержащий пробелов, знаков препинания и ограниченный пробе-лами, знаками препинания или началом/концом строки.*/
#include <iostream>
#include <string>

void In(std::string& wordS){
    std::getline(std::cin, wordS);
    std::cout << wordS << std::endl;
}

void Out(std::string& wordS, int firstmax, int lenmax){
    for (int i = firstmax; i <= firstmax + lenmax; i++){
        std::cout << wordS[i] << "";
    }
}

int SearchMax(std::string& wordS, int& LenMax){
    int N = wordS.length();
    int check = 0;
    int iFirst;

    for (int i = 0; i < N + 1; i++){
        if (isalpha(wordS[i]))
            check += 1;

        else {
            if (check >= LenMax)
                LenMax = check;

            check = 0;
        }
    }
    
    for (int i = 0; i < N + 1; i++){
        if (isalpha(wordS[i]))
            check += 1;

        else {
            if (check == LenMax)
                iFirst = i - check;

            check = 0;
        }
    }

    return iFirst;
}

int main(){
    std::cout << "Enter words: ";
    std::string words;
    int lenMax = 0;
    In(words);

    int firstMax = SearchMax(words, lenMax);

    Out(words, firstMax, lenMax);

    std::cout << "\n" << lenMax;

    return 0;
}
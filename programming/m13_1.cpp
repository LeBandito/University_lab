/*Дано целое число N (> 0) и строка S. Преобразовать строку S в строку дли-ны N следующим образом: 
если длина строки S больше N, то отбросить первые симво-лы, если длина строки S меньше N, то в ее начало добавить символы «.» (точка).*/
#include <iostream>
#include <string>
#include <cstring>

void In(int& N, std::string& S) {
    std::cout << "Enter N (> 0): ";
    std::cin >> N;
    
    std::cout << "Enter the words:" << std::endl;
    std::getline(std::cin, S);
}

std::string BRUH(int N, std::string S) {
    std::string S1;

    for (int i = N; i < S.size(); i++) {
        S1.push_back(S[i]);
    }
    
    return S1;
}

void ChangeWords(int N, std::string& S) {
    if (N > S.size()) {
        std::string S1(S.size() - N, '.');
        S = S1 + S;
    }

    else if (N < S.size()) {
        S = BRUH(N, S);
    }
}

void Out(std::string S) {
    std::cout << "S is " << std::endl;
    for (int i = 0; i < S.size(); i++) {
        std::cout << S[i];
    }
}

int main() {
    int N;
    std::string S;
    In(N, S);

    ChangeWords(N, S);

    Out(S);

    return 0;
}
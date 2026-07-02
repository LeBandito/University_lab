/*5.	Дан символ C и строки S, S0. После каждого вхождения символа C в строку S вставить строку S0.*/


#include <iostream>
#include <string>
#include <windows.h>

void In(char& a, std::string& A, std::string& A0) {
    std::cout << "Enter the symbol: ";
    std::cin >> a;

    std::cin.ignore();

    std::cout << "Enter S: ";
    std::getline(std::cin, A);

    std::cout << "Enter S0: ";
    std::getline(std::cin, A0);
}

std::string ChangeWords(char& a, std::string& A, std::string& A0) {
    int N = A.length();

    for (int i = 0; i < N; i++) {
        if (A[i] == a) {
            A.insert(i + 1, A0);
            i += A0.length();
            N += A0.length();
        }
    }

    return A;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char C;
    std::string S, S0;

    In(C, S, S0);

    std::cout << "The new S: " << ChangeWords(C, S, S0) << std::endl;

    return 0;
}
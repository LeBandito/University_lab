/*Задано N товаров (примерный перечень: Молоко, Сметана, Творог, Кефир, Сыр, Йогурт, Ряженка, Хлеб черный, Хлеб белый, Мясо, Колбаса, Рыба, 
Курица, Индейка, Конфеты, Печенье, Шоколад, Мармелад, Зефир, Овощи, Фрукты, Алкоголь, Табак) и массив покупок (размерности M). 
В одной покупке может быть несколько товаров из списка. Произвести разделение товаров на группы, в которые включены товары, наиболее часто покупаемые совместно.*/

#include <iostream>
#include <string>
#include <windows.h>

void InMN(int& m, int & n){
    std::cout << "Enter M, N: ";
    std::cin >> m >> n;
}

void madeStart(int** buy, int** mainBuy, int m, int n);
void madeFinish(int** buy, int** mainBuy, int m);

int main() {
    SetConsoleOutputCP(65001);
    
    int M, N;
    InMN(M, N);

    int** buy = new int* [M];
    int** mainBuy = new int* [M];
    int bruh[23];

    for (int i = 0; i < 23; i++){
        bruh[i] = 0;
    }

    madeStart(buy, mainBuy, M, N);

    for (int i = 0; i < M; i++){
        for (int j = 0; j < 23; j++){
            mainBuy[i][j] = 0;
        }
    }

    std::cout << "Enter your goods:" << std::endl;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            std::cin >> buy[i][j];
        }
    }

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            mainBuy[i][buy[i][j]] = mainBuy[i][buy[i][j]] + 1;
        }
    }

    std::cout << "Your goods:" << std::endl;

    for (int i = 0; i < M; i++){
        std::cout << "Buy " << i + 1  << ":"<< std::endl;
        for (int j = 0; j < N; j++){
            std::cout << buy[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Check:" << std::endl;

    for (int i = 1; i < M; i++){
        std::cout << "Buy " << i + 1  << ":"<< std::endl;
        for (int j = 0; j < 23; j++){
            std::cout << mainBuy[i][j] << " ";
        }
        std::cout << std::endl;
    }

    madeFinish(buy, mainBuy, M);

    return 0;
}



void madeStart(int** buy, int** mainBuy, int m, int n){
    for (int i = 0; i < m; i++){
        buy[i] = new int[n];
    }

    for (int i = 0; i < m; i++){
        mainBuy[i] = new int[23];
    }
}

void madeFinish(int** buy, int** mainBuy, int m){
    for (int i = 0; i < m; i++) {
        delete[](buy[i]);
    }

    for (int i = 0; i < m; i++) {
        delete[](mainBuy[i]);
    }

    delete[] buy;
    delete[] mainBuy;
}
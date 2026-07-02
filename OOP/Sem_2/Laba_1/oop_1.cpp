/*Использование функций-шаблонов: для работы с двумерными массивами арифметических типов 
данных разработать шаблоны ввода и вывода массива, а также шаблон для решения основной задачи.
5.	Заменить все положительные элементы противоположными им числами.*/

#include <iostream>
#include <string>
#include <vector>

template <typename X> 
void AddNumbers(std::vector<std::vector<X>>& mas, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << "\nInput matrix[" << i << "][" << j << "]: "; 
            std::cin >> mas[i][j];
        }
    }
    
    std::cout << std::endl;
}

template <typename X> 
void ShowNumbers(std::vector<std::vector<X>>& mas, int n, int m) {
    for (int i = 0; i < n; ++i) {
        std::cout << "|";
        
        for (int j = 0; j < m - 1; ++j) {
            std::cout << mas[i][j] << ", ";
        }
        
        std::cout << mas[i][m - 1];
        
        std::cout << "|" << std::endl;
    }
}

template <typename X> 
void reverseNumbers(std::vector<std::vector<X>>& mas, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mas[i][j] > 0) 
                mas[i][j] = mas[i][j] * (-1);
        }
    }
    
    std::cout << "BomBomBom!!!\n";
}

/* 
3 7
1 2 3 4 5 -3 -8 5 8 23 10000 -55 -66 -99 -1 -2 -3 -4 -5 3 8
2.03 3.333 -7.99 10.25 -1.111 -5.555 1 2 3 4 5 -3 -8 5 8 23 1 2 3 4 -6.66
*/

int main() {
    setlocale(LC_ALL, "");
    
    int n, m;
    std::wcout << L"Введите кол-во строк а затем столбцов, через пробел:";
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> masI(n, std::vector<int>(m));
    
    AddNumbers(masI, n, m);
    ShowNumbers(masI, n, m);
    reverseNumbers(masI, n, m);
    ShowNumbers(masI, n, m);
    
    std::vector<std::vector<double>> masD(n, std::vector<double>(m));
    
    AddNumbers(masD, n, m);
    ShowNumbers(masD, n, m);
    reverseNumbers(masD, n, m);
    ShowNumbers(masD, n, m);
    
    return 0;
}
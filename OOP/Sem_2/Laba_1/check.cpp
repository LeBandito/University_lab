/*Использование функций-шаблонов: для работы с двумерными массивами арифметических типов 
данных разработать шаблоны ввода и вывода массива, а также шаблон для решения основной задачи.
5.	Заменить все положительные элементы противоположными им числами.*/

#include <iostream>
#include <string>
#include <vector>

template <typename X> 
void AddNumbers(std::vector<std::vector<X>>& mas, int n, int m, int& sz) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "\nInput matrix[" << i << "][" << j << "]: ";
            std::cin >> mas[i][j];
            
            if (sz <= int(std::to_string(mas[i][j]).size()))
                sz = int(std::to_string(mas[i][j]).size());
        }
    }
    
    std::cout << std::endl;
}

template <typename X> 
void ShowNumbers(std::vector<std::vector<X>>& mas, int n, int m, int sz) {
    for (int i = 0; i < m; ++i) {
        std::cout << "|";
        
        std::cout << std::string(sz + 2 - int(std::to_string(mas[i][0]).size()), ' ');
        
        for (int j = 0; j < n - 1; ++j) {
            std::cout << mas[i][j] << ", ";
            
            std::cout << std::string(sz + 2 - int(std::to_string(mas[i][j]).size()), ' ');
        }
        
        std::cout << mas[i][n - 1];
        
        std::cout << "|" << std::endl;
    }
}

template <typename X> 
void reverseNumbers(std::vector<std::vector<X>>& mas, int n, int m) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mas[i][j] > 0) 
                mas[i][j] = mas[i][j] * (-1);
        }
    }
    
    std::cout << "BomBomBom!!!\n";
}

/* 
7 3
1 2 3 4 5 -3 -8 5 8 23 10000 -55 -66 -99 -1 -2 -3 -4 -5 3 8
*/

int main() {
    setlocale(LC_ALL, "");
    
    int n, m;
    std::wcout << L"Введите кол-во строк а затем столбцов, через пробел:";
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> mas(m, std::vector<int>(n));
    
    int sz = 0;
    
    AddNumbers(mas, n, m, sz);
    ShowNumbers(mas, n, m, sz);
    reverseNumbers(mas, n, m);
    ShowNumbers(mas, n, m, sz);
    
    return 0;
}
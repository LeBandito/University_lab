/*5.	Имеется массив размерностью N, элементами которого являются целые числа 
из диапазона 1..M (N>M). 
Составить программу линейной сложности для сортировки данного массива.*/

#include <iostream>

void InNumbers(int* mas, int n, int m){
    for (int i = 0; i < n; i++){
        mas[i] = 1 + rand() % m;
        std::cout << mas[i] << " ";
    }
}

int* CountingSort(int* mas, int n, int m){
    int* C = new int[m];
    for (int i = 0; i < m; i++){
        C[i] = 0;
    }

    for (int i = 0; i < n; i++){
        C[mas[i]] = C[mas[i]] + 1;
    }

    int b = 0;

    for (int j = 0; j < m; j++){
        for (int i = 0; i < C[j]; i++){
            mas[b] = j;
            b = b + 1;
        }
    }

    return mas;
}
    
int main(){
    int N;
    std::cout << "Enter N: ";
    std::cin >> N;

    int M;
    std::cout << "Enter M: ";
    std::cin >> M;

    int* arr = new int[N];
    InNumbers(arr, N, M);

    std::cout << "\n" << "CountingSort: " << std::endl;
    int* my = CountingSort(arr, N, M);

    for (int i = 0; i < N; i++){
        std::cout << my[i] << " ";
    }

    delete[] arr;

    return 0;
}
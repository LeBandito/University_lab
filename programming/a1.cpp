#include <iostream>

int Summ(int** mas, int m, int n){
    int sm = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            sm += mas[i][j];
        }
    }
    return sm;
}

int main(){
    int m, n;
    std::cout << "Enter m, n: ";
    std::cin >> m >> n;

    int **arr = new int* [m];

    for(int i = 0; i < m; i++){
        arr[i] = new int [n];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cout << "Enter arr[" << i << "][" << j << "]: ";
            std::cin >> arr[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "The summ = " << Summ(arr, m, n) << std::endl;

    for(int i = 0; i < m; i++){
        delete [] (arr[i]);
    }

    delete [] arr;

    return 0;
}
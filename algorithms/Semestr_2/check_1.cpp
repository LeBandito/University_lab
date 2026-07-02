#include <iostream>

void In(int n, int* Arr) {
    std::cout << "Enter arr: " << std::endl;

    for (int i = 0; i < n; i++) {
        std::cin >> Arr[i];
    }
}

int Min(int a, int b) {
    if (a >= b) {
        return b;
    }

    if (b >= a) {
        return a;
    }

    return 0;
}

int* FindPuddles(int n, int* Arr) {
    int* ArrM = new int[n]();
    int vrem = 0;

    for (int j = vrem + 1; j < n; j++) {
        if (Arr[j] < Arr[vrem]) {
            ArrM[vrem] = Arr[vrem];                
        }

        else {
            ArrM[vrem] = Arr[vrem]; 
            vrem = j;
        }
    }
    
    std::cout << "Var First: ";

    for (int i = 0; i < n; i++) {
        std::cout << ArrM[i] << " ";
    }

    int VremBack = n - 1;

    for (int j = VremBack - 1; j > 0; j--) {
        if (Arr[j] < Arr[VremBack]) {
            ArrM[VremBack] = Arr[VremBack];
        }

        else {
            ArrM[VremBack] = Arr[VremBack];
            VremBack = j;
        }
    }

    std::cout << "\nVar Second: ";
    
    for (int i = 0; i < n; i++) {
        std::cout << ArrM[i] << " ";
    }

    return ArrM;
    delete[] ArrM;
}

int FindSquare(int n, int* Arr, int* ArrM) {
    int Square = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ArrM[i] != 0) && (ArrM[j] != 0)) {
                std::cout << "\nbruh: ";
                
                for (int k = i + 1; k < j; k++) {
                    std::cout << Arr[k] << " ";
                    Square += (Min(ArrM[i], ArrM[j]) - Arr[k]);
                }

                i = j;
            }
        }
    }

    return Square;    
}

// N = 14
// arr = { 2 5 1 2 3 4 7 7 6 1 3 9 4 3 }

int main() {
    int N;
    std::cout << "Enter N: " << std::endl;
    std::cin >> N;

    int* arr = new int[N];

    In(N, arr);

    int* arrM = FindPuddles(N, arr);

    int square = FindSquare(N, arr, arrM);

    std::cout << "\nThe square is: " << square << std::endl;

    delete[] arr;
    delete[] arrM;
    return 0;
}
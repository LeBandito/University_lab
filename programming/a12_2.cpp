#include <iostream>
#include <math.h>

void InArr(double** mas, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //std::cout << "Enter arr[" << i << "][" << j << "] = ";
            //std::cin >> mas[i][j];
            mas[i][j] = -10 + rand() % 21;
        }
    }
}

void OutArr(double** mas, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << mas[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

double multi(double* mas, int n) {
    double m = 1;
    double k = 0;

    for (int i = 0; i < n; i++) {
        if (mas[i] > 0) {
            m *= mas[i];
            if (mas[i] == 1)
                k += 1;
        }
    }
    if ((m == 1) && (k == 0))
        return 0;
    else
        return m;
}

double* AverageGeometric(double** mas, int n, int m) {
    double* bobr = new double[m];

    for (int i = 0; i < m; i++) {
        double* check = new double[n];
        for (int j = 0; j < n; j++) {
            check[j] = mas[j][i];
        }
        bobr[i] = pow(multi(check, n), 1 / double(n));
    }

    return bobr;
}

int main() {
    int n, m;
    std::cout << "Enter n, m: ";
    std::cin >> n >> m;

    double** arr = new double* [n];

    for (int i = 0; i < n; i++) {
        arr[i] = new double[m];
    }

    InArr(arr, n, m);
    OutArr(arr, n, m);

    std::cout << "AverageGeometric(arr, n, m): " << std::endl;
    double* my = AverageGeometric(arr, n, m);

    for (int i = 0; i < m; i++) {
        std::cout << my[i] << " ";
    }

    delete[] my;

    for (int i = 0; i < n; i++) {
        delete[](arr[i]);
    }

    delete[] arr;

    return 0;
}

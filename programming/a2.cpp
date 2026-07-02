#include <iostream>

double Max(double* mas, int N){
    double maxx = -100000000000;

    for(int i = 0; i < N; i++){
        if (maxx <= mas[i])
            maxx = mas[i];
    }

    return maxx;
}

double Arithmetic(double* mas, int N){
    double summ = 0;
    int k = 0;

    for(int i = 0; i < N; i++){
        if (mas[i] < 0){
            summ += mas[i];
            k += 1;
        }
    }

    if ((summ == 0) || (k == 0)){
        return 0;
    }
    else {
        double sr = summ / k;
        return sr;
    }
}

int main(){
    int N;
    std::cout << "Enter N: ";
    std::cin >> N;

    double* arr = new double[N];

    for(int i = 0; i < N; i++){
        std::cout << "Enter arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << std::endl;

    for(int i = 0; i < N; i++){
        std::cout << arr[i] << " ";
    }

    std::cout << "The maximum: " << Max(arr, N) << std::endl;

    if (Arithmetic(arr, N) == 0)
        std::cout << "the number of negative elements is 0";
    
    else
        std::cout << "\n" << "The arithmetic mean of negative elements: " << Arithmetic(arr, N) << std::endl;

    delete[] arr;

    return 0;
}
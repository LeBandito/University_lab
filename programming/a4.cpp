#include <iostream>

void InNumber(double& number){
    std::cout << "The number = ";
    std::cin >> number;
}

void InRoot(int& rootDegree){
    std::cout << "The root = ";
    std::cin >> rootDegree;
}

double mabs(double x){
    if (x < 0) 
        return -x;
    else
        return x; 
}

double RootExtraction(double number, int rootDegree){
    double eps = 0.00001;
    double root = number / rootDegree;
    double rn = number;
    int countiter = 0;

    while(mabs(root - rn) >= eps){
        rn = number;
        for(int i = 1; i < rootDegree; i++){
            rn = rn / root;
        }
        root = 0.5 * ( rn + root);
        countiter++;
    }
    return root;
}
 
int main(void) {
    double number;
    int rootDegree;
    
    InNumber(number);
    InRoot(rootDegree);

    std::cout << "root is " << RootExtraction(number, rootDegree);

    return 0;
}
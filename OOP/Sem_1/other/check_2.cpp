/* Вариант №5
Функция f(x): 
    ln(1 - x), x ∈ [-1; 3], Δx = 0,2
    
Способ формирования массива c: 
    c(i) = a(i + 1) - 1 / b(i - 1)
Для каждого варианта необходимо создать три массива а, b и с размерами 
соответственно nl, n2 и n3 (nl != n2 != n3). В массив а занести значения
функции f(x) согласно варианту (при возникновении исключения заносить
нули). Массив b заполнить случайными числами (среди них должны быть и
отрицательные числа и нули). Массив с формируется согласно варианту.
Предусмотреть и обработать возникающие при этом исключительные ситуации 
(деление на ноль, корень из отрицательного числа, арифметическое 
переполнение, выход за пределы диапазона индексов массива и т.п.).*/

#include <iostream>
#include <vector>
#include <random>
#include <cmath>

class ZeroDivideException {
    public:
        int idx;
        ZeroDivideException (int i) 
        {
            idx = i;            
        }
};

class logOfNegative {
    public:
        int idx;
        logOfNegative (int i) 
        {
            idx = i;            
        }    
};

// n1 = 20
void F(std::vector<double>& a) {
    for (double i = -1; i <= 3; i += 0.2) {
        a.push_back(log(1 - i) / log(exp(1)));
        std::cout << a[i] << " ";
    }
}

// n2 = 30
void Random(std::vector<double>& b) {
    for (int i = 0; i < 30; i++) {
        b.push_back((std::rand() % 30) - 15);
        std::cout << b[i] << " ";
    }
}

// n3 = 20
void BomBomBom(std::vector<double>& a, std::vector<double>& b, std::vector<double>& c) {
    for (int i = 1; i < 21; i++) {
        c.push_back(a[i + 1] - (1 / b[i - 1]));
        std::cout << c[i] << " ";
    }
}

// std::rand() % 100

int main() {
    setlocale(LC_ALL, "");
    std::vector<double> a, b, c;
    std::wcout << L"Массив a: " << std::endl;
    F(a);
    
    std::wcout << L"\nМассив b: " << std::endl;
    Random(b);
    
    std::wcout << L"\nМассив c: " << std::endl;
    BomBomBom(a, b, c);
    
    return 0;
}


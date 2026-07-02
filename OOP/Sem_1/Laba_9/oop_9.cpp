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
        ZeroDivideException (int i) {
            idx = i;
        }
};

class LogOfNegativeException {
    public:
        int idx;
        LogOfNegativeException (int i) {
            idx = i;
        }
};

class IndexException {
    public:
        int idx;
        IndexException(int i) {
            idx = i;
        }
};

// n1 = 21
void F(std::vector<double>& a) {
    int index = 0;
    for (double x = -1.0; x <= 3.0; x += 0.2, index++) {
        try {
            if (1 - x <= 0) {
                a.push_back(0.0);
                throw LogOfNegativeException(index);
            }
            double value = log(1 - x);
            a.push_back(value);
            std::cout << value << " ";
        } catch (LogOfNegativeException ex) {
            std::cout << "Log error at x=" << x << " index=" << ex.idx << std::endl;
        }
    }
}

// n2 = 30
void Random(std::vector<double>& b) {
    for (int i = 0; i < 30; i++) {
        int random_num = (std::rand() % 30) - 15;
        b.push_back(random_num);
        std::cout << random_num << " ";
    }
}

// n3 = 20
void BomBomBom(std::vector<double>& a, std::vector<double>& b, std::vector<double>& c) {
    for (int i = 0; i < 20; i++) {
        try {
            // граница
            if (i + 1 >= a.size()) {
                throw IndexException(i);
            }
            if (i - 1 < 0 || i - 1 >= b.size()) {
                throw IndexException(i);
            }
            
            // ноль
            if (b[i - 1] == 0) {
                c.push_back(0.0);
                throw ZeroDivideException(i);
            }
            
            //c(i) = a(i + 1) - 1 / b(i - 1)
            double value = a[i + 1] - (1.0 / b[i - 1]);
            c.push_back(value);
            std::cout << value << " ";
            
        } catch (ZeroDivideException ex) {
            std::cout << "Zero divide error in index" << ex.idx << std::endl;
        } catch (IndexException ex) {
            std::cout << "Index error at " << ex.idx << std::endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    
    std::vector<double> a, b, c;
    
    std::wcout << L"Массив a: " << std::endl;
    F(a);
    
    std::wcout << L"\nМассив b: " << std::endl;
    Random(b);
    
    std::wcout << L"\n\nМассив c: " << std::endl;
    BomBomBom(a, b, c);
    
    std::wcout << L"\nРазмеры массивов: ";
    std::wcout << L"a=" << a.size() << L", b=" << b.size() << L", c=" << c.size() << std::endl;
    
    return 0;
}

/*5. Создать абстрактный базовый класс прогрессия с виртуальной функцией – вычисление суммы прогрессии. 
Создать производные классы: арифметическая прогрессия и геометрическая прогрессия. 
Каждый класс имеет два поля типа double: 
    первый член прогрессии 
    и постоянная разность (для арифметической) 
    и постоянное отношение (для геометрической). 
Определить функцию вычисления суммы, где параметром является количество элементов прогрессии.*/

#include <iostream>
#include <cmath>

class progression {
    public:
        virtual int getsum(int n) const = 0;
        virtual ~progression() = default;    
};

// An = A1 + (n - 1) * D
// Sn = n/2 * (2*A1 + (n-1)*D)

class arithmetic : public progression {
    private:
        int A1;
        int D;
    
    public:
        arithmetic(): A1(), D()
        {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}
        
        arithmetic(int newA1, int newD): A1(newA1), D(newD)
        {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}
        
        arithmetic(const arithmetic& other): A1(other.A1), D(other.D)
        {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
        
        int getA1() const {return A1;}
        int getD() const {return D;} 
        
        int getsum(int n) const override {
            if (n <= 0) 
                return 0;
                
            return (n * (2 * A1 + (n - 1) * D)) / 2;
        }
        
        void ShowData(int n) {
            std::wcout << L"Арифметическая прогрессия: " << getsum(n) << std::endl;
        }
};

// Bn = B1 * q ^ (n - 1)
// Sn = B1 * (1 - q^n) / (1 - q)

class geometric : public progression {
    private:
        int B1;
        int q;
    
    public:
        geometric(): B1(), q()
        {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}
        
        geometric(int newB1, int newQ): B1(newB1), q(newQ)
        {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}
        
        geometric(const geometric& other): B1(other.B1), q(other.q)
        {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
        
        int getB1() const {return B1;}
        int getQ() const {return q;}
        
        int getsum(int n) const override {
            if (n <= 0) 
                return 0;
            
            if (q == 1) 
                return B1 * n;
            
            return B1 * (1 - pow(q, n)) / (1 - q);
        }
        
        void ShowData(int n) {
            std::wcout << L"Геометрическая прогрессия: " << getsum(n) << std::endl;
        }
};

int main() {
    setlocale(LC_ALL, "");
    arithmetic bom_arith(1, 2);
    bom_arith.ShowData(6);
    
    geometric bom_geom(1, 2);
    bom_geom.ShowData(6);
    
    return 0;
}
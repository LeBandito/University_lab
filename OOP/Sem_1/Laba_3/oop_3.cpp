/*Класс:
Треугольник
Свойства: сторона и два прилежащих к ней угла
Операции:
уменьшение увеличение размера стороны (из свойств) в
заданное количество раз;
вычисление длины медианы, принадлежашей любой стороне;
определение подобен ли другой треугольник данному (этого
же класса);
определение значений сторон.*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class triangle {
    private:
        float a;
        float a_B;
        float a_C;
        float b;
        float c;
        
    public:
        triangle() : a(), a_B(), a_C(), b(), c()
        {
            std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;
        }
        
        triangle(float A, float A_B, float A_C) : a(A), a_B(A_B), a_C(A_C)
        {
            b = A * ((sin(M_PI * (A_C / 180))) / (sin(M_PI * ((180 - A_B - A_C) / 180))));
            c = A * ((sin(M_PI * (A_B / 180))) / (sin(M_PI * ((180 - A_B - A_C) / 180))));
            std::wcout << L"Вызван конструктор с параметрами!" << std::endl;
        }

        triangle(const triangle& other) : 
        a(other.a), a_B(other.a_B), a_C(other.a_C), b(other.b), c(other.c)
        {
            std::wcout << L"Вызван конструктор копирования!" << std::endl;
        }

        bool set_a(float new_a) {
            if (new_a <= 0) {
                std::wcout << L"Неправильно!" << std::endl;
                return false;
            }
            
            a = 1.0 * a * new_a;
            
            std::wcout << L"Меняем сторону A: " << a << std::endl;
            
            return true;            
        }
        
        bool set_a_B(float new_a_B) {
            if ((new_a_B <= 0) || (new_a_B >= 180)) {
                std::wcout << L"Неправильно!" << std::endl;
                return false;
            }
        
            a_B = new_a_B;
            
            std::wcout << L"Меняем угол a_B: " << a_B << std::endl;
            
            return true;            
        }
        
        bool set_a_C(float new_a_C) {
            if ((new_a_C <= 0) || (new_a_C >= 180)) {
                std::wcout << L"Неправильно!" << std::endl;
                return false;
            }
        
            a_C = new_a_C;
            
            std::wcout << L"Меняем угол a_B: " << a_C << std::endl;
            
            return true;            
        }
        
        float get_a() const {return a;}
        float get_a_B() const {return a_B;}
        float get_a_C() const {return a_C;}
        float get_b() const {return b;}
        float get_c() const {return c;}

        void ma();
        void mb();
        void mc();
        
        bool isValid() const {
            if (a_B + a_C >= 180) {
                std::wcout << L"Нельзя!" << std::endl;
                return false;
            }
            
            if ((a + b <= c) || (a + c <= b) || (c + b <= a)) {
                std::wcout << L"Нельзя!" << std::endl;
                return false;
            }
            
            if ((a <= 0) || (b <= 0) || (c <= 0)) {
                std::wcout << L"Нельзя!" << std::endl;
                return false;
            }
            
            if ((a_B <= 0) || (a_C <= 0)) {
                std::wcout << L"Нельзя!" << std::endl;
                return false;
            }
            
            return true;
        }

        void show_data();
        
        bool is_similar(triangle& other) {
            float eps = 1e-6;
            float ratio_a = a / other.a;
            float ratio_b = b / other.b;
            float ratio_c = c / other.c;

            return !((fabs(ratio_a - ratio_b) >= eps) || (fabs(ratio_b - ratio_c) >= eps) || (fabs(ratio_a - ratio_c) >= eps));
        }
        
        void check(bool BomBom);
        
        ~triangle() {
            std::wcout << L"Удаляем!" << std::endl;
        }
};

void triangle::ma() {
    float ma = (0.5) * pow(2 * c * c + 2 * b * b - a * a, 0.5);
    std::wcout << L"Медиана A равна: " << ma << std::endl;
}

void triangle::mb() {
    float mb = (0.5) * pow(2 * c * c + 2 * a * a - b * b, 0.5);
    std::wcout << L"Медиана B равна: " << mb << std::endl;
}

void triangle::mc() {
    float mc = (0.5) * pow(2 * a * a + 2 * b * b - c * c, 0.5);
    std::wcout << L"Медиана C равна: " << mc << std::endl;
}

void triangle::show_data() {
    std::wcout << L" --------- " << std::endl;
    std::wcout << L"Сторона A: " << get_a() << std::endl;
    std::wcout << L"Сторона B: " << get_b() << std::endl;
    std::wcout << L"Сторона C: " << get_c() << std::endl;
    std::wcout << L"Угол <AB: " << acos((a * a + b * b - c * c) / (2 * a * b)) << std::endl;
    std::wcout << L"Угол <AC: " << acos((a * a + c * c - b * b) / (2 * a * c)) << std::endl;
    std::wcout << L" --------- " << std::endl;
};

void triangle::check(bool BomBom) {
    std::wcout << L" --------- " << std::endl;
    
    if (BomBom)
        std::wcout << L"Подобны!" << std::endl;

    else
        std::wcout << L"Не подобны!" << std::endl;
    
    std::wcout << L" --------- " << std::endl;
};

// 8 30 40 0.5

int main() {
    setlocale(LC_ALL, "");
    float a, a_B, a_C, newA;
    std::wcout << L"Enter a, <ab, <ac: " << std::endl;
    std::cin >> a >> a_B >> a_C;

    triangle triaG_1(1.0 * a, 1.0 * a_B, 1.0 * a_C);
    
    if (triaG_1.isValid())
        std::wcout << L"Корректно" << std::endl;
        
    triaG_1.show_data();
    triaG_1.ma();
    triaG_1.mb();
    triaG_1.mc();

    std::cout << "Enter newA: " << std::endl;
    std::cin >> newA;

    triangle copyTriaG_1(triaG_1);
    copyTriaG_1.set_a(1.0 * newA);
    if (copyTriaG_1.isValid())
        std::wcout << L"Корректно" << std::endl;
        
    copyTriaG_1.show_data();
    copyTriaG_1.ma();
    copyTriaG_1.mb();
    copyTriaG_1.mc();

    triaG_1.check(triaG_1.is_similar(copyTriaG_1));

    return 0;
}
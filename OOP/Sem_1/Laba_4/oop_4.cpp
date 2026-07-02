/* Вариант 5
Класс: Прямая
Члены класса: Координаты двух точек (xl,yl) и (x2,у2)
Методы: Конструктор, деструктор, метод вывода уравнения прямой
Операторы перегрузки: Проверка параллельности 2" прямых (), определение угла между 2-мя прямыми (%)
Исходные данные: 
    Прямая АВ: A(xa,ya), B(xb,yb)
    Прямая CD: C(xc,ye), D(xd,yd)
Результаты:
    Вывести уравнения прямых линий. 
    Если прямые не параллельны, 
    то найти и вывести угол между ними
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class straight {
    private:
        float aX, aY;
        float bX, bY;
        
    public:
        straight(): aX(), aY(), bX(), bY()
        {
            std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;
        }
        
        straight(float a_X, float a_Y, float b_X, float b_Y): 
        aX(a_X), aY(a_Y), bX(b_X), bY(b_Y)
        {
            std::wcout << L"Вызван конструктор с параметрами!" << std::endl;
        }
        
        straight(const straight& other): aX(other.aX), aY(other.aY), bX(other.bX), bY(other.bY)
        {
            std::wcout << L"Вызван конструктор копирования!" << std::endl;
        }
        
        void setAB(float new_aX, float new_aY, float new_bX, float new_bY) {
            aX = new_aX;
            aY = new_aY;
            bX = new_bX;
            bY = new_bY;
        }
        
        // void set_aX(int new_aX) {aX = new_aX;}
        // void set_aY(int new_aY) {aY = new_aY;}
        // void set_bX(int new_bX) {bX = new_bX;}
        // void set_bY(int new_bY) {bY = new_bY;}
        
        int get_aX() const {return aX;}
        int get_aY() const {return aY;}
        int get_bX() const {return bX;}
        int get_bY() const {return bY;}
        
        void ShowData();
        
        void TheStraight();
        
        bool operator||(const straight& other);
        float operator<(const straight& other);
        
        ~straight() {
            std::wcout << L"Удаляем!" << std::endl;
        }
};

void straight::ShowData() {
    std::wcout << L"X1: " << get_aX() << std::endl;
    std::wcout << L"Y1: " << get_aY() << std::endl;
    std::wcout << L"X2: " << get_bX() << std::endl;
    std::wcout << L"Y2: " << get_bY() << std::endl;
}

void straight::TheStraight() {
    float bruhX = aY - bY;
    float bruhY = bX - aX;
    float bruhXY = aX * bY - bX * aY;
    std::wcout << L"Уравнение прямой: " << bruhX  << "x " << bruhY << "y " << bruhXY << std::endl;
    std::wcout << L"Уравнение прямой: ";

    if (bruhX > 0)
        std::wcout << L"+" << bruhX << "x ";
    else if (bruhX < 0)
        std::wcout << bruhX << "x ";
    
    if (bruhY > 0)
        std::wcout << L"+" << bruhY << "y ";
    else if (bruhY < 0)
        std::wcout << bruhY << "y ";
        
    if (bruhXY > 0)
        std::wcout << L"+" << bruhXY;
    else if (bruhXY < 0)
        std::wcout << bruhXY;
    
    std::wcout << std::endl;
}

bool straight::operator||(const straight& other) {
    float AB_CD = 1.0 * (bX - aX) * (other.bX - other.aX) + 
        1.0 * (bY - aY) * (other.bY - other.aY);
    float _AB_ = 1.0 * pow(pow(bX - aX, 2) + pow(bY - aY, 2), 0.5);
    float _CD_ = 1.0 * pow(pow(other.bX - other.aX, 2) 
        + pow(other.bY - other.aY, 2), 0.5);
    float final = acos(1.0 * AB_CD / (_AB_ * _CD_)) * 180 / M_PI;
    
    // float bruh = acos(((bX - aX) * (other.bX - other.aX) + (bY - aY) * (other.bY - other.aY)) / 
    // (pow(pow(bX - aX, 2) + pow(bY - aY, 2), 0.5) * 
    // pow(pow(other.bX - other.aX, 2) + pow(other.bY - other.aY, 2), 0.5)));
    
    if ((int(final) == 180) || (int(final) == 0))
        return true;
        
    return false;
}

float straight::operator<(const straight& other) {
    float AB_CD = 1.0 * (bX - aX) * (other.bX - other.aX) + 
        1.0 * (bY - aY) * (other.bY - other.aY);
    float _AB_ = 1.0 * pow(pow(bX - aX, 2) + pow(bY - aY, 2), 0.5);
    float _CD_ = 1.0 * pow(pow(other.bX - other.aX, 2) 
        + pow(other.bY - other.aY, 2), 0.5);
    float final = acos(1.0 * AB_CD / (_AB_ * _CD_)) * 180 / M_PI;
    
    if (final > 90)
        return 180 - final;
        
    return final;
}

// Для 90 -- 2 2 8 2 5 1 5 5
// Для 45 -- 2 2 8 2 5 1 9 5
// Для 30 -- 0 0 100 0 0 0 100 57.735
// Параллельны -- 0 0 4 2 0 2 4 4

int main() {
    setlocale(LC_ALL, "");
    float aX, aY, bX, bY;
    std::wcout << L"Введите {aX, aY, bX, bY}" << std::endl;
    std::cin >> aX >> aY >> bX >> bY;
    straight BomFirst(aX, aY, bX, bY);
    BomFirst.ShowData();
    BomFirst.TheStraight();
    
    float cX, cY, dX, dY;
    std::wcout << L"Введите {cX, cY, dX, dY}" << std::endl;
    std::cin >> cX >> cY >> dX >> dY;
    straight BomSecond(cX, cY, dX, dY);
    BomSecond.ShowData();
    BomSecond.TheStraight();
    
    if (BomFirst||BomSecond)
        std::wcout << L"Прямые параллельны!" << std::endl;
    
    else    
        std::wcout << L"Угол между прямыми: " << (BomFirst<BomSecond) << std::endl;
    
    return 0;
}
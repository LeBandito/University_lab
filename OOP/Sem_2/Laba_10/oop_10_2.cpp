/*
В программе № 2 выполнить то же самое, но для данных пользовательского типа.

№ п/п | Первый контейнер| Второй контейнер | Встроенный тип данных 
5 queue vector char 

Приложение 1 
5. СТРАНА 
имя – string 
форма правления – string 
площадь – float
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>

class Country {
private:
    std::string name;
    std::string government;
    float area;

public:
    Country() {
        name = "";
        government = "";
        area = 0;
    }

    friend std::istream& operator>>(std::istream& in, Country& c) {
        std::cout << "Name: ";
        in >> c.name;

        std::cout << "Government: ";
        in >> c.government;

        std::cout << "Area: ";
        in >> c.area;

        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Country& c) {
        out << c.name << " | " << c.government << " | " << c.area;
        return out;
    }
};

void ShowQueue(std::queue<Country> q) {
    while (!q.empty()) {
        std::cout << q.front() << std::endl;
        q.pop();
    }
}

int main() {
    std::queue<Country> q1;
    int n;

    std::cout << "Count countries: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        Country c;
        std::cin >> c;
        q1.push(c);
    }

    std::cout << "\nQueue:\n";
    ShowQueue(q1);

    // удаляем первый элемент
    q1.pop();

    std::cout << "\nAfter delete:\n";
    ShowQueue(q1);

    std::queue<Country> q2;

    std::cout << "\nEnter 2 countries:\n";

    for (int i = 0; i < 2; i++) {
        Country c;
        std::cin >> c;
        q2.push(c);
    }

    while (!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }

    std::cout << "\nResult queue:\n";
    ShowQueue(q1);

    return 0;
}
/*
В программе № 3 выполнить следующее:
1. Создать контейнер, содержащий объекты пользовательского типа. 
    Тип контейнера выбирается в соответствии с вариантом задания.
2. Отсортировать его по убыванию элементов.
3. Просмотреть контейнер.
4. Используя подходящий алгоритм, найти в контейнере элемент, удовлетворяющий заданному условию.
5. Переместить элементы, удовлетворяющие заданному условию в другой (предварительно пустой) 
    контейнер. Тип второго контейнера определяется вариантом задания.
6. Просмотреть второй контейнер.
7. Отсортировать первый и второй контейнеры по возрастанию элементов.
8. Просмотреть их.
9. Получить третий контейнер путем слияния первых двух.
10. Просмотреть третий контейнер.
11 .Подсчитать, сколько элементов, удовлетворяющих заданному условию, содержит третий контейнер.
12.Определить, есть ли в третьем контейнере элемент, удовлетворяющий заданному условию.

№ п/п | Первый контейнер| Второй контейнер | Встроенный тип данных 
5 queue vector char 

Приложение 1 
5. СТРАНА 
имя – string 
форма правления – string 
площадь – float
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Country {
private:
    std::string name;
    std::string government;
    float area;

public:
    Country() {
        area = 0;
    }

    Country(std::string n, std::string g, float a) {
        name = n;
        government = g;
        area = a;
    }

    float getArea() const {
        return area;
    }

    //по возрастанию (п.7)
    bool operator<(const Country& other) const {
        return area < other.area;
    }

    friend std::ostream& operator<<(std::ostream& out, const Country& c) {
        out << c.name << " | " << c.government << " | " << c.area;

        return out;
    }
};

// по убыванию (п.2)
bool comp(const Country& a, const Country& b) {
    return a.getArea() > b.getArea();
}

// поиск (п.4)
bool predicate(const Country& c) {
    return c.getArea() > 1000000;
}

int main() {
    std::vector<Country> v1;

    v1.push_back(Country("Russia", "Republic", 17098246));
    v1.push_back(Country("Germany", "Republic", 357588));
    v1.push_back(Country("Canada", "Federation", 9984670));
    v1.push_back(Country("France", "Republic", 551695));

    // по убыванию
    std::sort(v1.begin(), v1.end(), comp);

    std::cout << "Container 1:\n";
    for (auto x : v1)
        std::cout << x << std::endl;

    // поиск
    auto it = std::find_if(v1.begin(), v1.end(), predicate);
    if (it != v1.end()) {
        std::cout << "\nFound:\n" << *it << std::endl;
    }

    // перенос во второй контейнер
    std::vector<Country> v2;
    std::copy_if(v1.begin(), v1.end(), back_inserter(v2), predicate);

    std::cout << "\nContainer 2:\n";
    for (auto x : v2)
        std::cout << x << std::endl;

    // по возрастанию
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    std::cout << "\nContainer 1 ASC:\n";
    for (auto x : v1)
        std::cout << x << std::endl;

    std::cout << "\nContainer 2 ASC:\n";
    for (auto x : v2)
        std::cout << x << std::endl;

    // слияние (п.9)
    std::vector<Country> v3;

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));

    std::cout << "\nContainer 3:\n";
    for (auto x : v3)
        std::cout << x << std::endl;

    // количество (п.11)
    int count = std::count_if(v3.begin(), v3.end(), predicate);
    std::cout << "\nCount = " << count << std::endl;

    // наличие (п.12)
    bool exists = std::any_of(v3.begin(), v3.end(), predicate);

    if (exists) {
        std::cout << "Element exists\n";
    } else {
        std::cout << "Element not found\n";
    }
    
    return 0;
}
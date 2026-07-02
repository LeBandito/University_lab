/* 
5: Комбинирование объектов функции и структур данных
Создайте структуру данных "Сотрудник", содержащую поля имя, возраст и зарплата. 
Напишите программу, которая позволяет пользователю добавлять новых сотрудников в список. 
Реализуйте возможность сортировки списка сотрудников по возрасту или зарплате с 
использованием функторов или лямбда-функций. После сортировки программа должна 
выводить отсортированный список сотрудников.

1) Добавление сотрудников.
2) Вывод списка сотрудников.
3) Сортировку по возрасту (функтор).
4) Сортировку по зарплате (лямбда-функция).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Employee {
    std::string name;
    int age;
    double salary;
};

// По возрасту
struct SortByAge {
    bool operator()(const Employee& a, const Employee& b) const {
        return a.age < b.age;
    }
};



int main() {
    std::vector<Employee> employees;

    employees = { {"abcd", 20, 22000}, 
                  {"abc", 22, 44000}, 
                  {"badv", 18, 30000}, 
                  {"bbdv", 55, 122000} };
    
    int k = 0;

    while (k != 5) {
        std::cout << "\nWhat?\n";
        std::cout << "1) Add employee\n";
        std::cout << "2) Show employees\n";
        std::cout << "3) Sort by age\n";
        std::cout << "4) Sort by salary\n";
        std::cout << "5) Exit\n";

        std::cin >> k;
        std::cin.ignore();

        if (k == 1) {
            Employee emp;

            std::cout << "Enter name: ";
            std::getline(std::cin, emp.name);

            std::cout << "Enter age: ";
            std::cin >> emp.age;

            std::cout << "Enter salary: ";
            std::cin >> emp.salary;
            std::cin.ignore();

            employees.push_back(emp);
        } else if (k == 2) {
            if (employees.empty()) {
                std::cout << "List is empty!\n";
            } else {
                for (size_t i = 0; i < employees.size(); ++i) {
                    std::cout << i + 1 << ") " 
                        << "Name: " << employees[i].name
                        << ", Age: " << employees[i].age
                        << ", Salary: " << employees[i].salary << std::endl;
                }
            }
        } else if (k == 3) {
            std::sort(employees.begin(), employees.end(), SortByAge());

            std::cout << "Sorted by age!\n";
        } else if (k == 4) {
            std::sort(employees.begin(), employees.end(), 
                [](const Employee& a, const Employee& b) { return a.salary < b.salary; });

            std::cout << "Sorted by salary!\n";
        } else if (k == 5) {
            std::cout << "Bye!\n";
        } else {
            std::cout << "Wrong command!\n";
        }
    }

    return 0;
}
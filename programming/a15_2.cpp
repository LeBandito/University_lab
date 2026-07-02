/*5. Описать структуру «дата» (год, месяц, день). 
Определить функцию «недель с начала года» вычисляющую количество недель с начала года.*/

#include <iostream>

struct Data {
    int day;
    int month;
    int year;
};

void Calculate(Data bob) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int d = 0;

    for (int i = 0; i < bob.month; i++) {
        d += days[i];
    }

    d += bob.day;

    int week = d / 8;

    std::cout << "Week = " << week;

}

int main() {
    Data bob;
    std::cout << "Enter the data: ";
    std::cin >> bob.day >> bob.month >> bob.year;

    Calculate(bob);

    return 0;
}
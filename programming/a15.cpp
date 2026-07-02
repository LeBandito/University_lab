/*Вариант 5.
Описать структуру с именем AEROFLOT, содержащую поля:
	название пункта назначения рейса;
	номер рейса;
	тип самолета.
Написать программу, выполняющую следующие действия:
	ввод с клавиатуры данных в массив, состоящий из 7 элементов типа AEROFLOT;
	вывод на экран пунктов назначения и номеров рейсов, обслуживаемых самолетом, тип которого введен с клавиатуры;
	если таких рейсов нет, вывести соответствующее сообщение.*/

#include <iostream>
#include <string>

struct AEROFLOT{
	std::string destination;
	int number;
	int plane;

};

void In(int& N, AEROFLOT* mas) {
    std::cout << "Enter arr: " << std::endl;
	
	for (int i = 0; i < N; i++) {
        std::cin.ignore();
        std::cout << "Enter the destination: " << std::endl;
		std::getline(std::cin, mas[i].destination);

        std::cout << "Enter the number and the type of airplane:" << std::endl;
		std::cin >> mas[i].number >> mas[i].plane;
	}

    std::cout << std::endl;
}

void Out(int& N, AEROFLOT* mas) {
	for (int i = 0; i < N; i++) {
        std::cout << "The type of airplane: " << mas[i].plane << std::endl;
        std::cout << mas[i].destination << " " << mas[i].number << std::endl;
	}

}

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

	AEROFLOT* arr = new AEROFLOT[n];

    In(n, arr);

    Out(n, arr);

    delete[] arr;

	return 0;
}
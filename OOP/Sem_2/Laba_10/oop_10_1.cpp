/*
В программе № 1 выполнить следующее:
1. Создать объект-контейнер в соответствии  с вариантом задания и заполнить его данными, 
    тип которых определяется вариантом задания.
2. Просмотреть контейнер.
3. Изменить контейнер, удалив из него одни элементы и заменив другие.
4. Просмотреть контейнер, используя для доступа к его элементам итераторы.
5. Создать второй контейнер этого же класса и заполнить его данными того же типа, 
    что и первый контейнер.
6. Изменить первый контейнер, удалив из него n элементов после заданного и добавив 
    затем в него все элементы из второго контейнера.
7. Просмотреть первый  и второй контейнеры.

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

void ShowQueue(std::queue<char> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::queue<char> q1;

    q1.push('A');
    q1.push('B');
    q1.push('C');
    q1.push('D');
    q1.push('E');

    std::cout << "Queue 1:\n";
    ShowQueue(q1);

    // удаление и замена элементов
    q1.pop();

    std::queue<char> temp;
    while (!q1.empty()) {
        char c = q1.front();
        q1.pop();

        if (c == 'C')
            c = 'X';

        temp.push(c);
    }

    q1 = temp;

    std::cout << "\nModified queue:\n";
    ShowQueue(q1);

    std::vector<char> vec;

    vec.push_back('K');
    vec.push_back('L');
    vec.push_back('M');

    // удалить 2 элемента после первого
    if (!q1.empty()) {
        temp.push(q1.front());
        q1.pop();

        int n = 2;
        while (!q1.empty() && n--)
            q1.pop();

        while (!q1.empty()) {
            temp.push(q1.front());
            q1.pop();
        }

        q1 = temp;
    }

    for (char c : vec)
        q1.push(c);

    std::cout << "\nQueue 1:\n";
    ShowQueue(q1);

    std::cout << "Vector:\n";
    for (char c : vec)
        std::cout << c << " ";

    return 0;
}
/* 
5.	Реализация системы управления задачами с использованием стека и очереди: 
Студентам предлагается создать систему управления задачами, которая использует 
структуры данных стек и очередь. Система должна позволять добавлять задачи в очередь, 
выполнять их в порядке приоритета, а также откладывать и завершать задачи. Стек можно 
использовать для отслеживания выполненных задач и их откладывания.
1) Просмотр очереди задач.
2) Добавление задачи.
3) Выполнение задачи.
4) Отложить задачу.
5) Просмотр отложенных задач.
6) Вернуть последнюю отложенную задачу.
7) Просмотр выполненных задач.
8) Отменить последнее выполнение.
9) Выход.
*/

#include <iostream>
#include <queue>
#include <stack>
#include <string>

struct Task {
    int id;
    std::string name;
};

int main() {
    std::queue<Task> tasks;
    std::stack<Task> completed;
    std::stack<Task> postponed;

    int nextId = 1;
    int k = 0;

    while (k != 9) {
        std::cout << "\nWhat?\n";
        std::cout << "1) Show task queue\n";
        std::cout << "2) Add task\n";
        std::cout << "3) Execute task\n";
        std::cout << "4) Postpone task\n";
        std::cout << "5) Show postponed tasks\n";
        std::cout << "6) Return postponed task\n";
        std::cout << "7) Show completed tasks\n";
        std::cout << "8) Undo last completed task\n";
        std::cout << "9) Exit\n";

        std::cin >> k;
        std::cin.ignore();

        if (k == 1) {
            if (tasks.empty()) {
                std::cout << "Queue is empty!\n";
            } else {
                std::queue<Task> temp = tasks;

                std::cout << "Current queue:\n";
                while (!temp.empty()) {
                    Task t = temp.front();
                    std::cout << "[" << t.id << "] " << t.name << std::endl;
                    temp.pop();
                }
            }
        } else if (k == 2) {
            Task t;
            t.id = nextId++;

            std::cout << "Enter task name: ";
            std::getline(std::cin, t.name);

            tasks.push(t);

            std::cout << "Task added!\n";
        } else if (k == 3) {
            if (tasks.empty()) {
                std::cout << "No tasks to execute!\n";
            } else {
                Task t = tasks.front();
                tasks.pop();

                completed.push(t);

                std::cout << "Task completed: " << t.name << std::endl;
            }
        } else if (k == 4) {
            if (tasks.empty()) {
                std::cout << "No tasks to postpone!\n";
            } else {
                Task t = tasks.front();
                tasks.pop();

                postponed.push(t);

                std::cout << "Task postponed: " << t.name << std::endl;
            }
        } else if (k == 5) {
            if (postponed.empty()) {
                std::cout << "No postponed tasks!\n";
            } else {
                std::stack<Task> temp = postponed;

                std::cout << "Postponed tasks:\n";
                while (!temp.empty()) {
                    Task t = temp.top();

                    std::cout << "[" << t.id << "] " << t.name << std::endl;

                    temp.pop();
                }
            }
        } else if (k == 6) {
            if (postponed.empty()) {
                std::cout << "No postponed tasks!\n";
            } else {
                Task t = postponed.top();
                postponed.pop();

                tasks.push(t);

                std::cout << "Task returned to queue: " << t.name << std::endl;
            }
        } else if (k == 7) {
            if (completed.empty()) {
                std::cout << "No completed tasks!\n";
            } else {
                std::stack<Task> temp = completed;

                std::cout << "Completed tasks:\n";
                while (!temp.empty()) {
                    Task t = temp.top();

                    std::cout << "[" << t.id << "] " << t.name << std::endl;

                    temp.pop();
                }
            }
        } else if (k == 8) {
            if (completed.empty()) {
                std::cout << "No completed tasks!\n";
            } else {
                Task t = completed.top();
                completed.pop();

                tasks.push(t);

                std::cout << "Completion canceled: " << t.name << std::endl;
            }
        } else if (k == 9) {
            std::cout << "Bye!\n";
        } else {
            std::cout << "Wrong command!\n";
        }
    }

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

// =======================
// Структура Student
// =======================

struct Student {
    string name;
    int age;

    // Оператор сравнения
    bool operator==(const Student& other) const {
        return name == other.name && age == other.age;
    }
};

// Перегрузка вывода
ostream& operator<<(ostream& os, const Student& s) {
    os << s.name << " (" << s.age << ")";
    return os;
}

// =======================
// Шаблон класса LinkedList
// =======================

template <typename T>
class LinkedList {
private:

    // Узел списка
    struct Node {
        T data;
        Node* next;

        Node(const T& value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;

public:

    // =======================
    // Конструктор
    // =======================

    LinkedList() {
        head = nullptr;
    }

    // =======================
    // Конструктор копирования
    // =======================

    LinkedList(const LinkedList& other) {
        head = nullptr;

        Node* current = other.head;

        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }
    }

    // =======================
    // Оператор присваивания
    // =======================

    LinkedList& operator=(const LinkedList& other) {

        if (this == &other)
            return *this;

        clear();

        Node* current = other.head;

        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }

        return *this;
    }

    // =======================
    // Деструктор
    // =======================

    ~LinkedList() {
        clear();
    }

    // =======================
    // Очистка списка
    // =======================

    void clear() {

        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // =======================
    // Добавление в начало
    // =======================

    void pushFront(const T& value) {

        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    // =======================
    // Добавление в конец
    // =======================

    void pushBack(const T& value) {

        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // =======================
    // Удаление первого элемента
    // =======================

    void popFront() {

        if (head == nullptr) {
            cout << "Список пуст!\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;
    }

    // =======================
    // Вставка по индексу
    // =======================

    void insert(int index, const T& value) {

        if (index < 0) {
            cout << "Некорректный индекс!\n";
            return;
        }

        if (index == 0) {
            pushFront(value);
            return;
        }

        Node* current = head;

        for (int i = 0; i < index - 1; i++) {

            if (current == nullptr) {
                cout << "Индекс вне диапазона!\n";
                return;
            }

            current = current->next;
        }

        if (current == nullptr) {
            cout << "Индекс вне диапазона!\n";
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = current->next;
        current->next = newNode;
    }

    // =======================
    // Печать списка
    // =======================

    void print() const {

        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "nullptr\n";
    }

    // =======================
    // Доступ для внешних функций
    // =======================

    template <typename U>
    friend int listSize(const LinkedList<U>& list);

    template <typename U>
    friend void removeValue(LinkedList<U>& list, const U& value);
};

// =======================
// Подсчёт элементов
// =======================

template <typename T>
int listSize(const LinkedList<T>& list) {

    typename LinkedList<T>::Node* current = list.head;

    int count = 0;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

// =======================
// Удаление первого вхождения
// =======================

template <typename T>
void removeValue(LinkedList<T>& list, const T& value) {

    if (list.head == nullptr)
        return;

    // Если удаляется первый элемент
    if (list.head->data == value) {

        typename LinkedList<T>::Node* temp = list.head;

        list.head = list.head->next;

        delete temp;
        return;
    }

    typename LinkedList<T>::Node* current = list.head;

    while (current->next != nullptr &&
           !(current->next->data == value)) {

        current = current->next;
    }

    if (current->next != nullptr) {

        typename LinkedList<T>::Node* temp = current->next;

        current->next = current->next->next;

        delete temp;
    }
}

// =======================
// MAIN
// =======================

int main() {

    // ====================================
    // Работа со списком int
    // ====================================

    cout << "===== LIST<int> =====\n";

    LinkedList<int> numbers;

    numbers.pushBack(10);
    numbers.pushBack(20);
    numbers.pushFront(5);

    numbers.insert(1, 15);

    numbers.print();

    cout << "Размер списка: "
         << listSize(numbers) << endl;

    removeValue(numbers, 20);

    cout << "После удаления 20:\n";

    numbers.print();

    numbers.popFront();

    cout << "После popFront:\n";

    numbers.print();


    // ====================================
    // Работа со структурой Student
    // ====================================

    cout << "\n===== LIST<Student> =====\n";

    LinkedList<Student> students;

    students.pushBack({"Alice", 20});
    students.pushBack({"Bob", 22});
    students.pushFront({"Tom", 19});

    students.print();

    cout << "Размер списка: "
         << listSize(students) << endl;

    removeValue(students, {"Bob", 22});

    cout << "После удаления Bob:\n";

    students.print();

    return 0;
}
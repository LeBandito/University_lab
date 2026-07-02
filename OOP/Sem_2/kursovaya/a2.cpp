#include <iostream>
#include <string>
#include <windows.h>

struct Student {
    std::string name;
    int age;

    bool operator==(const Student& other) const {
        return name == other.name && age == other.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.name << " (" << s.age << ")";
    return os;
}

template <typename T>
class LinkedList {
private:
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
    LinkedList() {
        head = nullptr;
    }

    LinkedList(const LinkedList& other) {
        head = nullptr;

        Node* current = other.head;

        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }
    }

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

    ~LinkedList() {
        clear();
    }

    void clear() {

        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void pushFront(const T& value) {

        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

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

    void popFront() {

        if (head == nullptr) {
            std::cout << "Список пуст!\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;
    }

    void insert(int index, const T& value) {

        if (index < 0) {
            std::cout << "Некорректный индекс!\n";
            return;
        }

        if (index == 0) {
            pushFront(value);
            return;
        }

        Node* current = head;

        for (int i = 0; i < index - 1; i++) {

            if (current == nullptr) {
                std::cout << "Индекс вне диапазона!\n";
                return;
            }

            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Индекс вне диапазона!\n";
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = current->next;
        current->next = newNode;
    }

    void print() const {

        Node* current = head;

        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }

        std::cout << "nullptr\n";
    }

    template <typename U>
    friend int listSize(const LinkedList<U>& list);

    template <typename U>
    friend void removeValue(LinkedList<U>& list, const U& value);
};

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

template <typename T>
void removeValue(LinkedList<T>& list, const T& value) {

    if (list.head == nullptr)
        return;

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

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "LIST<int>: \n";

    LinkedList<int> numbers;

    numbers.pushBack(10);
    numbers.pushBack(20);
    numbers.pushFront(5);

    numbers.insert(1, 15);

    numbers.print();

    std::wcout << L"Размер списка: ";
    std::cout << listSize(numbers) << std::endl;

    removeValue(numbers, 20);

    std::wcout << L"После удаления 20:\n";

    numbers.print();

    numbers.popFront();

    std::wcout << L"После popFront:\n";

    numbers.print();

    std::cout << "\nLIST<Student>: \n";

    LinkedList<Student> students;

    students.pushBack({"Alice", 20});
    students.pushBack({"Bob", 22});
    students.pushFront({"Tom", 19});

    students.print();

    std::wcout << L"Размер списка: ";
    std::cout << listSize(students) << std::endl;

    removeValue(students, {"Bob", 22});

    std::wcout << L"После удаления Bob:\n";

    students.print();

    return 0;
}



/*для ЛР№1 нужно просто создать класс с данными и 1-2 методами (не конструкторами) 
и  продемонстрировать описание функций в классе и вне класса.
5. ТОВАР (имя – char *, количество – int, стоимость – float)*/

#include <iostream>
#include <string>

class products {
    public:
        std::string name;
        int quantity;
        float cost;
    
    void show_products() {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Количество: " << quantity << std::endl;
        std::cout << "Стоимость: " << cost << std::endl;
    };
};

int main() {
    products milk, bread;

    milk.name = "Our Cow";
    milk.quantity = 3;
    milk.cost = 80;

    bread.name = "Grain";
    bread.quantity = 5;
    bread.cost = 30;

    milk.show_products();
    bread.show_products();

    return 0;
}
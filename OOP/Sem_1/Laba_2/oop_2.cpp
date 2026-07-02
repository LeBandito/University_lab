/*5. ТОВАР (имя – char *, количество – int, стоимость – float)*/
#include <iostream>

class products{
    public:
        std::string name;
        int quantity;
        float cost;
    
    // products() : name("Nothing"), quantity(0), cost(0.0) {}
    // products(std::string Name, int Quantity, float Cost) : name(Name), quantity(Quantity), cost(Cost) {}
    // products(const products& other) 
    //     : name(other.name), quantity(other.quantity), cost(other.cost) 
    //     {std::cout << "Копируем!" << std::endl;}

    // Конструктор без параметров
    products() {
        name = "Nothing"; 
        quantity = 0; 
        cost = 0.0;
        std::cout << "Вызван конструктор без параметров" << std::endl;
    }

    products(std::string Name, int Quantity, float Cost) {
        name = Name; 
        quantity = Quantity; 
        cost = Cost;
        std::cout << "Вызван конструктор с параметрами" << std::endl;
    }

    products(const products& other) {
        name = other.name; 
        quantity = other.quantity; 
        cost = other.cost;
        std::cout << "Копируем!" << std::endl;
    }

    void change_cost(float newcost) {
        cost = newcost;
        std::cout << "Меняем цену!" << std::endl;
    }

    ~products() {
        std::cout << "Удаляем!" << std::endl;
    }

    // Просмотр
    std::string getName() const { return name; }
    int getQuantity() const { return quantity; }
    float getCost() const { return cost; }

    // Установка
    void setName(const std::string& n) { name = n; }
    void setQuantity(int q) { quantity = q; }
    void setCost(float c) { cost = c; }

    void show_products();
};

void products::show_products() {
    std::cout << "Имя: " << name << std::endl;
    std::cout << "Количество: " << quantity << std::endl;
    std::cout << "Стоимость: " << cost << std::endl;
    std::cout << " ---------- " << std::endl;
};

int main() {
    // указатель на компоненту-функцию.
    void (products::*show_funk)() = &products::show_products;

    {
    products milk("Our Cow", 3, 80);
    milk.show_products();
    // (milk.*show_funk)();

    products copymilk(milk);
    copymilk.show_products();    
    // (copymilk.*show_funk)();

    products bread("Grain", 5, 30);
    bread.show_products();
    // (bread.*show_funk)();

    // указатель на экземпляр класса.
    products* newbread;
    newbread = &bread;
    newbread -> change_cost(32.8);
    bread.show_products();
    }

    // Массив статический 
    {
        products listT[3] = {products(), products("Сок Добрый", 3, 80.7), products("Черешня", 2, 270.3)};
        
        for (int i = 0; i < 3; i++) {
            (listT[i].*show_funk)();
        } 
    }

    // Массив динамический 
    {
        products* dynamiclistT = new products[2];
        dynamiclistT[0] = products("Сыр", 4, 140.6);
        dynamiclistT[1] = products("Колбаса", 1, 67.5);

        for (int i = 0; i < 3; i++) {
            (dynamiclistT[i].*show_funk)();
        } 
        
        // Очистка 
        delete[] dynamiclistT;
    }

    products nothing;
    nothing.show_products();    
    // (nothing.*show_funk)();

    return 0;
}
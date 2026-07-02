/*Задание: 
Построить иерархию классов в соответствии с вариантом задания. Построить диаграммы классов.
Вариант 5:Игрушка, продукт, товар, молочный продукт*/

#include <iostream>

class product {
    private:
        int the_product;
    
    public:
        product(): the_product()
        {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}

        product(int new_product): the_product(new_product)
        {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}

        product(const product& other): the_product(other.the_product)
        {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
        
        void set_product(int new_product) {the_product = new_product;}
        int get_product() const {return the_product;}
        
        virtual void Show() 
        {std::cout << "the_product is " << get_product() << std::endl;}
            
        virtual ~product()
        {std::wcout << L"Удаляем product!" << std::endl;}
};

class Toy : public product {
    private:
        int the_toy;
    
    public:
        Toy(): the_toy(), product()
        {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}

        Toy(int new_toy, int new_product): the_toy(new_toy), product(new_product)
        {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}

        Toy(const Toy& other): the_toy(other.the_toy), product(other.get_product())
        {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
        
        void set_Toy(int new_toy) {the_toy = new_toy;}
        int get_Toy() const {return the_toy;}

        void Show()
        {
            product::Show();
            std::cout << "the_toy is " << get_Toy() << std::endl;
        }
        
        ~Toy()
        {std::wcout << L"Удаляем!" << std::endl;}
};

class productFood : public product {
    private:
        int the_productFood;
    
    public:
        productFood(): the_productFood(), product()
        {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}

        productFood(int new_Food, int new_product): 
            the_productFood(new_Food), product(new_product)
        {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}

        productFood(const productFood& other): 
            the_productFood(other.the_productFood), product(other.get_product())
        {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
        
        void set_productFood(int new_Food) {the_productFood = new_Food;}
        int get_productFood() const {return the_productFood;}

        void Show()
        {
            product::Show();
            std::cout << "the_productFood is " << get_productFood() << std::endl;
        }
        
        ~productFood()
        {std::wcout << L"Удаляем!" << std::endl;}
};

class milkProduct : public productFood {
    private:
        int the_milkProduct;
    
    public:
        milkProduct(): the_milkProduct(), productFood()
        {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}

        milkProduct(int new_milk, int new_Food, int new_product): 
            the_milkProduct(new_milk), productFood(new_Food, new_product)
        {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}

        milkProduct(const milkProduct& other): the_milkProduct(other.the_milkProduct), 
            productFood(other.get_productFood(), other.get_product())
        {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
        
        void set_milkProduct(int new_milk) {the_milkProduct = new_milk;}
        int get_milkProduct() const {return the_milkProduct;}

        void Show()
        {
            productFood::Show();
            std::cout << "the_milkProduct is " << get_milkProduct() << std::endl;
        }
        
        ~milkProduct()
        {std::wcout << L"Удаляем!" << std::endl;}
};

int main() {
    Toy toy(10, 100);
    toy.Show();
    
    std::cout << "---" << std::endl;
    
    milkProduct milk(50, 200, 300);
    milk.Show();
    
    return 0;
}
/*5. ТОВАР (имя – char *, количество – int, стоимость – float)*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>

class ProductManipulator {
    private:
        int width;
        char fillChar;
        bool alignLeft;
    public:
        ProductManipulator(int w, char f, bool a) : width(w), fillChar(f), alignLeft(a) {}
        
        friend std::ostream& operator<<(std::ostream& os, const ProductManipulator& pm);
};

std::ostream& operator<<(std::ostream& os, const ProductManipulator& pm) {
    os.width(pm.width);
    os.fill(pm.fillChar);
    
    if (pm.alignLeft) {
        os << std::left;
    } else {
        os << std::right;
    }
    
    return os;
}

ProductManipulator productFormat(int width, char fillChar, bool alignLeft) {
    return ProductManipulator(width, fillChar, alignLeft);
}

class products {
    private:
        char name[30];
        int quantity;
        float cost;
    
    public:
        products(): name(), quantity(), cost()
        { std::wcout << L"Вызван конструктор без параметрами" << std::endl; }

        products(const char* Name, int Quantity, float Cost): quantity(Quantity), cost(Cost)
        { strcpy(name, Name); std::wcout << L"Вызван конструктор с параметрами" << std::endl; }

        products(const products& other): quantity(other.quantity), cost(other.cost)
        { strcpy(name, other.name); std::wcout << L"Вызван конструктор копирования" << std::endl; }

        const char* getName() const { return name; }
        int getQuantity() const { return quantity; }
        float getCost() const { return cost; }

        void setName(const std::string& n)
        { 
            strncpy(name, n.c_str(), 29);
            name[29] = '\0';
        }        
        void setQuantity(int q) { quantity = q; }
        void setCost(float c) { cost = c; }

        void change_cost(float newcost);
        
        void show_products();
        
        friend std::ostream& operator<<(std::ostream& os, const products& p);
        friend std::istream& operator>>(std::istream& is, products& p);
        
        ~products() { std::wcout << L"Удаляем!" << std::endl; }
};

void products::change_cost(float newcost) {
    setCost(newcost);
    std::wcout << L"Меняем цену!" << std::endl;
}

void products::show_products() {
    std::wcout << L"Имя: "; std::cout << getName() << std::endl;
    std::wcout << L"Количество: "; std::cout << getQuantity() << std::endl;
    std::wcout << L"Стоимость: "; std::cout << getCost() << std::endl;
};

std::istream& operator>>(std::istream& is, products& p) {
    is >> p.name >> p.quantity >> p.cost;
    return is;
}

void ViewWords() {
    std::ifstream f;
    f.open("DataBum.dat", std::ios::in | std::ios::binary);
    products vrem;
    
    while(f.read((char*)&vrem, sizeof(products))) {        
        std::cout << vrem << std::endl;
    }
}

// milk 10 85.5 bread 5 45.0 cheese 3 320.0 

/*
    Я решил сделать чтение до пустой строки. То есть, после введения данных, 
    нужно просто ещё раз нажать Enter!
*/ 

int main() {
    products milk("milk", 10, 85.5);
    
    std::cout << productFormat(15, '-', true) << milk.getName() 
              << productFormat(8, ' ', false) << milk.getQuantity()
              << productFormat(10, '.', false) << milk.getCost() << std::endl;
    return 0;
}
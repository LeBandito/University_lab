/*5. ТОВАР (имя – char *, количество – int, стоимость – float)*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

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

std::ostream& operator<<(std::ostream& os, const products& p) {
    os << p.name << " " << p.quantity << " " << p.cost;
    return os;
}

std::istream& operator>>(std::istream& is, products& p) {
    is >> p.name >> p.quantity >> p.cost;
    return is;
}

void BumOut(std::fstream& f) {
    f.open("DataBum.dat", std::ios::out);
}

void ReadData(std::fstream& f) {
    std::wcout << L"Введите данные: " << std::endl;
    int k(0);
    std::string words;
    
    do {
        std::getline(std::cin, words);
        std::string check;
        products vrem;
        int flag(0);
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] != ' ') {
                check.push_back(words[i]);
            } else {
                switch (flag)
                {
                    case 1:
                        vrem.setName(check);
                        flag += 1;
                        break;
                    case 2:
                        vrem.setQuantity(stoi(check));
                        flag += 1;
                        break;
                    case 3:
                        vrem.setCost(stof(check));
                        flag += 1;
                        break;
                    default:
                        break;
                }
                
                check = "";
            }
        }
        
        if ((flag == 3) && (!check.empty()))
            vrem.setCost(stof(check));
        
        f.write((char*)&vrem, sizeof(products));
        
        k += 1;
    } while (!words.empty());
    
    std::wcout << L"Всего "; std::cout << k; std::wcout << L" записей!" << std::endl;
}

// milk 10 85.5 bread 5 45.0 cheese 3 320.0 

/*
    Я решил сделать чтение до пустой строки. То есть, после введения данных, 
    нужно просто ещё раз нажать Enter!
*/ 

int main() {
    setlocale(LC_ALL, "");
    std::fstream f;
    BumOut(f);
    ReadData(f);
    
    products milk("cow", 5, 1000);
    milk.show_products();
    
    milk.change_cost(900);
    milk.show_products();
    
    return 0;
}
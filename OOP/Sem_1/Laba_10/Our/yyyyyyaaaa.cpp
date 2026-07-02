#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <algorithm>

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

class products {
    private:
        char name[30];
        int quantity;
        float cost;
    
    public:
        products(): name(), quantity(), cost() {}
        
        products(const products& other): 
        quantity(other.quantity), cost(other.cost) { strcpy(name, other.name); }
        
        products(const char* Name, int Quantity, float Cost): 
        quantity(Quantity), cost(Cost) { strcpy(name, Name); }
        
        void setName(const std::string& n)
        { 
            strncpy(name, n.c_str(), 29);
            name[29] = '\0';
        }
        void setQuantity(int newQuantity) {quantity = newQuantity;}
        void setCost(float newCost) {cost = newCost;}
        
        std::string getName() const 
        { return std::string(name); }
        int getQuantity() const {return quantity;}
        float getCost() const {return cost;}

        friend std::ostream& operator<<(std::ostream& os, const products& p);
};

std::istream& operator>>(std::istream& is, products& p) {
    std::string temp_name;
    int temp_quantity;
    float temp_cost;
    
    is >> temp_name >> temp_quantity >> temp_cost;
    
    p.setName(temp_name);
    p.setQuantity(temp_quantity);
    p.setCost(temp_cost);
    
    return is;
}

std::ostream& operator<<(std::ostream& os, const products& p) {
    os << p.name << " " << p.quantity << " " << p.cost;
    return os;
}

void ReadData(std::fstream& f) {
    f.open("DataBum.dat", std::ios::out | std::ios::binary);
    
    if (!f.is_open()) {
        std::wcout << L"DataBum.dat не найден!" << std::endl;
        return;
    }
    
    std::vector<products> all_products;
    std::string words, check;
    std::getline(std::cin, words);
    
    products vrem;
    int flag(1);

    for (int i = 0; i < words.size(); i++) {
        if (words[i] != ' ') {
            check += words[i];
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
                    flag = 1;
                    all_products.push_back(vrem);
                    vrem = products();
                    break;
                default:
                    break;
            }
            
            check = "";
        }
    }
    
    if (!check.empty()) {
        switch (flag) {
            case 1:
                vrem.setName(check);
                break;
            case 2:
                vrem.setQuantity(stoi(check));
                break;
            case 3:
                vrem.setCost(stof(check));
                break;
        }
    }
    
    all_products.push_back(vrem);
    
    for (int i = 0; i < all_products.size(); i++) {
        f.write((char*)&all_products[i], sizeof(products));
    }
    
    f.close();
}

products OneWord() {
    std::string words;
    std::getline(std::cin, words);
    
    products vrem;
    std::string check;
    int flag(1);

    for (int i = 0; i < words.size(); i++) {
        if (words[i] != ' ') {
            check += words[i];
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
    
    if (!check.empty()) {
        switch (flag) {
            case 1:
                vrem.setName(check);
                break;
            case 2:
                vrem.setQuantity(stoi(check));
                break;
            case 3:
                vrem.setCost(stof(check));
                break;
        }
    }
    
    return vrem; 
}

void AddWord(std::fstream& f) {
    f.open("DataBum.dat", std::ios::app | std::ios::binary);
    
    if (!f.is_open()) {
        std::wcout << L"DataBum.dat не найден!" << std::endl;
        return;
    }
    
    std::wcout << L"Введите данные, которые хотите добавить: " << std::endl;
    products vrem = OneWord();
    
    std::cout << vrem.getName() << " " << vrem.getQuantity() 
    << " " << vrem.getCost() << std::endl;
    
    f.write((char*)&vrem, sizeof(products));
    f.close();
}

void CheckData() {
    std::ifstream f("DataBum.dat", std::ios::binary);
    
    if (!f.is_open()) {
        std::wcout << L"DataBum.dat не найден!" << std::endl;
        return;
    }
    
    std::wcout << L"Просмотрим внесённые данные: " << std::endl;
    products vrem;
    int k(1);
    
    while(f.read((char*)&vrem, sizeof(products))) {
        std::cout << ProductManipulator(3, ' ', false) << k << ") "
                  << ProductManipulator(15, '-', true) << vrem.getName()
                  << ProductManipulator(8, ' ', false) << vrem.getQuantity()
                  << ProductManipulator(10, '*', false) << vrem.getCost()
                  << std::endl;
        k++;
    }
    
    f.close();
}

void SearchData() {
    std::ifstream f("DataBum.dat", std::ios::binary);
    
    if (!f.is_open()) {
        std::wcout << L"DataBum.dat не найден!" << std::endl;
        return;
    }
    
    products vrem;
    
    std::wcout << L"Что ищем?" << std::endl;
    std::string search;
    std::cin >> search;
    
    std::wcout << L"Ищем данные: ";
    std::cout << search << std::endl;

    bool found(false);    
    int k(1);
    
    while(f.read((char*)&vrem, sizeof(products))) {
        if (search == vrem.getName()) {
            std::wcout << L"Нашли!" << std::endl;
            std::cout << k << ") " << vrem.getName() << " " << vrem.getQuantity() 
            << " " << vrem.getCost() << std::endl;
            found = true;
        }
        
        k += 1;
    }
    
    if (!found) {
        std::wcout << L"Данные не найдены!" << std::endl;
    }
    
    f.close();
}

void DeleteData() {
    std::ifstream g("DataBum.dat", std::ios::binary);
    std::ofstream f("temp.dat", std::ios::binary);
    
    if (!g.is_open()) {
        std::wcout << L"DataBum.dat не найден" << std::endl;
        return;
    }
    
    if (!f.is_open()) {
        std::wcout << L"Не удалось создать временный файл" << std::endl;
        g.close();
        return;
    }
    
    products vrem, repl;
    
    int choice;
    std::wcout << L"Введите номер строки: " << std::endl;
    std::cin >> choice;

    int check(1);
    
    bool found = false;

    while(g.read((char*)&vrem, sizeof(products))) {        
        if (choice == check) {
            std::wcout << L"УДАЛЕНО:\n" << choice << ") ";
            std::cout << vrem.getName() << " ";
            std::cout << vrem.getQuantity() << " ";
            std::cout << vrem.getCost() << std::endl;
            found = true;
        } else {
            f.write((char*)&vrem, sizeof(products));
        }
        
        check += 1;
    }
    
    if (found) {
        std::wcout << L"Удаление завершено!" << std::endl;
    } else {
        std::wcout << L"Слово не найдено!" << std::endl;
    }
    
    g.close();  
    f.close();
    remove("DataBum.dat");
    rename("temp.dat", "DataBum.dat"); 
}

void CorrectData() {
    std::ifstream g("DataBum.dat", std::ios::binary);
    std::ofstream f("temp.dat", std::ios::binary);
    
    if (!g.is_open()) {
        std::wcout << L"DataBum.dat не найден" << std::endl;
        return;
    }
    
    if (!f.is_open()) {
        std::wcout << L"Не удалось создать временный файл" << std::endl;
        g.close();
        return;
    }
    
    products vrem;
    
    int choice, tme(1);
    std::wcout << L"Введите номер строки: " << std::endl;
    std::cin >> choice;
    
    int check(1);
    bool found = false;

    while(g.read((char*)&vrem, sizeof(products))) {
        if (choice == check) {
            std::cout << choice << ") " << vrem.getName() << " " << 
            vrem.getQuantity() << " " << vrem.getCost() << std::endl;
            
            std::wcout << L"Введите данные: " << std::endl;
            std::cin.ignore();
            products BomBomBom = OneWord();
            f.write((char*)&BomBomBom, sizeof(products));
            found = true;
        } else {
            f.write((char*)&vrem, sizeof(products));
        }
        
        check += 1;
    }
    
    if (found) {
        std::wcout << L"Изменения зафиксированы!" << std::endl;
    } else {
        std::wcout << L"Слово не найдено!" << std::endl;
    }
    
    g.close();  
    f.close();  
    remove("DataBum.dat");
    rename("temp.dat", "DataBum.dat"); 
}

void variants(int OurChoice, std::fstream& f) {      
    switch(OurChoice)
    {
        case 1:
            AddWord(f);
            break;
        case 2: 
            CheckData();
            break;
        case 3: 
            SearchData();
            break;
        case 4: 
            DeleteData();
            break;
        case 5: 
            CorrectData();
            break;
        case 6: 
            std::wcout << L"Ну всё..." << std::endl;
            break;
        default: 
            std::wcout << L"Чего? Такого x нету!" << "\n";
            break;
    }
}

// milk 10 85.5 bread 5 45.0 cheese 3 320.0

int main() {
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");
    
    std::fstream f;
    std::wcout << L"Внесите данные:" << std::endl;
    ReadData(f);
        
    int OurChoice;
    
    do {
        std::wcout << L"Что будем делать?" << std::endl;
        std::wcout << L"1) Добавить данные." << std::endl; 
        std::wcout << L"2) Просмотреть данные." << std::endl; 
        std::wcout << L"3) Искать данные." << std::endl; 
        std::wcout << L"4) Удалить данные." << std::endl; 
        std::wcout << L"5) Исправить данные." << std::endl; 
        std::wcout << L"6) Выход из программы." << std::endl; 
        
        std::cin >> OurChoice;
        std::cin.ignore();
        
        variants(OurChoice, f);
        std::cout << std::endl;
    } while (OurChoice != 6);
    
    return 0;
}

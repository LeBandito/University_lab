#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <algorithm>

class products {
    public:
        char name[30];
        int quantity;
        float cost;
    
        products(): name(), quantity(), cost() {}
        products(const char* Name, int Quantity, float Cost): 
        quantity(Quantity), cost(Cost) { strcpy(name, Name); }
        
        void setName(const std::string& n)
        { 
            strncpy(name, n.c_str(), 29);
            name[29] = '\0';
        }

        friend std::ostream& operator<<(std::ostream& os, const products& p);
};

std::ostream& operator<<(std::ostream& os, const products& p) {
    os << p.name << " " << p.quantity << " " << p.cost;
    return os;
}

void BumOut(std::fstream& f) {
    f.open("DataBum.dat", std::ios::out);
}

void ReadData(std::fstream& f, std::vector<products>& all_products) {
    std::string words;
    
    while (std::getline(std::cin, words)) {
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
                        vrem.quantity = stoi(check);
                        flag += 1;
                        break;
                    case 3:
                        vrem.cost = stof(check);
                        flag += 1;
                        break;
                    default:
                        break;
                }
                
                check = "";
            }
        }
        
        if ((flag == 3) && (!check.empty()))
            vrem.cost = stof(check);
        
        all_products.push_back(vrem);
    }
    
    for (int i = 0; i < all_products.size(); i++) {
        f.write((char*)&all_products[i], sizeof(products));
    }
    
    f.close();
}

void AddWord() {
    std::ofstream f;
    f.open("DataBum.dat", std::ios::app | std::ios::binary);
    
    std::string words;
    
    std::wcout << L"Напишите данные, которые хотите добавить: " << std::endl;
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
                    vrem.quantity = stoi(check);
                    flag += 1;
                    break;
                case 3:
                    vrem.cost = stof(check);
                    flag += 1;
                    break;
                default:
                    break;
            }
            
            check = "";
        }
    }
    
    if ((flag == 3) && (!check.empty()))
        vrem.cost = stof(check);
    
    f.write((char*)&vrem, sizeof(products));
    f.close();
}

void CheckData(std::fstream& f) {
    f.open("DataBum.dat", std::ios::out);
    std::wcout << L"Просмотрим внесённые данные: " << std::endl;
    products vrem;
    int k(1);
    
    while(f.read((char*)&vrem, sizeof(products))) {
        std::cout << k << ") ";
        std::cout << vrem.name << " ";
        std::cout << vrem.quantity << " ";
        std::cout << vrem.cost << std::endl;
        k += 1;
    }
}

void DeleteData(std::fstream& f) {
    std::ifstream g("DataBum.dat", std::ios::binary);
    std::ofstream f("temp.dat", std::ios::binary);
    products vrem;
    
    int choice;
    std::wcout << L"Введите номер строки: " << std::endl;
    std::cin >> choice;

    int check(1);
    
    bool found = false;

    while(g.read((char*)&vrem, sizeof(products))) {        
        if (choice == check) {
            std::wcout << L"УДАЛЕНО:\n" << choice << ") ";
            std::cout << vrem.name << " ";
            std::cout << vrem.quantity << " ";
            std::cout << vrem.cost << std::endl;
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

int main() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream f, g;
    In(f, g);
    
    std::vector<sales> all_sales;
    std::vector<products> all_products;
    
    DataIn(f, g, all_sales, all_products);
    // CheckData(all_sales, all_products);
    
    std::vector<int> max_product(14, 0), max_clients(300, 0), last_clients(300, 0);
    
    MaxInformation(max_product, max_clients, all_sales);
    // CheckMax(max_product, max_clients, all_products);
    
    LastInformation(max_clients, last_clients, all_sales);
    // CheckLast(last_clients, all_products);
    
    // CustomerPurchases(all_sales, all_products);
    
    // Весь перебор и частичный перебор по 1 значению
    std::vector<std::vector<int>> products_products_Need;
    
    BoughtTogether(all_sales, products_products_Need);
    CheckTogether(all_products, products_products_Need);
    
    // Пробуем на Сканер
    // std::cout << all_products[PredictNextProduct(2, products_products_FL)].product << std::endl;
    
    PredictDay(max_clients, last_clients, all_products, products_products_Need);
    
    return 0;
}
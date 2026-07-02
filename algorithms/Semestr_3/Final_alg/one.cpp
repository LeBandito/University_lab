
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <algorithm>

struct sales {
    int day;
    int num;
    int client;
    int product;
};

struct products {
    int num;
    std::string product;
    int price;
};

void In(std::ifstream& f, std::ifstream& g) {
    f.open("1.txt", std::ios::in);
    g.open("2.txt", std::ios::in);
}

void DataIn(std::ifstream& f, std::ifstream& g, 
    std::vector<sales>& all_sales, std::vector<products>& all_products) {
    std::string words_sales, words_products;
    
    while (std::getline(f, words_sales)) {
        sales vrem;
        std::string check;
        int flag(1);

        for (int i = 0; i < words_sales.size(); i++) {
            if (words_sales[i] != '\t') {
                check += words_sales[i];
            } else {
                switch (flag)
                {
                    case 1:
                        vrem.day = stoi(check);
                        flag += 1;
                        break;
                    case 2:
                        vrem.num = stoi(check);
                        flag += 1;
                        break;
                    case 3:
                        vrem.client = stoi(check);
                        flag += 1;
                        break;
                    case 4:
                        vrem.product = stoi(check);
                        flag += 1;
                        break;
                    default:
                        break;
                }
                
                check = "";
            }
        }
        
        if ((flag == 4) && (!check.empty()))
            vrem.product = stoi(check);
        
        all_sales.push_back(vrem);
    }
    
    while (std::getline(g, words_products)) {
        products vrem;
        std::string check;
        int flag(1);

        for (int i = 0; i < words_products.size(); i++) {
            if (words_products[i] != '\t') {
                check += words_products[i];
            } else {
                switch (flag)
                {
                    case 1:
                        vrem.num = stoi(check);
                        flag += 1;
                        break;
                    case 2:
                        vrem.product = check;
                        flag += 1;
                        break;
                    case 3:
                        vrem.price = stoi(check);
                        flag += 1;
                        break;
                    default:
                        break;
                }
                
                check = "";
            }
        }
        
        if ((flag == 3) && (!check.empty()))
            vrem.price = stoi(check);
        
        all_products.push_back(vrem);
    }
}

void CheckData(std::vector<sales>& all_sales, std::vector<products>& all_products) {
    std::wcout << L"Проверим внесённые данные по дням: " << std::endl;
    
    for (int i = 0; i < all_sales.size(); i++) {
        std::cout << all_sales[i].day << " ";
        std::cout << all_sales[i].num << " ";
        std::cout << all_sales[i].client << " ";
        std::cout << all_sales[i].product << " " << std::endl;
    }
        
    std::wcout << L"Проверим внесённые данные по товарам: " << std::endl;

    for (int i = 0; i < all_products.size(); i++) {
        std::cout << all_products[i].num << " ";
        std::cout << all_products[i].product << " ";
        std::cout << all_products[i].price << " " << std::endl;
    }
}

void MaxInformation(std::vector<int>& max_product, std::vector<int>& max_clients, 
    std::vector<sales>& all_sales) {
    for (int i = 0; i < all_sales.size(); i++) {
        max_product[all_sales[i].product - 1] += 1;
        max_clients[all_sales[i].client - 1] += 1;
    }
}

void CheckMax(std::vector<int>& max_product, std::vector<int>& max_clients, 
    std::vector<products>& all_products) {
    std::wcout << L"Проверим максимальные данные по продуктам: " << std::endl;
    
    for (int i = 0; i < max_product.size(); i++) {
        std::cout << all_products[i].product << ": " << max_product[i] << std::endl;
    }
        
    std::wcout << L"Проверим максимальные данные по клиентам: " << std::endl;

    for (int i = 0; i < max_clients.size(); i++) {
        std::wcout << L"Клиент " << i + 1 << ": ";
        std::cout << max_clients[i] << std::endl;
    }
}

void LastInformation(std::vector<int>& max_clients, 
    std::vector<int>& last_clients, std::vector<sales>& all_sales) {  
    for (int i = 0; i < all_sales.size(); i++) {
        last_clients[all_sales[i].client - 1] = all_sales[i].product - 1;
    }
}

void CheckLast(std::vector<int>& last_clients, std::vector<products>& all_products) {
    std::wcout << L"Поседняя покупка клнтов: " << std::endl;
    
    for (int i = 0; i < 300; i++) {
        std::wcout << L"Клиент " << i + 1 << ": ";
        std::cout << all_products[last_clients[i]].product << std::endl;
    }
}

void CustomerPurchases(std::vector<sales>& all_sales, std::vector<products>& all_products) {
    for (int i = 0; i < 300; i++) {
        std::cout << i + 1;
        std::wcout << L" Клиент: " << std::endl;
        
        for (int j = 0; j < 14; j++) {
            std::cout << "\t" << all_products[j].product << " --- ";
            int check(0);
            
            for (int k = 0; k < all_sales.size(); k++) {
                if ((all_sales[k].client == i) && (all_sales[k].product == j))
                    check += 1;
            }
            
            std::cout << check << std::endl;
        }
    }
}

void BoughtTogether(std::vector<sales>& all_sales,  
    std::vector<std::vector<int>>& products_products_Need) {
    for (int i = 0; i < 14; i++) {
        std::vector<int> vrem(14, 0);
        products_products_Need.push_back(vrem);
    }
        
    std::vector<std::vector<int>> client_purchases(300);
    
    for (int i = 0; i < all_sales.size(); i++) {
        client_purchases[all_sales[i].client - 1].push_back(all_sales[i].product);
    }
    
    for (int i = 0; i < 300; i++) {
        std::wcout << L"Клиент " << i + 1 << ": ";
        
        for (int j = 0; j < client_purchases[i].size(); j++) {
            std::cout << client_purchases[i][j] << " ";
        }
        
        std::cout << std::endl;
    }
    
    // Вариант 3 - Вот он то и был нужен!
    
    for (int i = 0; i < 300; i++) {
        int NewFlag = 0;
        
        for (int j = 0; j < client_purchases[i].size(); j++) {
            int current_product = client_purchases[i][j];
            
            if (NewFlag == 0) {
                NewFlag = current_product;
            } else {
                products_products_Need[NewFlag - 1][current_product - 1] += 1;
                // products_products_Need[current_product - 1][NewFlag - 1] += 1;
                NewFlag = current_product;
            }
        }
    }
}

void CheckTogether(std::vector<products>& all_products, 
    std::vector<std::vector<int>>& products_products_Need) {
    std::wcout << L"\nКакой товар покупали после КАЖДОГО:" << std::endl;

    for (int i = 0; i < products_products_Need.size(); i++) {
        std::cout << all_products[i].product;
        
        std::cout << std::string(19 - all_products[i].product.size(), ' ');
        
        for (int j = 0; j < products_products_Need[i].size(); j++) {
            std::cout << std::string(5 - std::to_string(products_products_Need[i][j]).size(), ' ') 
            << products_products_Need[i][j];
        }
        
        std::cout << std::endl;
    }
}

int PredictNextProduct(int last_product, std::vector<std::vector<int>>& products_products_FL) {
    int maxx(0);
    
    for (int i = 0; i < 14; i++) {
        if (products_products_FL[last_product][i] > products_products_FL[last_product][maxx])
            maxx = i;
    }
    
    return maxx;
}

void PredictDay(std::vector<int>& max_clients, std::vector<int>& last_clients, 
    std::vector<products>& all_products, std::vector<std::vector<int>>& products_products_FL) {
    std::wcout << L"\nНа 501 день скорее всего купят: " << std::endl;
    
    std::vector<std::pair<int, int>> BomBomBom;
    
    for (int i = 0; i < 300; i++) {
        BomBomBom.push_back({max_clients[i], i});
    }
    
    std::sort(BomBomBom.begin(), BomBomBom.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        } else {
            return a.second < b.second;
        }
    });
        
    int well(0);
    
    for (int i = 0; i < 20; i++) {
        int vrem = PredictNextProduct(last_clients[BomBomBom[i].second], products_products_FL);
        std::cout << i + 1 << ")" << std::string(3 - std::to_string(i + 1).size(), ' ');
        std::wcout << L"Клиент " << BomBomBom[i].second + 1 << ":";
        std::cout << std::string(4 - std::to_string(BomBomBom[i].second + 1).size(), ' ');
        std::cout << all_products[vrem].product;
        std::cout << std::string(20 - all_products[vrem].product.size(), ' ');
        std::cout << all_products[vrem].price << std::endl;
        well += all_products[vrem].price;
    }
    
    std::wcout << L"\nПредположительная стоимость за 501 день: " << well;
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
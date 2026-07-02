#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>
#include <string>
#include <cstring>

class products {
    private:
        char name[30];
        int quantity;
        float cost;

    public:
        // Объявления конструкторов
        products();
        products(const char* Name, int Quantity, float Cost);
        products(const products& other);
        
        // Объявления геттеров
        const char* getName() const;
        int getQuantity() const;
        float getCost() const;
        
        // Объявления сеттеров
        void setName(const std::string& n);
        void setQuantity(int q);
        void setCost(float c);
        
        // Объявления других методов
        void change_cost(float newcost);
        void show_products();
        
        // Объявления перегруженных операторов
        friend std::ostream& operator<<(std::ostream& os, const products& p);
        friend std::istream& operator>>(std::istream& is, products& p);
        
        // Объявление деструктора
        ~products();
};

#endif
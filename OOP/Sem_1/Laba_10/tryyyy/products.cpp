#include "products.h"
#include <iostream>
#include <string> 
#include <cstring>

// Реализации конструкторов
products::products() : name(), quantity(), cost()
{ std::wcout << L"Вызван конструктор без параметрами" << std::endl; }

products::products(const char* Name, int Quantity, float Cost): quantity(Quantity), cost(Cost) 
{ strcpy(name, Name); std::wcout << L"Вызван конструктор с параметрами" << std::endl; }

products::products(const products& other): quantity(other.quantity), cost(other.cost) 
{ strcpy(name, other.name); std::wcout << L"Вызван конструктор копирования" << std::endl; }

// Реализации геттеров
const char* products::getName() const  { return name; }
int products::getQuantity() const { return quantity; }
float products::getCost() const { return cost; }

// Реализации сеттеров
void products::setName(const std::string& n)
{ 
    strncpy(name, n.c_str(), 29);
    name[29] = '\0';
}        
void products::setQuantity(int q) { quantity = q; }
void products::setCost(float c) { cost = c; }

// Реализации методов
void products::change_cost(float newcost) {
    setCost(newcost);
    std::wcout << L"Меняем цену!" << std::endl;
}

void products::show_products() {
    std::wcout << L"Имя: "; std::cout << getName() << std::endl;
    std::wcout << L"Количество: "; std::cout << getQuantity() << std::endl;
    std::wcout << L"Стоимость: "; std::cout << getCost() << std::endl;
};

// Реализации перегруженных операторов
std::ostream& operator<<(std::ostream& os, const products& p) {
    os << p.name << " " << p.quantity << " " << p.cost;
    return os;
}

std::istream& operator>>(std::istream& is, products& p) {
    is >> p.name >> p.quantity >> p.cost;
    return is;
}

// Реализации деструктора
products::~products() { std::wcout << L"Удаляем!" << std::endl; }
#include "products.h"
#include <fstream>
#include <iostream>

int main() {
    // Тест
    products items[5] = {
        {"milk", 10, 85.5},
        {"bread", 15, 45.0},
        {"cheese", 8, 320.0},
        {"eggs", 30, 65.0},
        {"butter", 12, 120.0}
    };
    
    std::ofstream file("products.dat", std::ios::binary);
    
    if (!file) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }
    
    // Запись
    for (int i = 0; i < 5; i++) {
        file.write((char*)&items[i], sizeof(products));
    }
    
    file.close();
    
    // Размер
    std::ifstream check("products.dat", std::ios::binary | std::ios::ate);
    std::streamsize size = check.tellg();
    check.close();
    
    std::cout << "Записано объектов: 5" << std::endl;
    std::cout << "Размер файла: " << size << " байт" << std::endl;
    std::cout << "Размер одного объекта: " << sizeof(products) << " байт" << std::endl;
    
    return 0;
}
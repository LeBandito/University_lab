/*5. Даны натуральное число n и вещественный массив  из n элементов. 
Перед каждым элементом с отрицательным значением вставить элемент, 
равный абсолютной величине отрицательного элемента. Если массив не 
содержит ни одного отрицательного элемента, выдать об этом сообщение.*/

#include <iostream>
#include <vector>

int main() {
    // std::vector<double> d = 
    //     {-2.5576, 100.32, -7733.8474, 47822,
    //     647928.3492, -687.32,284, 4902, -23};
    
    std::vector<double> d = 
        {2.5576, 100.32, 7733.8474, 47822,
        647928.3492, 687.32,284, 4902, 23};
        
    std::vector<double> c = {};
    
    bool flag = true;
    for (int i = 0; i < d.size(); ++i) {
        if (d[i] < 0) {
            c.push_back(-d[i]);
            c.push_back(d[i]);
            flag = false;
        } else {
            c.push_back(d[i]);
        }
    }
    
    for (int i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    
    if (flag) 
        std::cout << "\nNo any negative elements!" << std::endl;
        
    return 0;
}
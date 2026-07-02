/*5.	Написать программу для учета кадров видео-потока с использованием deque 
для хранения и обработки списка кадров с возможностью добавления и удаления как 
первого, так и последнего кадра.*/

#include <iostream>
#include <deque>

int main() {
    std::deque<int> arr = {1, 2, 3, 4, 5, 6};
    
    int k(0);
    while (k != 9) {
        std::cout << "What?" << std::endl;
        std::cout << "1) Show all deque." << std::endl;
        std::cout << "2) Add start." << std::endl;
        std::cout << "3) Add finish." << std::endl;
        std::cout << "4) Delete start." << std::endl;
        std::cout << "5) Delete finish." << std::endl;
        std::cout << "6) Add." << std::endl;
        std::cout << "7) Delete." << std::endl;
        std::cout << "8) Search." << std::endl;
        std::cout << "9) Exit." << std::endl; 
        std::cin >> k;
        std::cin.ignore();   
        
        if (k == 1) {
            for (const int& i : arr)
                std::cout << i << " ";
            std::cout << std::endl;
        } else if (k == 2) {
            std::cout << "Enter: ";
            int vrem;
            std::cin >> vrem;
            arr.push_front(vrem);
        } else if (k == 3) {
            std::cout << "Enter: ";
            int vrem;
            std::cin >> vrem;
            arr.push_back(vrem);
        } else if (k == 4) {
            arr.pop_front();
        } else if (k == 5) {
            arr.pop_back();
        } else if (k == 6) {
            std::cout << "Where? (0, 1, 2, ... , n)" << std::endl;
            int ind;
            std::cin >> ind;
            std::cin.ignore();
            std::cout << "What?" << std::endl;
            int vrem;
            std::cin >> vrem;
            
            auto it = arr.begin();
            for (int i = 0; i < ind; ++i) ++it;
            
            arr.insert(it, vrem);
        } else if (k == 7) {
            std::cout << "Where? (0, 1, 2, ... , n)" << std::endl;
            int ind;
            std::cin >> ind;
            std::cin.ignore();
            
            auto it = arr.begin();
            for (int i = 0; i < ind; ++i) ++it;
            
            arr.erase(it);
        } else if (k == 8) {
            std::cout << "What search?" << std::endl;
            int vrem;
            std::cin >> vrem;
            
            bool flag = true;
            int ind(1);
            for (const auto& i : arr) {
                if (i == vrem) {
                    std::cout << ind << ") " << i << "; ";
                    flag = false;
                }
                ++ind;
            }
            
            if (flag) 
                std::cout << "Not found!";
            
            std::cout << std::endl;
        } else if (k == 9) {
            std::cout << "Bye!" << std::endl;
        }
    }
    
    
    return 0;
}
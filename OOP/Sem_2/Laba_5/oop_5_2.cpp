/*5.	Написать программу для учета контактов, используя list для хранения 
списка контактов с возможностью добавления, удаления и поиска контактов.*/

#include <iostream>
#include <string>
#include <list>

struct PHONE {
    std::string NAME;
    std::string COMP;
    std::string NUM;
};

int main() {
    std::list<PHONE> P;
    
    int k(0);
    while (k != 5) {
        std::cout << "What?" << std::endl;
        std::cout << "1) Show all list." << std::endl;
        std::cout << "2) Add." << std::endl;
        std::cout << "3) Delete." << std::endl;
        std::cout << "4) Search" << std::endl;
        std::cout << "5) Exit." << std::endl;
        std::cin >> k;
        std::cin.ignore();
        
        if (k == 1) {
            for (const PHONE& i : P)
                std::cout << i.NAME << " | " << i.COMP << " | " << i.NUM << std::endl;
        } else if (k == 2) {
            int l(0);
            std::cout << "Where? (0,1,2...n?)" << std::endl;
            std::cin >> l;
            std::cin.ignore();
            PHONE vrem;
            std::cout << "What? (name company number)" << std::endl;
            std::getline(std::cin, vrem.NAME);
            std::getline(std::cin, vrem.COMP);
            std::getline(std::cin, vrem.NUM);
            
            auto it = P.begin();
            for (int i = 0; i < l; ++i) ++it;
            
            P.insert(it, vrem);
        } else if (k == 3) {
            int l(0);
            std::cout << "Where? (0,1,2...n?)" << std::endl;
            std::cin >> l;
            std::cin.ignore();
            
            auto it = P.begin();
            for (int i = 0; i < l; ++i) ++it;
            
            P.erase(it);
        } else if (k == 4) {
            PHONE vrem;
            std::cout << "What search? (name company number)" << std::endl;
            std::getline(std::cin, vrem.NAME);
            std::getline(std::cin, vrem.COMP);
            std::getline(std::cin, vrem.NUM);
            
            bool real = false;
            int idx(0);
            for (const PHONE& i : P) {
                bool check = true;
                if (((!vrem.NAME.empty()) && (i.NAME != vrem.NAME)) || 
                    ((!vrem.COMP.empty()) && (i.COMP != vrem.COMP)) ||
                    ((!vrem.NUM.empty()) && (i.NUM != vrem.NUM))) 
                    check = false;
                
                if (check) {
                    std::cout << idx << ") " << 
                    i.NAME << " " << i.COMP << " " << i.NUM << std::endl;
                    real = true;
                }
                
                ++idx;
            }
            if (!real) 
                std::cout << "Not found!" << std::endl;
        } else if (k == 5) {
            std::cout << "Bye!" << std::endl;
        }
    }
    
    return 0;
}

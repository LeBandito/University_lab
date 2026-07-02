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
    
    int k;
    
    while (true) {
        std::cout << "What?" << std::endl;
        std::cout << "0) Show all list." << std::endl;
        std::cout << "1) Add." << std::endl;
        std::cout << "2) Delete." << std::endl;
        std::cout << "3) Search." << std::endl;
        std::cout << "4) Exit." << std::endl;
        std::cin >> k;
        
        if (k == 0) {
            int l = 0;
            for (PHONE i : P)
                std::cout << l << ") " << i.NAME << " " << i.COMP << " " << i.NUM << std::endl;
        }
        
        if (k == 1) {
            int l;
            std::cout << "Where? (example 0...n)" << std::endl;
            std::cin >> l;
            
            PHONE vrem;
            std::cout << "What? (name company number)" << std::endl;
            std::cin >> vrem.NAME >> vrem.COMP >> vrem.NUM;
            // std::getline(std::cin, vrem.NAME);
            // std::getline(std::cin, vrem.COMP);
            // std::getline(std::cin, vrem.NUM);
            
            auto it = P.begin();
            // for (int i = 0; i < l; ++i) ++it;
            advance(it, l);
            P.insert(it, vrem);
        }
        
        if (k == 2) {
            int l;
            std::cout << "Where? (example 0...n)" << std::endl;
            std::cin >> l;
            
            auto it = P.begin();
            advance(it, l);
            P.erase(it);
        }
        
        if (k == 3) {
            PHONE vrem;
            std::cout << "What search? (name company number)" << std::endl;
            std::getline(std::cin, vrem.NAME);
            std::getline(std::cin, vrem.COMP);
            std::getline(std::cin, vrem.NUM);
            
            bool found = false;
            int idx = 0;
            for (const PHONE& l : P) {
                bool match = true;
                if ((!vrem.NAME.empty()) && (vrem.NAME != l.NAME)) match = false;
                if ((!vrem.COMP.empty()) && (vrem.COMP != l.COMP)) match = false;
                if ((!vrem.NUM.empty()) && (vrem.NUM != l.NUM)) match = false;
                
                if (match) {
                    std::cout << idx << ") " << l.NAME << " " 
                              << l.COMP << " " << l.NUM << std::endl;
                    found = true;
                }
                idx++;
            }
            if (!found)
                std::cout << "Not found." << std::endl;
            }
            
            if (k == 4) {
                break;
            }
    }
    
    return 0;
}
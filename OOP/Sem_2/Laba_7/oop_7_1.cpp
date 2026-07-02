/*5.	Создать программу для организации турнира по настольному теннису 
с использованием контейнера multiset для ранжирования игроков по результатам матчей.*/

#include <iostream>
#include <string>
#include <set>

struct PLAY {
    std::string name;
    int points;
    
    bool operator<(const PLAY& other) const {
        if (points != other.points) {
            return points > other.points;
        }
        return name < other.name;
    }
};

int main() {
    std::multiset<PLAY> arr = {{"Ben", 12}, {"Bruh", 15}, {"BomBomBom", 7}};
    
    int k(0);
    while (k != 4) {
        std::cout << "What?" << std::endl;
        std::cout << "1) Show all." << std::endl;
        std::cout << "2) Add." << std::endl;
        std::cout << "3) Delete." << std::endl;
        std::cout << "4) Exit." << std::endl;
        std::cin >> k;
        std::cin.ignore();
        
        if (k == 1) {
            int ind(1);
            for (const PLAY t : arr) {
                std::cout << ind << ") " << t.name << " - " << t.points << std::endl;
                ++ind;
            }
        } else if (k == 2) {
            PLAY vrem;
            std::cout << "What? (name points)" << std::endl;
            std::cin >> vrem.name;
            std::cin >> vrem.points;
            
            arr.insert(vrem);
        } else if (k == 3) {
            int ind(0);
            std::cout << "Where?" << std::endl;
            std::cin >> ind;
            
            auto it = arr.begin();
            for (int i = 0; i < ind - 1; ++i) ++it;
            arr.erase(it);
        } else if (k == 4) {
            std::cout << "Bye..." << std::endl;
        }
    }
    
    return 0;
}
/*
5.	Написать программу для хранения и отображения рейтинга футбольных команд, 
где каждой команде соответствует количество очков, с использованием контейнера map.
*/

#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> arr = {
        {"Barcelona", 82},
        {"RealMadrid", 88},
        {"Liverpool", 79}
    };

    int k(0);

    while (k != 5) {
        std::cout << "What?" << std::endl;
        std::cout << "1) Show all." << std::endl;
        std::cout << "2) Add." << std::endl;
        std::cout << "3) Delete." << std::endl;
        std::cout << "4) Search." << std::endl;
        std::cout << "5) Exit." << std::endl;

        std::cin >> k;
        std::cin.ignore();

        if (k == 1) {
            int ind(1);

            for (const auto& t : arr) {
                std::cout << ind << ") " << t.first << " - " << t.second << " points" << std::endl;
                ++ind;
            }
        } else if (k == 2) {
            std::string name;
            int points;

            std::cout << "What? (name points)" << std::endl;

            std::cin >> name;
            std::cin >> points;

            arr[name] = points;
        } else if (k == 3) {
            std::string name;

            std::cout << "Team name?" << std::endl;
            std::cin >> name;

            arr.erase(name);
        } else if (k == 4) {
            std::string name;

            std::cout << "Team name?" << std::endl;
            std::cin >> name;

            auto it = arr.find(name);

            if (it != arr.end()) {
                std::cout << it->first << " - " << it->second << " points" << std::endl;
            } else {
                std::cout << "Not found!" << std::endl;
            }
        } else if (k == 5) {
            std::cout << "Bye..." << std::endl;
        }
    }

    return 0;
}
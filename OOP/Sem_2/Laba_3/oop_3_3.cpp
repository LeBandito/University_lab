#include <iostream>
#include <string>

struct NOTE {
    std::string NAME;
    std::string TELE;
    std::string GROUP;
    int BDAY[3];
};

/*
Boris
8(800)555-35-35
Total
1 1 2000
*/

int main() {
    NOTE BLOCKNOTE[8];

    for (int i = 0; i < 8; i++) {
        std::cout << "Enter name: ";
        std::getline(std::cin, BLOCKNOTE[i].NAME);

        std::cout << "Enter phone: ";
        std::getline(std::cin, BLOCKNOTE[i].TELE);

        std::cout << "Enter group: ";
        std::getline(std::cin, BLOCKNOTE[i].GROUP);

        std::cout << "Enter birthday (day month year): ";
        std::cin >> BLOCKNOTE[i].BDAY[0]
            >> BLOCKNOTE[i].BDAY[1]
            >> BLOCKNOTE[i].BDAY[2];
        std::cin.ignore();
    }

    std::string search;
    std::cout << "Enter phone to search: ";
    std::getline(std::cin, search);

    bool found = false;

    for (int i = 0; i < 8; i++) {
        if (BLOCKNOTE[i].TELE == search) {
            std::cout << "Name: " << BLOCKNOTE[i].NAME << std::endl;
            std::cout << "Group: " << BLOCKNOTE[i].GROUP << std::endl;
            std::cout << "Birthday: "
                << BLOCKNOTE[i].BDAY[0] << "."
                << BLOCKNOTE[i].BDAY[1] << "."
                << BLOCKNOTE[i].BDAY[2] << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Contact not found!" << std::endl;
    }

    return 0;
}
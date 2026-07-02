/*5.	Дан файл, содержащий числа. 
Найти в нем минимальное и максимальное число и записать их в другой файл.*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

void In(std::fstream& f, std::fstream& g) {
    f.open("bruh.txt", std::ios::in);
    g.open("BomBomBom.txt", std::ios::out);
}

void AddData(std::fstream& f, std::vector<int>& arr) {
    std::string words;
    std::string vrem;

    while (std::getline(f, words)) {
        vrem = "";

        for (int i = 0; i < words.size(); i++) {
            if (isdigit(words[i])) {
                vrem.push_back(words[i]);
            }

            else if (!vrem.empty()) {
                arr.push_back(std::stoi(vrem));
                vrem = "";
            }
        }
        
        if (!vrem.empty()) {
            arr.push_back(std::stoi(vrem));
        }
    }
}

void SearchNumbers(std::fstream& g, std::vector<int> arr) {
    int Min = arr[0];
    int Max = arr[0];

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= Min)
            Min = arr[i];

        else if (arr[i] >= Max)
            Max = arr[i];
    }

    std::cout << "Max: " << Max << "\nMin: " << Min << std::endl;
    
    g << Max << " " << Min;
}

int main() {
    std::fstream f, g;
    std::vector<int> arr;

    In(f, g);

    AddData(f, arr);

    SearchNumbers(g, arr);

    return 0;
}
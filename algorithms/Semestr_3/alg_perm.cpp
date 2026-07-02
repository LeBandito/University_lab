/*5. Имеется N коробок разной емкости и формы. Имеется также два автомата, 
соединенных в технологическую линию. Первый – заполняет коробки, а второй – упаковывает. 
Время заполнения и упаковки коробок каждого типа различно. Необходимо найти такой порядок 
подачи коробок на конвейер, при котором время их обработки будет минимальным.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void InData(std::vector<std::vector<int>>& boxes) {
    std::vector<int> boom;
    
    std::string words;
    std::wcout << L"Введите значения коробок: " << std::endl;
    std::getline(std::cin, words);
    
    std::string vrem;
    
    int check(0);
    
    for (int i = 0; i < words.size(); i++) {
        if (words[i] != ' ') {
            vrem.push_back(words[i]);
        } 
        if (words[i] == ' ') {
            boom.push_back(stoi(vrem));
            vrem = "";
            check += 1;
        } 
        if (check == 2) {
            boxes.push_back(boom);
            boom.clear();
            check = 0;
        }
    }
    
    if (!vrem.empty()) {
        boom.push_back(stoi(vrem));
        boxes.push_back(boom);
        boom.clear();
    }
}

int whatTime(std::vector<std::vector<int>>& boxes) {
    int time(boxes[0][0]);
    
    for (int i = 0; i < boxes.size() - 1; i++) {
        if (boxes[i + 1][0] >= boxes[i][1]) {
            time += boxes[i + 1][0];
        } else {
            time += boxes[i][1];
        }
    }
    
    time += boxes[boxes.size() - 1][1];
    
    return time;
}

int minimum(std::vector<int> absolute) {
    int opa = 0;
    
    for (int i = 0; i < absolute.size(); i++) {
        if (absolute[opa] > absolute[i]) 
            opa = i;
    }
    
    return opa;
}

void mainSearch(std::vector<std::vector<int>> boxes) {
    std::vector<std::vector<std::vector<int>>> BomBom;
    std::vector<int> absolute;
    
    std::sort(boxes.begin(), boxes.end());
    
    do {
        BomBom.push_back(boxes);
    } while(std::next_permutation(boxes.begin(), boxes.end()));
    
    for (int i = 0; i < BomBom.size(); i++) {
        std::wcout << L"Перестановка " << i + 1 << ": | ";
        
        for (int j = 0; j < BomBom[i].size(); j++) {
            for (int k = 0; k < BomBom[i][j].size(); k++) {
                std::cout << BomBom[i][j][k] << " ";
            }
            
            std::cout << "| ";
        }
        
        std::cout << "--- " << whatTime(BomBom[i]) << std::endl;
        
        absolute.push_back(whatTime(BomBom[i]));
    }
    
    int min = minimum(absolute);
    
    std::wcout << L"Комбинация с минимальными временем это: \n| ";
    
    for (int i = 0; i < BomBom[min].size(); i++) {
        for (int j = 0; j < BomBom[min][i].size(); j++) {
            std::cout << BomBom[min][i][j] << " ";
        }
        std::cout << "| ";
    }
    
    std::wcout << L"\nВремя необходимое для выполнения этой комбинации: " << std::endl;
    std::cout << absolute[min] << std::endl;
}

// 2 5 3 1 7 10 1 1 2 8

int main() {
    setlocale(LC_ALL, "");
    std::vector<std::vector<int>> boxes;
    
    InData(boxes);
    
    // std::wcout << L"Время данной комбинации: ";
    // std::cout << whatTime(boxes) << std::endl;
    
    mainSearch(boxes);
    
    return 0;
}
/*5.  Дано N резисторов с номиналом Ri. Необходимо составить из них последовательную цепь, 
сопротивление которой будет максимально близким к заданному R0.*/

#include <iostream>
#include <string>
#include <vector>

void InData(std::vector<int>& values) {
    std::string words;
    std::wcout << L"Введите N резисторов: " << std::endl;
    std::getline(std::cin, words);
    
    std::string vrem;
    
    for (int i = 0; i < words.size(); i++) {
        if (words[i] != ' ') {
            vrem.push_back(words[i]);
        } else {
            values.push_back(stoi(vrem));
            vrem = "";
        }
    }
    
    if (!vrem.empty())
        values.push_back(stoi(vrem));
}

void allCombination(std::vector<std::vector<int>>& all, const std::vector<int>& values) {
    for (int mask = 0; mask < (1 << values.size()); mask++) {
        std::vector<int> current;
        
        for (int i = 0; i < values.size(); i++) {
            if (mask & (1 << i))
                current.push_back(values[i]);
        }
        
        all.push_back(current);
    }
}

void calculating(int n, const std::vector<int>& values) {
    std::vector<std::vector<int>> all;
    allCombination(all, values);
    
    std::vector<int> booom;
    
    for (int i = 0; i < (all.size()); i++) {
        for (int j = 0; j < (all[i].size()); j++) {
            std::cout << all[i][j] << " ";
        }
        
        std::cout << std::endl;
    }
    
    int vrem(0);
    
    for (int i = 0; i < (all.size()); i++) {
        for (int j = 0; j < (all[i].size()); j++) {
            vrem += all[i][j];
        }
        
        booom.push_back(n - vrem);
        
        vrem = 0;
    }
    
    std::wcout << L"Варианты: " << std::endl;
    
    for (int i = 0; i < (booom.size()); i++) {
        std::cout << booom[i] << " ";
    }
    
    int minn(0);
    
    for (int i = 0; i < (booom.size()); i++) {
        // ((booom[minn] > booom[i]) && (booom[minn] >= 0) && (booom[i] >= 0))
        if (abs(booom[minn]) > abs(booom[i]))
            minn = i;
    }
    
    std::cout << "\n" << minn << " " << booom[minn];
    
    std::wcout << L"\nНужное число: ";
    std::cout << n;
    
    std::wcout << L"\nПодходящая комбинация: ";
    
    for (int i = 0; i < (all[minn].size()); i++) {
        std::cout << all[minn][i] << " ";
    }    
}

// 7 1 3 4 5 6
// 15 1 7 6 8 12
// 60 94 43 94 6 86 88 44 71 37 67

int main() {
    setlocale(LC_ALL, "");
    int num;
    std::wcout << L"Введите R0: " << std::endl;
    std::cin >> num;
    std::cin.ignore();

    std::vector<int> values;
    InData(values);
    
    calculating(num, values);
    
    return 0;
}

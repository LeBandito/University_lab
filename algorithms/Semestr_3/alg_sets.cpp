/*5.	Дано N резисторов с номиналом Ri. Необходимо составить из них последовательную цепь, 
сопротивление которой будет максимально близким к заданному R0.*/
/* Old vt chuvsu */ 

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

struct BestResult {
    int sum;
    int difference;
    std::vector<int> used_resistors;
};

void findClosestSum(int R0, const std::vector<int>& resistors, 
                   int index, int currentSum, 
                   std::vector<int>& currentUsed,
                   BestResult& best) {
    
    int diff = std::abs(R0 - currentSum);
    
    if (diff < best.difference) {
        best.sum = currentSum;
        best.difference = diff;
        best.used_resistors = currentUsed;
    }
    
    if (diff == 0) return;
    
    for (int i = index; i < resistors.size(); i++) {
        currentUsed.push_back(resistors[i]);
        findClosestSum(R0, resistors, i + 1, currentSum + resistors[i], currentUsed, best);
        currentUsed.pop_back();
    }
}

int main() {
    setlocale(LC_ALL, "");
    int R0 = 15;
    std::vector<int> resistors = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    BestResult best;
    best.difference = INT_MAX;
    best.sum = 0;
    
    std::vector<int> currentUsed;
    
    findClosestSum(R0, resistors, 0, 0, currentUsed, best);
    
    std::cout << "R0: " << R0 << std::endl;
    std::wcout << L"Найденная сумма: " << best.sum << std::endl;
    std::wcout << L"Разница: " << best.difference << std::endl;
    std::wcout << L"Использованные резисторы: ";
    
    for (int r : best.used_resistors) {
        std::cout << r << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}

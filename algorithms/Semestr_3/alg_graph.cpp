/* 5.  Обратное N-дерево 
            O
       O  O |
        \ | O
O  O  O  \|/
 \ |  |   O
   O  O  /
    \ | /
      O
      
      O
    / | \
   O  O  \
 / |  |   O
O  O  O  /|\
        / | O
       O  O |
            O
В узлах дерева находятся некоторые числа. Определить значение корневого элемента. 
Вычисления производятся по следующим правилам: 
1. Расчет начинается с терминальных элементов и их половинное значение добавляется 
    к значению связанного с ними узла;
2. Когда к значению некоторого узла будут добавлены необходимые значения всех терминальных 
    элементов, то данный узел начинает рассматриваться как терминальный и повторяется шаг 1.
3. Вычисления заканчиваются тогда, когда корень дерева станет терминальным. 
    1)        O
           / |    \
    2)    O  O     O
        / |  |   / | \
    3) O  O  O  O  O  O 
                      |
    4)                O   
   
    1)        1
           / |    \
    2)    2  3     4
        / |  |   / | \
    3) 5  6  7  8  9  10 
                       |
    4)                11    
   
{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}   */
   
#include <iostream>
#include <string>
#include <vector>

void InData(std::vector<int>& arr) {
    std::string words;
    std::wcout << L"Введите значения вершин: " << std::endl;
    
    std::getline(std::cin, words);
    
    std::string vrem;
        
    for (int i = 0; i < words.size(); i++) {
        if (words[i] != ' ') {
            vrem.push_back(words[i]);
        } else {
            arr.push_back(stoi(vrem));
            vrem = "";
        }
    }
    
    if (!vrem.empty())
        arr.push_back(stoi(vrem));
}

bool isLeaf(int node, const std::vector<std::vector<bool>>& tree) {
    for (int i = 0; i < tree[node].size(); i++) {
        if (tree[node][i]) {
            return false;
        }
    }
    
    return true;
}

double calculateNode(int node, const std::vector<std::vector<bool>>& tree, const std::vector<int>& values) {
    if (isLeaf(node, tree)) {
        return values[node];
    }
    
    double sum = values[node];
    
    for (int i = 0; i < tree[node].size(); i++) {
        if (tree[node][i]) {
            double childValue = calculateNode(i, tree, values);
            sum += childValue / 2;
        }
    }
    
    return sum;
}

// 1 2 3 4 5 6 7 8 9 10 11
// 100 100 100 100 100 100 100 100 100 100 100

int main() {
    setlocale(LC_ALL, "");
    std::vector<std::vector<bool>> tree = 
    {{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
     {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, 
     {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, 
     {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0}, 
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    std::vector<int> arr;
    InData(arr);
    
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    std::wcout << L"Итого: ";
    std::cout << calculateNode(0, tree, arr) << std::endl;
    
    return 0;
}

/*5.  Совместные множества
Задано N товаров (примерный перечень: Milk, Sour Cream, Kefir, Cheese, 
Yogurt, Ryazhenka, Black bread, White bread, Meat, Sausage, Fish, Chicken, Turkey, 
Sweets, Cookies, Chocolate, Marmalade, Marshmallows, Vegetables, Fruits, Alcohol, Tobacco) 
и массив покупок (размерности M). В одной покупке может быть несколько товаров из списка. 
Произвести разделение товаров на группы, в которые включены товары, наиболее часто покупаемые совместно.*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

void plusOne(std::string& numStr) {
    bool flag = true;

    for (int i = numStr.size() - 1; i >= 0 && flag; --i) {
        if (numStr[i] == '1') {
            numStr[i] = '0';
        }

        else {
            numStr[i] = '1';
            flag = false;
        }
    }

    if (flag) {
        numStr = '1' + numStr;
    }
}

std::vector<std::string> getCombinationWithMask(std::vector<std::string>& buying, std::string& mask) {
    std::vector<std::string> combination;

    for (int i = 0; i < mask.size(); ++i) {
        if (mask[i] == '1') {
            combination.push_back(buying[i]);
        }
    }

    return combination;
}

std::vector<std::vector<std::string>> getAllCombinationInBuying(std::vector<std::string> buying) {
    const std::size_t vecSize = buying.size();

    std::string numStr(vecSize, '0'), numFinish(vecSize, '1'); //00000 11111
    plusOne(numStr);

    std::vector<std::vector<std::string>> allCombinationInBuying;

    while (numStr != numFinish) {
        allCombinationInBuying.push_back(getCombinationWithMask(buying, numStr));
        plusOne(numStr);
    }

    allCombinationInBuying.push_back(getCombinationWithMask(buying, numStr));

    return allCombinationInBuying;
}

int main() {
    std::vector<std::vector<std::string>> buyings = {
        {"Milk", "Sour cream", "Yogurt", "White bread", "Biscuits"},
        {"Milk", "Sour cream", "Kefir", "White bread", "Chocolate"},
        {"Milk", "Sour cream", "Yogurt", "White bread", "Sweets"},
        {"Milk", "Sour cream", "Yogurt"}
    };

    std::map<std::vector<std::string>, int> mapCombinationAllBuyings;

    for (int i = 0; i < buyings.size(); ++i) {
        std::vector<std::vector<std::string>> allCombinationPurchasing = getAllCombinationInBuying(buyings[i]);

        for (auto& comb : allCombinationPurchasing) {
            mapCombinationAllBuyings[comb]++;
        }
    }

    //std::pair<std::vector<std::string>, int> combinationProducts
    
    for (const auto& combinationProducts : mapCombinationAllBuyings) {
        if (combinationProducts.second > 1 && combinationProducts.first.size() > 1) {
            std::cout << "Products: ";

            for (const auto& prod : combinationProducts.first) {
                std::cout << prod << " | ";
            }

            std::cout << combinationProducts.second << std::endl;
        }
    }
}

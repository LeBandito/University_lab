/*Открыть текстовый файл в необходимом режиме (на чтение, на чтение и запись, на добавление). 
(В файле должно быть не менее 30 строк). Найти самую длинную строку текста и заменить её 
пустой строкой. Записать измененный текст в новый файл.*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    std::string line;
    std::vector<std::string> words;
    
    while (std::getline(in, line)) {
        words.push_back(line);
    }
    
    int MaxSizeIndex = 0;    
    for (int i = 0; i < words.size(); ++i) {
        if (words[MaxSizeIndex].size() < words[i].size()) {
            MaxSizeIndex = i;
        }
    }
    
    words[MaxSizeIndex] = "";
    
    for (int i = 0; i < words.size(); ++i) {
        out << words[i] << std::endl;
    }
    
    in.close();
    out.close();
    
    return 0;
}
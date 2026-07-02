#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void BumIn(std::fstream& f) {
    f.open("BumBumBum.txt", std::ios::in);
}

void BumOut(std::fstream& g) {
    g.open("DataBum.dat", std::ios::out | std::ios::binary);
}

struct word {
    char word1[100];
    char word2[100];
};

void InData(std::fstream& f, std::vector<word>& BomDataBum) {
    std::string words;
    
    while (std::getline(f, words)) {        
        word vrem;
        
        for (int i = 0; i < 100; i++) {
            vrem.word1[i] = 0;
            vrem.word2[i] = 0;
        }
        
        int i(0), j(0), k(0);
        
        while ((i < words.size()) && (words[i] != ' ') && (i < 99)) {
            vrem.word1[i] = words[i];
            i++;
        }
        vrem.word1[i] = '\0';
        
        // " - "
        j = i + 3;
        
        while ((j < words.length()) && (k < 99)) {
            vrem.word2[k] = words[j];
            j++;
            k++;
        }
        vrem.word2[k] = '\0';
        
        BomDataBum.push_back(vrem);
    }
}

void transfer(std::vector<word>& BomDataBum, std::fstream& g) {
    for (int i = 0; i < BomDataBum.size(); i++) {
        g.write((char*)&BomDataBum[i], sizeof(word));
    }
}

int main() {
    setlocale(LC_ALL, "");
    std::fstream f;
    BumIn(f);
    
    std::vector<word> BomDataBum;
    InData(f, BomDataBum);
    
    std::fstream g;
    BumOut(g);
    
    transfer(BomDataBum, g);
    
    f.close();
    g.close();
    return 0;
}
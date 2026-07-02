/*5.	Кенгуру
На узенькой дорожке встречаются две семьи кенгуру (по N кенгуру в каждой семье). 
Между ними одно пустое место. Кенгуру могут либо передвинуться на пустое перед собой место, 
либо перепрыгнуть через «чужое» кенгуру на пустое мест сзади него. Прыгать через своих нельзя. 
Необходимо найти последовательность прыжков, в результате которых семьи продолжат свой путь.
Например: 
    начальная позиция:  >>>  <<<
    конечная позиция: <<<  >>>      */

#include <iostream>
#include <string>

void InData(std::string& kan) {
    std::wcout << L"Кенгуру: " << std::endl;
    std::getline(std::cin, kan);
}

std::string Final(std::string kan) {
    int Tuda(0), Suda(0);
    
    for (int i = 0; i < kan.size(); i++) {
        if (kan[i] == '>')
            Tuda += 1;
        
        else if (kan[i] == '<')
            Suda += 1;
    }
    
    return std::string(Suda, '<') + " " + std::string(Tuda, '>');
}

bool OnlyWalk(std::string kan) {
    for (int i = 0; i < kan.size(); i++) {
        if ((kan[i] == '>') && (kan[i + 1] == ' ') && (kan[i + 2] == '<')) {
            if (i + 1 < (kan.size() / 2)) {
                return false;
            }
            
            else if ((i + 1 > (kan.size() / 2))) {
                return false;
            }
        }
        
        else if ((kan[i] == ' ') && (kan[i + 1] == '>') && (kan[i + 2] == '<')) {
            return false;
        }
        
        else if ((kan[i] == '>') && (kan[i + 1] == '<') && (kan[i + 2] == ' ')) {
            return false;
        }
        
        else if ((kan[i] == ' ') && (i == kan.size() - 1)) {
            if (kan[i - 1] == '>') {
                return false;
            }
            
            else if ((kan[i - 2] == '>') && (kan[i - 1] == '<')) {
                return false;
            }
        }
        
        else if ((kan[i] == ' ') && (i == 0)) {
            if (kan[i + 1] == '<') {
                return false;
            }
            
            else if ((kan[i + 2] == '<') && (kan[i + 1] == '>')) {
                return false;
            }
        }
    }
    
    return true;
}

void BomBomBOOOM(std::string finality, std::string kan) {
    int step = 0;
    
    int bam = 0;
    
    // while (bam != 20) {
    while (kan != finality) {
        for (int i = 0; i < kan.size(); i++) {
            if ((kan[i] == '>') && (kan[i + 1] == ' ') && (kan[i + 2] == '<')) {
                if ((i + 1 < (kan.size() / 2)) || (step == 0)) {
                    kan[i] = ' ';
                    kan[i + 1] = '>';
                    kan[i + 2] = '<';
                    step += 1;
                    break;
                }
                
                else if ((i + 1 > (kan.size() / 2))) {
                    kan[i] = '>';
                    kan[i + 1] = '<';
                    kan[i + 2] = ' ';
                    step += 1;
                    break;
                }
            }
            
            else if ((kan[i] == ' ') && (kan[i + 1] == '>') && (kan[i + 2] == '<')) {
                kan[i] = '<';
                kan[i + 1] = '>';
                kan[i + 2] = ' ';
                step += 1;
                break;
            }
            
            else if ((kan[i] == '>') && (kan[i + 1] == '<') && (kan[i + 2] == ' ')) {
                kan[i] = ' ';
                kan[i + 1] = '<';
                kan[i + 2] = '>';
                step += 1;
                break;
            }
            
            else if ((kan[i] == ' ') && (i == kan.size() - 1)) {
                if (kan[i - 1] == '>') {
                    kan[i - 1] = ' ';
                    kan[i] = '>';
                    step += 1;
                    break;
                }
                
                else if ((kan[i - 2] == '>') && (kan[i - 1] == '<')) {
                    kan[i - 2] = ' ';
                    kan[i] = '>';
                    step += 1;
                    break;
                }
            }
            
            else if ((kan[i] == ' ') && (i == 0)) {
                if (kan[i + 1] == '<') {
                    kan[i + 1] = ' ';
                    kan[i] = '<';
                    step += 1;
                    break;
                }
                
                else if ((kan[i + 2] == '<') && (kan[i + 1] == '>')) {
                    kan[i + 2] = ' ';
                    kan[i] = '<';
                    step += 1;
                    break;
                }
            }
            
            else if (OnlyWalk(kan)) {
                if ((kan[i] == ' ') && (kan[i + 1] == '<')) {
                    kan[i] = '<';
                    kan[i + 1] = ' ';
                    step += 1;
                    break;
                }
                
                else if ((kan[i] == ' ') && (kan[i - 1] == '>')) {
                    kan[i] = '>';
                    kan[i - 1] = ' ';
                    step += 1;
                    break;
                }
            }
        }
        
        bam += 1;
        
        std::cout << bam << ") " << kan << std::endl;
    }
}

// >>> <<<

int main() {
    setlocale(LC_ALL, "");
    std::string kan;
    
    InData(kan);
    
    std::string finality = Final(kan);
    
    BomBomBOOOM(finality, kan);
    
    return 0;
}
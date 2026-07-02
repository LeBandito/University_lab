/*Получить от пользователя строку текста и подсчитать количество двойных пробелов. 
Вывести полученное значение на экран. 
Повторять до тех пор, пока не встретится строка завершающаяся словом quit*/

#include <iostream>
#include <string>

/*
a bcd  e   fghij k lmn op qr st  uv   wx yz
ab cd  e  fghij k  lmn op qr st   uvwx yz
abc d  e   fghij k  l  mn op qr st   uvwx yzquit
*/

int main() {
    std::string s;
    
    while (true) {
        std::getline(std::cin, s);
        int count = 0;
        std::string check;
        
        for (int i = 0; i < s.size() - 1; ++i) {
            if ((s[i] == ' ') && (s[i + 1] == ' '))
                ++count;
            
            if (i > s.size() - 5) {
                check += s[i];
            }
        }
        
        check += s[s.size() - 1];
        
        std::cout << count << std::endl;
        
        if (check == "quit") 
            break;
    }
    
    return 0;
}
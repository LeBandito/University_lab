/*5.	Написать программу, которая считывает английский текст из файла 
и записывает в другой файл только предложения, начинающиеся с гласных букв.*/

#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

void In(std::fstream& f){
   f.open("bobr1.txt", std::ios::in);
}

void Out(std::fstream& g){
   g.open("bobr2.txt", std::ios::out);
}

void SearchWords(std::fstream& f, std::fstream& g){
   int check = 0;

   std::string words;
   while (std::getline(f, words)) {
      int N = words.length();

      for (int i = 0; i < N; i++) {
         if ((words[i] != '!') && (words[i] != '?') && (words[i] != '.')) { 
            check += 1;
         }
         
         else {
            if (isspace(words[i - check])) {
               if ((tolower(words[i - check + 1]) == 'a') || (tolower(words[i - check + 1]) == 'e') ||
               (tolower(words[i - check + 1]) == 'i') || (tolower(words[i - check + 1]) == 'o') ||
               (tolower(words[i - check + 1]) == 'u')) {
                  g << " ";

                  for (int j = i - check + 1; j < i + 1; j++)
                     g << words[j];
               }
            }

            else {
               if ((tolower(words[i - check]) == 'a') || (tolower(words[i - check]) == 'e') ||
               (tolower(words[i - check]) == 'i') || (tolower(words[i - check]) == 'o') ||
               (tolower(words[i - check]) == 'u')) {
                  for (int j = i - check; j < i + 1; j++)
                     g << words[j];
               }
            }

            check = 0;            
         }
      }
      
      g << std::endl;
   }
}

int main() {
   std::fstream F;
   In(F);

   std::fstream G;
   Out(G);

   SearchWords(F, G);

   F.close();
   G.close();
   return 0;
}
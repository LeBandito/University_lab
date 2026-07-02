import requests
from bs4 import BeautifulSoup
import time

with open("C:\\code\\Chuvsu\\algoritms\\Semestr_3\\russian.txt", "r", encoding="windows-1251") as input_file\
    , open("C:\\code\\Chuvsu\\algoritms\\Semestr_3\\BumBumBum.txt", "w", encoding="utf-8") as output_file:
    for i, line in enumerate(input_file):
        word = line.strip()
        
        if i >= 1000:
            break
            
        response = requests.get("https://morphologyonline.ru/" + word)
        
        if response.status_code == 200:
            soup = BeautifulSoup(response.text, 'html.parser')
            morph_list = soup.find('ul', class_='list-morphy')
            
            if morph_list:
                first_li = morph_list.find('li')
                
                if first_li:
                    
                    full_text = first_li.get_text()
                    clean_text = full_text.replace("Начальная форма:", "").strip()
                    
                    if '(' in clean_text:
                        clean_text = clean_text.split('(')[0].strip()
                    
                    print(f"{word} – {clean_text}")
                    output_file.write(f"{word} – {clean_text}" + "\n")
        
        time.sleep(0.5)
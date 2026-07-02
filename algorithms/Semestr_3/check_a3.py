import os
import requests
from bs4 import BeautifulSoup as BS


# Скорее всего файл в windows-1251
with open("C:\\code\\Chuvsu\\algoritms\\Semestr_3\\russian.txt", "r", encoding="windows-1251") as file:
    word_count = 0
    for line in file:
        word = line.strip()
        word_count += 1
        while True:
            r = requests.get("https://morphologyonline.ru/" + word)
            html = BS(r.content, 'html.parser')
            items = html.select(".items > .list-morphy")
            
            if(len(items)):
                for i in items:
                    title = i.select('.caption > li')
                    print(title[0].text)
        #print(f"{word_count}: {word}")
    
    print(f"\nВсего слов: {word_count}")
import requests
from bs4 import BeautifulSoup
import time

def extract_base_form(li_element):
    """Извлекает чистую начальную форму из li элемента"""
    full_text = li_element.get_text()
    
    # Убираем "Начальная форма: " и пояснения в скобках
    clean_text = full_text.replace("Начальная форма: ", "").strip()
    if '(' in clean_text:
        clean_text = clean_text.split('(')[0].strip()
    
    return clean_text

# Открываем файлы
with open("C:\\code\\Chuvsu\\algoritms\\Semestr_3\\russian.txt", "r", encoding="windows-1251") as input_file, \
     open("BumBumBum.txt", "w", encoding="utf-8") as output_file:
    
    processed_count = 0
    success_count = 0
    
    for line in input_file:
        word = line.strip()
        
        # Обрабатываем только первые 50 слов для теста
        if processed_count >= 50:
            break
        
        try:
            response = requests.get("https://morphologyonline.ru/" + word, timeout=10)
            
            if response.status_code == 200:
                soup = BeautifulSoup(response.text, 'html.parser')
                morph_list = soup.find('ul', class_='list-morphy')
                
                if morph_list:
                    first_li = morph_list.find('li')
                    if first_li:
                        base_form = extract_base_form(first_li)
                        
                        # Формируем строку в нужном формате
                        result_line = f"{word} – {base_form}"
                        
                        # Записываем в файл
                        output_file.write(result_line + "\n")
                        
        except Exception as e:
            print(f"❌ {word} – ошибка: {e}")
        
        # Важная пауза между запросами
        time.sleep(1)
/*15.	На сайте фиксируется информация о времени захода и выхода каждого посетителя (часы: минуты). Сайт работает круглосуточно. 
Определить период/периоды времени, в течение которого/которых количество посетителей на сайте было максимально.*/
#include <iostream>
#include <vector>
#include <string>

struct Time {
    int Hour;
    int Minute;
};

struct TimePeople {
    Time First;
    Time Second;
};

void EnterData(std::vector<TimePeople>& people, std::vector<Time>& person) {
    std::vector<std::string> words;

    std::string word;
    std::cout << "Enter the people: " << std::endl;
    std::getline(std::cin, word);
    
    std::string vrem;

    for (int i = 0; i < word.size(); i++) {
        if (word[i] != ' ') 
            vrem.push_back(word[i]);

        else {
            words.push_back(vrem);
            vrem.clear();
        }
    }

    if (!vrem.empty()) 
        words.push_back(vrem);

    for (int i = 0; i < words.size(); i += 4) {
        TimePeople t = { { std::stoi(words[i]), std::stoi(words[i + 1]) }, { std::stoi(words[i + 2]), std::stoi(words[i + 3]) } };
        people.push_back(t);

        Time tt1 = { std::stoi(words[i]), std::stoi(words[i + 1]) };
        person.push_back(tt1);
        
        Time tt2 = { std::stoi(words[i + 2]), std::stoi(words[i + 3]) };
        person.push_back(tt2);
    }
}

bool CheckTime(Time A, Time B) {
    if (A.Hour > B.Hour)
        return 1;

    else if (A.Hour < B.Hour)
        return 0;
    
    else if (A.Hour == B.Hour) {
        if (A.Minute > B.Minute)
            return 1;

        else if (A.Minute < B.Minute)
            return 0;
    }

    return 0;
}

void bubbleSort(std::vector<Time>& person) {
    for (int i = 0; i < person.size(); i++) {
        for (int j = 0; j < person.size() - i - 1; j++) {
            if (CheckTime(person[j], person[j + 1])) {
                Time vrem = person[j];
                person[j] = person[j + 1];
                person[j + 1] = vrem;
            }
        }
    }

    for (int i = 0; i < person.size() - 1; i++) {
        if ((person[i].Hour == person[i + 1].Hour) && (person[i].Minute == person[i + 1].Minute)) {
            auto it = person.begin();
            person.erase(it  + i);
        }
    }
}

void CheckPerson(std::vector<TimePeople> People, std::vector<Time> Person, std::vector<int>& TimeLine) {
    for (int i = 0; i < Person.size() - 1; i++) {
        for (int j = 0; j < People.size(); j++) {
            if ((((People[j].First.Hour == Person[i].Hour) && (People[j].First.Minute <= Person[i].Minute)) || (People[j].First.Hour < Person[i].Hour)) &&
            (((People[j].Second.Hour == Person[i + 1].Hour) && (People[j].Second.Minute >= Person[i + 1].Minute)) || (People[j].Second.Hour > Person[i + 1].Hour)))
                TimeLine[i] += 1;
        }
    }
}

void Out(std::vector<Time> Person, std::vector<int> TimeLine) {
    int Max = TimeLine[0];
    
    for (int i = 0; i < TimeLine.size(); i++) {
        if (TimeLine[i] >= Max)
            Max = TimeLine[i];
    }

    std::cout << "\n\nMax people: " << std::endl;

    for (int i = 0; i < TimeLine.size(); i++) {
        if (TimeLine[i] == Max) {
            if (Person[i].Hour == 0)
                std::cout << "0" << Person[i].Hour << ":";
            
            else 
                std::cout << Person[i].Hour << ":";


            if (Person[i].Minute == 0)
                std::cout << "0" << Person[i].Minute << "-";
            
            else 
                std::cout << Person[i].Minute << "-";

            if (Person[i + 1].Hour == 0)
                std::cout << "0" << Person[i + 1].Hour << ":";
            
            else 
                std::cout << Person[i + 1].Hour << ":";


            if (Person[i + 1].Minute == 0)
                std::cout << "0" << Person[i + 1].Minute << " ---> ";
            
            else 
                std::cout << Person[i + 1].Minute << " ---> ";
            
            std::cout << TimeLine[i] << std::endl; 
        }
    }
}

// 11 00 17 15 12 00 13 30 12 45 16 20 14 40 17 00 13 00 18 00 13 30 17 20

int main() {
    std::vector<TimePeople> people;
    std::vector<Time> person;
    
    EnterData(people, person);

    std::cout << "\nPeople" << std::endl;
    
    for (int i = 0; i < people.size(); i++) {
        std::cout << "Person " << i + 1 << ": " << std::endl;
        std::cout << people[i].First.Hour << " " << people[i].First.Minute << " " << people[i].Second.Hour << " " << people[i].Second.Minute << std::endl;
    }

    std::cout << "\nIntervals: " << std::endl;

    bubbleSort(person);

    for (int i = 0; i < person.size(); i++) {
        std::cout << person[i].Hour << " " << person[i].Minute << std::endl;
    }
    
    std::vector<int> TimeLine(person.size() - 1);

    std::cout << "\nCoincidences: " << std::endl;

    CheckPerson(people, person, TimeLine);

    for (int i = 0; i < TimeLine.size(); i++) {
        std::cout << TimeLine[i] << " ";
    }

    Out(person, TimeLine);

    return 0;
}
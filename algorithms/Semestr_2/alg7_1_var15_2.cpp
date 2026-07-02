/*15.	На сайте фиксируется информация о времени захода и выхода каждого посетителя (часы: минуты). Сайт работает круглосуточно. 
Определить период/периоды времени, в течение которого/которых количество посетителей на сайте было максимально.*/
#include <iostream>
#include <string>
#include <vector>

struct Time {
    int First;
    int Second;
};

void InData(std::vector<std::string>& people) {
    std::string timelines;
    std::cout << "Enter timelines: " << std::endl;

    std::getline(std::cin, timelines);
    
    std::string timerInOut;

    for (int i = 0; i < timelines.size(); i++) {
        if (timelines[i] != ' ')
            timerInOut.push_back(timelines[i]);

        else {
            people.push_back(timerInOut);
            timerInOut.clear();
        }
    }

    if (!timerInOut.empty())
        people.push_back(timerInOut);
}

void BubbleSort(std::vector<int>& RightTime) {
    for (int i = 0; i < RightTime.size(); i++) {
        for (int j = 0; j < RightTime.size() - i - 1; j++) {
            if (RightTime[j] > RightTime[j + 1]) {
                int vrem = RightTime[j];
                RightTime[j] = RightTime[j + 1];
                RightTime[j + 1] = vrem;
            }
        }
    }

    for (int i = 0; i < RightTime.size() - 1; i++) {
        if (RightTime[i] == RightTime[i + 1]) {
            auto it = RightTime.begin();
            RightTime.erase(it + i);
        }
    }
}

void TruthTime(std::vector<int>& RightTime, std::vector<std::string> people) {
    for (int i = 0; i < people.size(); i += 2) {
        RightTime.push_back(std::stoi(people[i] + people[i + 1]));
    }
}

void CheckLines(std::vector<int> RightTime, std::vector<int> newPeople, std::vector<int>& lines) {
    for (int i = 0; i < RightTime.size() - 1; i++) {
        for (int j = 0; j < newPeople.size() - 1; j++) {
            if ((newPeople[j] <= RightTime[i]) && (newPeople[j + 1] >= RightTime[i + 1]))
                lines[i] += 1;
        }
    }
}

// 11 00 17 15 12 00 13 30 12 45 16 20 14 40 17 00 13 00 18 00 13 30 17 20

int main() {
    std::vector<std::string> people;
    InData(people);

    std::vector<int> rightTime, newPeople;
    TruthTime(rightTime, people);
    TruthTime(newPeople, people);
    BubbleSort(rightTime);

    std::cout << "Timelines: " << std::endl;
    for (int i = 0; i < people.size(); i++) {
        std::cout << people[i] << " ";
    }

    std::cout << "\nRightTime: " << std::endl;
    for (int i = 0; i < rightTime.size(); i++) {
        std::cout << rightTime[i] << " ";
    }

    std::vector<int> lines(rightTime.size() - 1);
    CheckLines(rightTime, newPeople, lines);

    std::cout << "\nLines: " << std::endl;
    for (int i = 0; i < lines.size(); i++) {
        std::cout << lines[i] << " ";
    }
    
    system("pause");

    return 0;
}
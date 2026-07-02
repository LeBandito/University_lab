/*5. На вокзале имеется M билетных касс. При покупке билетов возможны два варианта: покупается билет в пункт,
с которым есть прямое сообщение, и билет с пересадкой в пункт, с которым нет прямого сообщения. Время оформления
первого варианта билета вдвое меньше времени оформления второго варианта. Количество пассажиров, покупающих
билеты по обоим вариантам примерно одинаково. Время оформления билета по первому варианту составляет O минут.
Поток пассажиров задан в виде массива следующего формата:
P={T1,v1, T2,v2, … Tn,vn}, где Ti, vi - соответственно время подхода пассажира к кассе и вариант покупки.
Определить размер очереди через время Т0. */
#include <iostream>

void InData(int& n, int& m, int& t0, int& p, int& time) {
    std::cout << "Enter N: ";
    std::cin >> n;

    std::cout << "Enter M: ";
    std::cin >> m;

    std::cout << "Enter T0: ";
    std::cin >> t0;

    std::cout << "Enter P: ";
    std::cin >> p;

    std::cout << "Enter Time: ";
    std::cin >> time;
    
    std::cout << std::endl;
}

void In(int n, int m, int p, int time, int** passengers, int* boxOffice) {
    int ttt = 0;

    for (int i = 0; i < n; i++) {
        passengers[i][0] = ttt;

        ttt += p;
        
        passengers[i][1] = time;
    }

    // passengers[i][0] = ttt;
    // passengers[i][1] = 10;

    for (int j = 0; j < m; j++) {
        boxOffice[j] = 0;
    }
}

int FindQueue(int n, int m, int t0, int time, int** passengers, int* boxOffice, double& aTime) {
    int passL = 0;

    for (int i = 0; i < t0; i++) {
        for (int j = 0; j < m; j++) {
            if ((boxOffice[j] == 0) || (boxOffice[j] == i)) {
                for (int k = passL; k < n; k++) {
                    if (passengers[k][0] <= i) {
                        boxOffice[j] = i + passengers[k][1];
                        passL = k + 1;

                        break;
                    }
                }
            }

            if (boxOffice[j] != 0)
                aTime += 1;
        }

        std::cout << "Time is " << i + 1 << " --- ";

        for (int j = 0; j < m; j++) {
            std::cout << boxOffice[j] << " ";
        }

        std::cout << std::endl;
    }

    double ppp = passL;
    
    aTime = aTime / ppp;

    return passL;
}

void Out(int passL, int n, double aTime) {
    std::cout << "The Queue is:" << std::endl;

    for (int i = passL; i < n; i++) {
        std::cout << "T" << i << ";" << std::endl;
    }

    std::cout << "And the average time is " << aTime << std::endl;

}

int main() {
    int N, M, T0, P, Time;

    InData(N, M, T0, P, Time);

    int** Passengers = new int* [N];

    int* BoxOffice = new int[M];

    for (int i = 0; i < N; i++) {
        Passengers[i] = new int[2];
    }

    In(N, M, P, Time, Passengers, BoxOffice);

    // for (int i = 0; i < N; i++) {
    //     std::cout << Passengers[i][0] << " " << Passengers[i][1] << std::endl; 

    // }

    double ATime = 0;

    int pass = FindQueue(N, M, T0, Time, Passengers, BoxOffice, ATime);
    // std::cout << "Bruh" << std::endl; 

    Out(pass, N, ATime);

    for (int i = 0; i < N; i++) {
        delete[](Passengers[i]);
    }

    delete[] Passengers;
    delete[] BoxOffice;
    return 0;
}
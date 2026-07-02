/*5. На вокзале имеется M билетных касс. При покупке билетов возможны два варианта: покупается билет в пункт, 
с которым есть прямое сообщение, и билет с пересадкой в пункт, с которым нет прямого сообщения. Время оформления 
первого варианта билета вдвое меньше времени оформления второго варианта. Количество пассажиров, покупающих 
билеты по обоим вариантам примерно одинаково. Время оформления билета по первому варианту составляет O минут. 
Поток пассажиров задан в виде массива следующего формата:
P={T1,v1, T2,v2, … Tn,vn}, где Ti, vi - соответственно время подхода пассажира к кассе и вариант покупки.
Определить размер очереди через время Т0. */
#include <iostream>

void In(int& n, int& m, int& t0, int** passengers, int* boxOffice) {
    std::cout << "Enter N: ";
    std::cin >> n;

    std::cout << "Enter M: ";
    std::cin >> m;

    std::cout << "Enter T0: ";
    std::cin >> t0;

    for (int i = 0; i < n; i++) {
        std::cout << "Enter T" << i << " and v" << i << ": " << std::endl;
        std::cin >> passengers[i][0] >> passengers[i][1];

        if (passengers[i][1] == 1)
            passengers[i][1] = 1;

        else
            passengers[i][1] = 2;
    }
    
    for (int j = 0; j < m; j++) {
        boxOffice[j] = 0;
    }

}

int FindQueue(int n, int m, int t0, int** passengers, int* boxOffice) {
    int passL = 0;

    for (int i = 0; i < t0; i++) {
        for (int j = 0; j < m; j++) {
            if ((boxOffice[j] == 0) || (boxOffice[j] == i)) {
                for (int k = passL; passL < n; k++) {
                    if (passengers[k][0] <= i) {
                        boxOffice[j] = i + passengers[k][1];
                        passL = k + 1;

                        break;
                    }
                }               
            }
        }

        std::cout << "\n" << std::endl;
    }

    for (int j = 0; j < m; j++) {
        std::cout << boxOffice[j] << " ";
    }

    return passL;
}

void Out(int passL, int n) {
    std::cout << "The Queue is:" << std::endl;

    for (int i = passL; i < n; i++) {
        std::cout << "T" << i << ";" << std::endl;
    }

}

int main() {
    int N, M, T0;

    // int N = 9;
    // int M = 2;
    
    // int N = 12;
    // int M = 3;

    int** Passengers = new int* [N];

    int* BoxOffice = new int[M];

    for (int i = 0; i < N; i++) {
        Passengers[i] = new int[2];
    }

    // int Passengers[N][M] = {{0, 1}, {0, 2}, {0, 1}, {1, 2}, {1, 2}, {2, 1}, {2, 2}, {2, 2}, {3, 1}};
    // int Passengers[N][M] = {{0, 1}, {0, 2}, {0, 1}, {0, 2}, {1, 2}, {1, 2}, {1, 2}, {2, 1}, {2, 1}, {2, 2}, {3, 2}, {3, 1}};

    In(N, M, T0, Passengers, BoxOffice);

    int pass = FindQueue(N, M, T0, Passengers, BoxOffice);

    Out(pass, N);
    
    for (int i = 0; i < N; i++) {
        delete[](Passengers[i]);
    }

    delete[] Passengers;
    delete[] BoxOffice;
    return 0;
}
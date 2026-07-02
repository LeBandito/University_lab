/*5. На вокзале имеется M билетных касс. При покупке билетов возможны два варианта: покупается билет в пункт, 
с которым есть прямое сообщение, и билет с пересадкой в пункт, с которым нет прямого сообщения. Время оформления 
первого варианта билета вдвое меньше времени оформления второго варианта. Количество пассажиров, покупающих 
билеты по обоим вариантам примерно одинаково. Время оформления билета по первому варианту составляет O минут. 
Поток пассажиров задан в виде массива следующего формата:
P={T1,v1, T2,v2, … Tn,vn}, где Ti, vi - соответственно время подхода пассажира к кассе и вариант покупки.
Определить размер очереди через время Т0. */
#include <iostream>

struct Back{
    int first;
    int second;
};

void InData(int &m, int &n, int &t0) {
    std::cout << "Enter quantity of box offices (M): " << std::endl;
    std::cin >> m;

    std::cout << "Enter quantity of passenger (N): " << std::endl;
    std::cin >> n;

    std::cout << "Enter finish time (T0): " << std::endl;
    std::cin >> t0;
}

void In(int** p, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Enter T" << i + 1 << " and v" << i + 1 << " : " << std::endl;
        std::cin >> p[i][0] >> p[i][1];

        if (p[i][1] == 1) {
            p[i][1] = 1;
        }
        
        else {
            p[i][1] = 2;
        }
    }
    
    std::cout << "\n" << std::endl;
}

Back FindQueue(int m, int n, int t0, int** p, int* ArrM) {
    int vrem = 0;
    int TimeQueue = 0;

    for (int i = 0; i < t0; i++) {
        std::cout << "box offices (M) at " << i << " : " << std::endl;

        for (int j = 0; j < m; j++) {
            for (int k = vrem; k < n; k++) {
                if ((ArrM[j] == i) || (ArrM[j] == 0)) {
                    ArrM[j] = i + p[k][1];
                    vrem += 1;
                    break;
                }
            }

            std::cout << ArrM[j] << " ";
        }

        TimeQueue += n - vrem;

        std::cout << "The queue: ";

        for (int j = vrem + 1; j <= n; j++) {
            std::cout << j << " ";

        }

        std::cout << "\n" << std::endl;
    }

    return {vrem, TimeQueue};
}

int main() { 
    int M, N, T0;
    // M = 2;
    // N = 11;
    // T0 = 5;
    InData(M, N, T0);

    int** P = new int*[N];
    int* arrM = new int[M]();

    for (int i = 0; i < N; i++) {
        P[i] = new int[2]; 
    }

    In(P, N);

    // int P[N][2] = {{0, 1}, {0, 2}, {0, 1}, {1, 1}, {1, 2}, {2, 1}, {2, 2}, {2, 1}, {2, 1}, {3, 2}, {3, 1}};
    // int arrM[M] = {};
    // 0 1 0 2 0 1 0 2 1 2 1 2 1 1 2 1 2 2 2 2 2 2 2 2 3 1 3 1 4 2 4 1

    Back Bruh = FindQueue(M, N, T0, P, arrM);

    std::cout << "The queue: ";

    for (int l = Bruh.first + 1; l <= N; l++) {
        std::cout << l << " ";
    }

    std::cout << "\nThe average time: " << Bruh.second / (N * 1.0);

    for (int i = 0; i < N; i++) {
        delete[](P[i]);
    }

    delete[] P;
    delete[] arrM;

    return 0;
}
/*5. Максимальный квадрат.
На плоскости задано N точек с координатами (X1,Y1), (X2,Y2), ..., (Xn,Yn).
Написать программу, которая из этих точек выделяет вершины квадрата, содержащего максимальное число заданных точек.
Примечание: точки, расположенные на сторонах квадрата, также принадлежат ему.
*/

#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x;
    double y;
};

struct Square {
    Point a1;
    Point a2;
    Point a3;
    Point a4;
};

void In(Point* arrN, int& n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Enter x" << i + 1 << " and y" << i + 1 << ":" << std::endl;
        std::cin >> arrN[i].x >> arrN[i].y;
    }
}

void NormalSquare(Point checkN[]) {
    Point P1 = checkN[0];
    Point P2 = checkN[0];
    Point P3 = checkN[0];
    Point P4 = checkN[0];

    for (int i = 0; i < 4; i++) {
        if ((P1.x <= checkN[i].x) && (P1.y <= checkN[i].y))
            P1 = checkN[i];
        
        if ((P2.x >= checkN[i].x) && (P2.y <= checkN[i].y))
            P2 = checkN[i];
        
        if ((P3.x >= checkN[i].x) && (P3.y >= checkN[i].y))
            P3 = checkN[i];

        if ((P4.x <= checkN[i].x) && (P4.y >= checkN[i].y))
            P4 = checkN[i];
    }

    checkN[0] = P1;
    checkN[1] = P2;
    checkN[2] = P3;
    checkN[3] = P4;
}

bool IsNot(Point* checkN, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (((checkN[i].x - checkN[j].x) == 0) && ((checkN[i].y - checkN[j].y) == 0))
                return false;
        }
    }

    return true;
}

bool CheckSquare(Point checkN[]) {
    int a1 = abs(checkN[1].x - checkN[0].x);
    int a2 = abs(checkN[2].x - checkN[3].x);
    int a3 = abs(checkN[1].y - checkN[2].y);
    int a4 = abs(checkN[0].y - checkN[3].y);

    if ((pow((checkN[1].x - checkN[3].x), 2) + pow((checkN[1].y - checkN[3].y), 2) == pow((checkN[0].x - checkN[2].x), 2) + 
    pow((checkN[0].y - checkN[2].y), 2)) && (a1 == a2) && (a3 == a4) && (a1 == a3) && (a1 == a4) && (a2 == a3) && (a2 == a4)) {
        return true;
    }

    return false;
}

void InSquare(Point* arrN, std::vector<Square>& masN, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    Point check[4] = { arrN[i], arrN[j], arrN[k], arrN[l] };                        
                    NormalSquare(check);

                    if (IsNot(check, 4)) {

                        if (CheckSquare(check)) {
                            std::cout << "The Square is " << "{(x1, y1), (x2, y2), (x3, y3), (x4, y4)} = {";

                            std::cout << "(" << check[0].x << ", " << check[0].y << "), ";
                            std::cout << "(" << check[1].x << ", " << check[1].y << "), ";
                            std::cout << "(" << check[2].x << ", " << check[2].y << "), ";
                            std::cout << "(" << check[3].x << ", " << check[3].y << ")} " << std::endl;
                            masN.push_back({ {check[0].x, check[0].y}, {check[1].x, check[1].y}, {check[2].x, check[2].y}, {check[3].x, check[3].y} });
                        }
                    }
                }
            }
        }
    }
}

void CountPoints(Point* arrN, std::vector<Square>& masN, int n, int* Points) {
    int sizeSquare = masN.size();

    for (int i = 0; i < sizeSquare; i++) {
        int check = 0;

        for (int j = 0; j < n; j++) {
            if ((arrN[j].x <= masN[i].a1.x) && (arrN[j].x >= masN[i].a2.x) && (arrN[j].y <= masN[i].a1.y) && (arrN[j].y >= masN[i].a4.y)) {
                check += 1;
            }
        }

        Points[i] = check - 4;
    }
}

int MaxSquare(int sizeSquare, int* Points) {
    int MaxPoints = 0;

    for (int i = 0; i < sizeSquare; i++) {
        if (Points[MaxPoints] <= Points[i])
            MaxPoints = i;
    }

    return MaxPoints;
}

void OutPoints(Point* arrN, Square maxx, int n) {
    std::cout << "The points are ";

    for (int j = 0; j < n; j++) {
        if (((arrN[j].x <= maxx.a1.x) && (arrN[j].x >= maxx.a2.x)) && ((arrN[j].y <= maxx.a2.y) && (arrN[j].y >= maxx.a3.y)) && 
        ((((arrN[j].x == maxx.a1.x) && (arrN[j].y == maxx.a1.y)) || ((arrN[j].x == maxx.a2.x) && (arrN[j].y == maxx.a2.y)) ||  
        ((arrN[j].x == maxx.a3.x) && (arrN[j].y == maxx.a3.y)) || ((arrN[j].x == maxx.a4.x) && (arrN[j].y == maxx.a4.y))) == false)) {
            std::cout << "(" << arrN[j].x << ", " << arrN[j].y << "), ";
        }
    }
}

int main() {
    int N = 15;
    // std::cout << "Enter N: ";
    // std::cin >> N;

    // Point* arr = new Point[N];

    Point arr[N] = {{1, -1}, {2, 2}, {2, 1}, {3, -2}, {4, 4}, {4, 2}, {4, 0}, {4, -1}, {6, 2}, {6, 0}, {6, -1}, {9, 4}, {9, 2}, {9, -1}, {2, 5}, {2, 0}, {7, 5}, {7, 0}};
    // Point arr[N] = {{1, -1}, {2, 5}, {2, 2}, {2, 1}, {2, 0}, {3, -2}, {4, 4}, {4, 2}, {4, 0}, {4, -1}, {6, 2}, {6, 0}, {6, -1}, {7, 5}, {7, 0}, {9, 4}, {9, 2}, {9, -1}};

    // int N = 4;
    // Point arr[N] = {{3, -3}, {1, -1}, {1, -1}, {1, -1}};

    // std::cout << IsNot(arr);

    std::vector<Square> mas;

    // In(arr, N);

    InSquare(arr, mas, N);

    int SizeSquare = mas.size();

    int* points = new int[SizeSquare];

    CountPoints(arr, mas, N, points);

    int MaxPoints = MaxSquare(SizeSquare, points);

    std::cout << "The square has max number of points is: " << points[MaxPoints] << std::endl;

    std::cout << "The Square is " << "{(x1, y1), (x2, y2), (x3, y3), (x4, y4)} = {";

    std::cout << "(" << mas[MaxPoints].a1.x << ", " << mas[MaxPoints].a1.y << "), ";
    std::cout << "(" << mas[MaxPoints].a2.x << ", " << mas[MaxPoints].a2.y << "), ";
    std::cout << "(" << mas[MaxPoints].a3.x << ", " << mas[MaxPoints].a3.y << "), ";
    std::cout << "(" << mas[MaxPoints].a4.x << ", " << mas[MaxPoints].a4.y << ")} " << std::endl;

    OutPoints(arr, mas[MaxPoints], N);

    delete[] points;
    // delete[] arr;
    return 0;
}
/*5.	Составить функцию вычисления целочисленного корня любой степени из длинного числа.*/

#include <iostream>
#include <string>


void Equal(std::string& s1, std::string& s2, int& l) {
    int l1 = s1.length();
    int l2 = s2.length();

    if (l1 > l2) {
        l = l1;

        for (int i = 0; i < l - l2; i++)
            s2 = '0' + s2;
    } 
    else {
        l = l2;

        for (int i = 0; i < l - l1; i++)
            s1 = '0' + s1;
    }
}

std::string Plus(std::string a, std::string b) {
    int l;

    Equal(a, b, l);

    bool p = false;
    std::string s = "";

    for (int i = l - 1; i >= 0; i--) {
        int x1 = a[i] - '0';
        int x2 = b[i] - '0';

        int x = x1 + x2;

        if (p) 
            x += 1;

        if (x > 9) 
            p = true;

        else 
            p = false;

        x = x % 10;

        s = std::to_string(x) + s;
    }

    if (p) 
        s = '1' + s;

    return s;
}

std::string Minus(std::string a, std::string b) {
    int l;

    Equal(a, b, l);

    bool p = false;
    std::string s = "";

    for (int i = l - 1; i >= 0; i--) {
        int x1 = a[i] - '0';
        int x2 = b[i] - '0';

        if (p) 
            x1 -= 1;

        if (x1 < x2) {
            x1 += 10;
            p = true;
        } 

        else {
            p = false;
        }

        int x = x1 - x2;
        s = std::to_string(x) + s;
    }

    while (s[0] == '0' && s.length() > 1)
        s.erase(0, 1);

    return s;
}

std::string MultiOne(std::string a, int b) {
    std::string s = "";

    for (int i = a.length() - 1; i >= 0; i--) {
        int x = a[i] - '0';
        x *= b;
        std::string s1 = std::to_string(x);
        s1.append(a.length() - 1 - i, '0');
        s = Plus(s, s1);
    }

    return s;
}

std::string Multi(std::string a, std::string b) {
    std::string s = "";

    for (int i = b.length() - 1; i >= 0; i--) {
        std::string s1 = MultiOne(a, b[i] - '0');
        s1.append(b.length() - 1 - i, '0');
        s = Plus(s, s1);
    }

    return s;
}

std::string Pow(std::string a, std::string b) {
    std::string rez = a;
    std::string x = b;
    if (a == "0") {
        return "0";
    } else {
        while (x != "1") {
            a = Multi(a, rez);
            x = Minus(x, "1");
        }
    }
    return a;
}

std::string Sqrt(std::string a, std::string b) { // Корень из любой степени
    std::string rez = "0";
    std::string x;
    
    do {
        rez = Plus(rez, "1");
        x = Pow(rez, b);
    } while (x != a);

    return rez;
}

int main() {
    std::string numberA, numberB;
    std::cout << "Enter numberA, numberB: ";
    std::cin >> numberA >> numberB;

    std::string numberAB = Multi(numberA, numberB);

    std::cout << "The number is: " << numberAB;

    return 0;
}
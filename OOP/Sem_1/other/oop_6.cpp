/*  B1   B2
    |   /
public  public
    | /
    D1   D2
    |   /
public  public
    | /
    D3
    |
public
    |
    D4*/

#include <iostream>

class B1 {
    public:
        int Bom_B1;
    
    B1(): Bom_B1()
    {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}

    B1(int newBom_B1): Bom_B1(newBom_B1)
    {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}

    B1(const B1& other): Bom_B1(other.Bom_B1)
    {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
    
    void set_B1(int newBom_B1) {Bom_B1 = newBom_B1;}
    int get_B1() const {return Bom_B1;}

    void Show()
    {std::cout << "Bom_B1 is " << get_B1() << std::endl;}
    
    ~B1()
    {std::wcout << L"Удаляем!" << std::endl;}
};

class B2 {
    public:
        int Bom_B2;
    
    B2(): Bom_B2()
    {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}

    B2(int newBom_B2): Bom_B2(newBom_B2)
    {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}

    B2(const B2& other): Bom_B2(other.Bom_B2)
    {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
    
    void set_B2(int newBom_B2) {Bom_B2 = newBom_B2;}
    int get_B2() const {return Bom_B2;}

    void Show()
    {std::cout << "Bom_B2 is " << get_B2() << std::endl;}
    
    ~B2()
    {std::wcout << L"Удаляем!" << std::endl;}
};

class D1 : public B1, public B2 {
    public:
        int Bom_D1;
    
    D1(): Bom_D1(), B1(), B2()
    {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}

    D1(int newBom_D1, int new_B1, int new_B2): Bom_D1(newBom_D1), B1(new_B1), B2(new_B2)
    {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}

    D1(const D1& other): Bom_D1(other.Bom_D1), B1(other.Bom_B1), B2(other.Bom_B2)
    {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
    
    void set_D1(int newBom_D1) {Bom_D1 = newBom_D1;}
    int get_D1() const {return Bom_D1;}

    void Show()
    {
        B1::Show();
        B2::Show();
        std::cout << "Bom_D1 is " << get_D1() << std::endl;
    }
    
    ~D1()
    {std::wcout << L"Удаляем!" << std::endl;}
};

class D2 {
    public:
        int Bom_D2;
    
    D2(): Bom_D2()
    {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}

    D2(int newBom_D2): Bom_D2(newBom_D2)
    {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}

    D2(const D2& other): Bom_D2(other.Bom_D2)
    {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
    
    void set_D2(int newBom_D2) {Bom_D2 = newBom_D2;}
    int get_D2() const {return Bom_D2;}

    void Show()
    {std::cout << "Bom_D2 is " << get_D2() << std::endl;}
    
    ~D2()
    {std::wcout << L"Удаляем!" << std::endl;}

};

class D3 : public D1, public D2 {
    public:
        int Bom_D3;
    
    D3(): Bom_D3(), D1(), D2()
    {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}

    D3(int newBom_D3, int new_D1, int new_B1, int new_B2, int new_D2): 
        Bom_D3(newBom_D3), D1(new_D1, new_B1, new_B2), D2(new_D2)
    {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}

    D3(const D3& other): 
        Bom_D3(other.Bom_D3), D1(other.Bom_D1, other.Bom_D1, other.Bom_D1), D2(other.Bom_D2)
    {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
    
    void set_D3(int newBom_D3) {Bom_D3 = newBom_D3;}
    int get_D3() const {return Bom_D3;}

    void Show()
    {
        D1::Show();
        D2::Show();
        std::cout << "Bom_D3 is " << get_D3() << std::endl;
    }
    
    ~D3()
    {std::wcout << L"Удаляем!" << std::endl;}
};

class D4 : public D3 {
    public:
        int Bom_D4;
    
    D4(): Bom_D4(), D3()
    {std::wcout << L"Вызван конструктор по умолчанию!" << std::endl;}

    D4(int newBom_D4, int new_D3, int new_D1, int new_B1, int new_B2, int new_D2): 
        Bom_D4(newBom_D4), D3(new_D3, new_D1, new_B1, new_B2, new_D2)   
    {std::wcout << L"Вызван конструктор с параметрами!" << std::endl;}

    D4(const D4& other): 
        Bom_D4(other.Bom_D4), D3(other.Bom_D3, other.Bom_D3, other.Bom_D3, other.Bom_D3, other.Bom_D3)
    {std::wcout << L"Вызван конструктор копирования!" << std::endl;}
    
    void set_D4(int newBom_D4) {Bom_D4 = newBom_D4;}
    int get_D4() const {return Bom_D4;}

    void Show()
    {
        D3::Show();
        std::cout << "Bom_D4 is " << get_D4() << std::endl;
    }
    
    ~D4()
    {std::wcout << L"Удаляем!" << std::endl;}
};

int main() {
    setlocale(LC_ALL, "");
    D4 Ka_Boom_D4(1, 2, 3, 4, 5, 6);
    Ka_Boom_D4.Show();
    
    return 0;
}

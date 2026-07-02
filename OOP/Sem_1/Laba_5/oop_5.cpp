/*Создать класс студент, содержащий в качестве параметров имя (строка), курс и
идентификационный номер. Определить конструкторы, деструктор и функцию
печати. Создать public-производный класс - студент-дипломник, имеющий
дополнительный строковый параметр - тему диплома. Определить конструкторы
по умолчанию и с разным числом параметров, деструктор, функцию печати.
Определить функции переназначения названия диплома и идентификационного
номера.*/

#include <iostream>

class student {
    private:
        std::string name;
        int course;
        int id;
    
    public:
        student(): name(), course(), id() 
        {
            std::wcout << L"Вызван конструктор по умаолчанию!" << std::endl;
        }
        
        student(std::string Name, int Course, int Id): name(Name), course(Course), id(Id) 
        {
            std::wcout << L"Вызван конструктор с параметрами!" << std::endl;
        }
        
        student(const student& other): name(other.name), course(other.course), id(other.id) 
        {
            std::wcout << L"Вызван конструктор копирования!" << std::endl;
        }
        
        void setName(std::string NewName) {name = NewName;}
        void setCourse(int NewCourse) {course = NewCourse;}
        void setId(int NewId) {id = NewId;}
        
        std::string getName() const {return name;}
        int getCourse() const {return course;}
        int getId() const {return id;}
        
        void ShowData();
        
        ~student() {
            std::wcout << L"Удаляем!" << std::endl;
        }
};

void student::ShowData() {
    std::cout << "Name: " << getName() << std::endl;
    std::wcout << L"Курс: " << getCourse() << std::endl;
    std::wcout << L"Идентификатор: " << getId() << std::endl;
    std::cout << " ----- " << std::endl;
}

class interpreter : public student {
    private:
        std::string subject;
    
    public:
        interpreter(): subject()
        {
            std::wcout << L"Вызван конструктор по умаолчанию!" << std::endl;
        }
        
        interpreter(std::string Name, int Course, int Id, std::string Subject): 
            student(Name, Course, Id), subject(Subject)
        {
            std::wcout << L"Вызван конструктор с параметрами!" << std::endl;
        }
        
        void setSubject(std::string NewSubject) {subject = NewSubject;}
        
        std::string getSubject() const {return subject;}
        
        void ShowData();
        
        ~interpreter() {
            std::wcout << L"Удаляем!" << std::endl;
        }
};

void interpreter::ShowData() {
    std::cout << "The subject of student: " << getSubject() << std::endl;
}

int main() {
    setlocale(LC_ALL, "");
    student BomBomBom("Bruh", 2, 175);
    BomBomBom.ShowData();
    BomBomBom.setName("Ararara");
    BomBomBom.ShowData();
    
    interpreter Urururu("Bobro", 3, 557, "math");
    Urururu.ShowData();
    
    return 0;
}


/*5. Написать программу, в которой описана иерархия классов: ошибка в программе
(«ошибочный указатель», «ошибка работы со списком», «недопустимый индекс», «список
переполнен»). Описать шаблонный класс для хранения массива указателей на объекты
произвольного класса, в шаблонном классе перегрузить операцию «[]». Продемонстрировать
работу операторов и использование шаблонного класса с различными классами.*/

#include <iostream>

class mistake {
    protected:
        std::string des;
    
    public:
        mistake(std::string new_des) : des(new_des) {}
        
        virtual std::string what() const { return des; }
        
        virtual ~mistake() {}
};

class errorPointer : public mistake {
    public:
        errorPointer() : mistake("ошибочный указатель - errorPointer") {}
};

class errorWorkingList : public mistake {
    public:
        errorWorkingList() : mistake("ошибка работы со списком - errorWorkingList") {}
};

class invalidIndex  : public mistake {
    public:
        invalidIndex() : mistake("недопустимый индекс - invalidIndex") {}
};

class fullList  : public mistake {
    public:
        fullList() : mistake("список переполнен - fullList") {}
};

template <typename T>
class PtrArray {
    private:
        T** piece;
        int capacity;
        int count;
    
    public: 
        PtrArray(int size) {
            capacity = size;
            count = 0;
            piece = new T*[capacity];
            
            for (int i = 0; i < capacity; ++i)
                piece[i] = nullptr;
                
            std::cout << "Created arr, for " << capacity << " elements!" << std::endl;
        }
        
        void add(const T& value) {
            if (count >= capacity)
                throw fullList();
                
            piece[count] = new T(value);
            count++;
            
            std::cout << "Element " << value << " was added" << std::endl;
        }
        
        T& operator[](int index) {
            if ((index < 0) || (index >= count))
                throw invalidIndex();
                
            for (int i = count; i < capacity; i++) {
                if (piece[i] != nullptr) {
                    throw errorWorkingList();
                }
            }
                
            if (piece[index] == nullptr)
                throw errorPointer();
                
            return *piece[index];
        }
        
        void makeError() {
            if (count > 0) {
                delete piece[0];
                piece[0] = nullptr;
            }
        }
        
        void makeHole() {
            if (count > 1) {
                delete piece[1];
                piece[1] = nullptr;
                count--;
            }
        }
        
        void makeListInconsistent() {
            if (count > 1) {
                // Создаем ситуацию: count=1, но элемент [1] существует
                count = 1;
            }
        }
        
        ~PtrArray() { 
            for (int i = 0; i < count; ++i) {
                if (piece[i] != NULL) 
                    delete piece[i];
            }
            
            delete[] piece; 
        }
};

int main() {
    try {
        PtrArray<int> bom(3);
        
        bom.add(10);
        bom.add(20);
        bom.add(30);
        
        std::cout << bom[0] << " " << bom[1] << " " << bom[2] << std::endl;
        
        bom[2] = 200;
        std::cout << bom[2] << std::endl;
        
        bom[3] = 500;
    } catch (const mistake& e) {
        std::cout << "Mistake: " << e.what() << std::endl;
    }

    try {
        PtrArray<char> boom(4);
        
        boom.add('h');
        boom.add('e');
        boom.add('l');
        boom.add('l');
        boom.add('o');
        
        std::cout << boom[0] << boom[1] << boom[2] << boom[3] << boom[4] << std::endl;
    } catch (const mistake& e) {
        std::cout << "Mistake: " << e.what() << std::endl;
    }

    try {
        PtrArray<std::string> booom(3);
        
        booom.add("Hello");
        booom.makeError();
        
        std::cout << booom[0] << booom[1] << booom[2] << booom[3] << booom[11] << std::endl;
    } catch (const mistake& e) {
        std::cout << "Mistake: " << e.what() << std::endl;
    }
    
    try {
        PtrArray<double> boooom(3);
        boooom.add(1.1);
        boooom.add(2.2);
        boooom.add(3.3);
        boooom.makeListInconsistent();
        std::cout << boooom[0] << std::endl;  
    } catch (const mistake& e) {
        std::cout << "Mistake: " << e.what() << std::endl;
    }
    
    return 0;
}
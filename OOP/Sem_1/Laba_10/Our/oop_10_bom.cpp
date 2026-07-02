#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;


class Examheader {
    private:
        int width;
        string value;
    public:
        Examheader(int w, string v) : width(fabs(w)), value(v) {}
        friend ostream& operator<<(ostream& os, const Examheader& ef);
};

ostream& operator<<(ostream& os, const Examheader& ef) {
    os << setw(ef.width) << left << ef.value;
    return os;
}


class Exam {
    private:
        string name;
        int date;
        int grade;
        static string validateName(const string& n) {
            if (n.empty()) throw invalid_argument("Имя не должно быть пустым");
            return n;
        }

        static int validateDate(int d) {
            if (d <= 0) throw invalid_argument("Номер должен быть положительным");
            return d;
        }

        static int validateGrade(int g) {
            if (g < 1 || g > 5) throw invalid_argument("Invalid grade");
            return g;
        }

    public:
        Exam() : name(""), date(0), grade(0) {}

        Exam(const string& n, int d, int g)
            : name(validateName(n)),
            date(validateDate(d)),
            grade(validateGrade(g)) {
        }

        string value() const {
            stringstream ss;
            ss << name << " " << date << " " << grade;
            return ss.str();
        }
        string getName() const { return name; }
        int getDate() const{ return date; }
        int getGrade() const{ return grade; }
        friend istream& operator>>(istream&, Exam&);
        friend ostream& operator<<(ostream&, const Exam&);
};

istream& operator>>(istream& in, Exam& e) {
    if (!in) return in;

    string n;
    int d, g;

    in >> n >> d >> g;

    if (in) {
        e = Exam(n, d, g);
    }

    return in;
}

ostream& operator<<(ostream& out, const Exam& e) {
    out << e.value() << endl;
    return out;
}


void SaveData(vector<Exam> vec, string file) {
    ofstream out(file, ios::trunc);
    int n = 0;
    for (const Exam& e : vec) {
        out << e;
        n++;
    }
    cout << "Сохранено " << n << " элементов." << endl;
    out.close();
}

vector<Exam> ReadData(const string& file) {
    vector<Exam> temp;
    ifstream in(file);

    if (!in) {
        cerr << "Ошибка открытия файла: " << file << "\n";
        return temp;
    }

    Exam e;
    while (in >> e) {
        temp.push_back(e);
    }

    if (in.eof()) {
        cout << "Достигнут конец файла. Чтение завершено успешно." << endl;
    }
    else if (in.bad()) {
        cerr << "Произошла критическая ошибка ввода-вывода (физическая проблема с носителем)." << endl;
    }
    else if (in.fail()) {
        cerr << "Ошибка чтения данных." << endl;
    }

    if (in.good()) {
        cout << "С потоком все в порядке." << endl; // Эта строка не выполнится после цикла
    }

    cout << "Прочитано " << temp.size() << " элементов.\n";
    return temp;
}


void ShowData(vector<Exam> vec) {
    int n = 1;
    /*for (const Exam& e : vec) {
        cout << n << " " << e.value() << endl;
        n++;
    }*/
    for (const Exam& e : vec) {
        cout << Examheader(15, e.getName())
            << Examheader(15, to_string(e.getDate()))
            << Examheader(10, to_string(e.getGrade())) << endl;
    }
}

void AddData(vector<Exam>& vec, const string& name, int date, int grade) {
    vec.push_back(Exam(name, date, grade));
}

void DeleteData(vector<Exam>& vec, int pos) {
    if (pos > 0 && pos <= vec.size()) {
        vec.erase(vec.begin() + pos - 1);
        cout << "Запись номер " << pos << " удалена." << endl;
    }
}

void FindData(const vector<Exam>& vec, const string& name) {
    int n = 1;
    for (const Exam& e : vec) {
        if (e.value().find(name) != string::npos) {
            cout << n << " " << e.value() << endl;
        }
        n++;
    }
}

void ReplaceData(vector<Exam>& vec, int pos, const string& name, int date, int grade) {
    if (pos > 0 && pos <= vec.size()) {
        vec[pos - 1] = Exam(name, date, grade);
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    vector<Exam> data;
    data.push_back(Exam("Васильев", 27628634, 5));
    data.push_back(Exam("Борисов", 28249084, 4));
    data.push_back(Exam("Николаев", 2422442, 3));
    cout << "Данные об экзамене:" << endl;
    ShowData(data);
    SaveData(data, "1.dat");
    cout << endl;
    cout << "Данные об экзамене:" << endl;
    data.clear();
    data = ReadData("1.dat");
    ShowData(data);
    cout << endl;
    cout << "Добавляем данные об экзамене:" << endl;
    AddData(data, "Кузнецов", 20241201, 5);
    ShowData(data);
    cout << endl;
    cout << "Удаляем запись №2" << endl;
    DeleteData(data, 2);
    ShowData(data);
    cout << endl;
    cout << "Найдём запись экзамена по фамилии студента:" << endl;
    FindData(data, "Кузнецов");
    cout << endl;
    cout << "Заменяем запись №1:" << endl;
    ReplaceData(data, 1, "Васильев", 20240605, 4);
    ShowData(data);
    SaveData(data, "2.dat");

    return 0;
}
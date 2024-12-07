#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    virtual void input() = 0; // Виртуальный ввод
    virtual void display() const = 0; // Виртуальный вывод
    virtual void save(ostream& out) const = 0; // Сохранение в файл
    virtual void load(istream& in) = 0; // Загрузка из файла
    virtual ~Base() {
        cout << "Destructor called for Base\n";
    }
};

#endif // BASE_H
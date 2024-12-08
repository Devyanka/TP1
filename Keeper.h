#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include <vector>
#include <fstream>
#include <stdexcept>

class Keeper {
private:
    Base** items;        // Указатель на массив указателей на объекты Base
    size_t size;         // Текущее количество объектов
    size_t capacity;     // Ёмкость массива

    void resize();       // Увеличение ёмкости массива

public:
    Keeper();
    ~Keeper();

    void add(Base* item);          // Добавление объекта
    void remove(size_t index);     // Удаление объекта по индексу
    void displayAll() const;       // Отображение всех объектов
    void saveToFile(const string& filename) const; // Сохранение в файл
    void loadFromFile(const string& filename);     // Загрузка из файла
};

#endif // KEEPER_H
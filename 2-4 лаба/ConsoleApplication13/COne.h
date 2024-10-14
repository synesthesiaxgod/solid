// COne.h
#ifndef CONE_H
#define CONE_H

#include <iostream>
#include <cstring>

class COne {
private:
    float f;
    char* ps;

public:
    // Конструктор по умолчанию
    COne();

    // Конструктор с параметрами
    COne(float fValue, const char* psValue);

    // Конструктор копирования
    COne(const COne& other);

    // Деструктор
    ~COne();

    // Перегруженный оператор присваивания
    COne& operator=(const COne& other);

    // Методы доступа
    float getF() const;
    const char* getPs() const;
    void setF(float fValue);
    void setPs(const char* psValue);

    // Метод print()
    void print() const;
};

#endif // CONE_H

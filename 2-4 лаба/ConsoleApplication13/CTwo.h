// CTwo.h
#ifndef CTWO_H
#define CTWO_H

#include <iostream>
#include <string>
#include "COne.h"

class CTwo {
protected:
    std::string s;
    COne obj;

public:
    // Конструктор по умолчанию
    CTwo();

    // Конструктор с параметрами
    CTwo(const std::string& sValue, const COne& objValue);

    // Конструктор копирования
    CTwo(const CTwo& other);

    // Деструктор
    virtual ~CTwo();

    // Перегруженный оператор присваивания
    CTwo& operator=(const CTwo& other);

    // Методы доступа
    std::string getS() const;
    COne getObj() const;
    void setS(const std::string& sValue);
    void setObj(const COne& objValue);

    // Виртуальный метод print()
    virtual void print() const;
};

#endif // CTWO_H

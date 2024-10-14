// CFour.h
#ifndef CFOUR_H
#define CFOUR_H

#include "CThree.h"

class CFour : public CThree {
private:
    double d;

public:
    // Конструктор по умолчанию
    CFour();

    // Конструктор с параметрами
    CFour(const std::string& sValue, const COne& objValue, int kValue, double dValue);

    // Конструктор копирования
    CFour(const CFour& other);

    // Деструктор
    ~CFour();

    // Перегруженный оператор присваивания
    CFour& operator=(const CFour& other);

    // Методы доступа
    double getD() const;
    void setD(double dValue);

    // Виртуальный метод print()
    virtual void print() const override;
};

#endif // CFOUR_H

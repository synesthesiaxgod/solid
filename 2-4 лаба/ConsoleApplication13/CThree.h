// CThree.h
#ifndef CTHREE_H
#define CTHREE_H

#include "CTwo.h"

class CThree : public CTwo {
private:
    int k;

public:
    // Конструктор по умолчанию
    CThree();

    // Конструктор с параметрами
    CThree(const std::string& sValue, const COne& objValue, int kValue);

    // Конструктор копирования
    CThree(const CThree& other);

    // Деструктор
    ~CThree();

    // Перегруженный оператор присваивания
    CThree& operator=(const CThree& other);

    // Методы доступа
    int getK() const;
    void setK(int kValue);

    // Виртуальный метод print()
    virtual void print() const override;
};

#endif // CTHREE_H

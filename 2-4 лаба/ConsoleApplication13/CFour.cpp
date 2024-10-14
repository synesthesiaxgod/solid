// CFour.cpp
#include "CFour.h"

// Конструктор по умолчанию
CFour::CFour() : CThree(), d(0.0) {}

// Конструктор с параметрами
CFour::CFour(const std::string& sValue, const COne& objValue, int kValue, double dValue)
    : CThree(sValue, objValue, kValue), d(dValue) {}

// Конструктор копирования
CFour::CFour(const CFour& other) : CThree(other), d(other.d) {}

// Деструктор
CFour::~CFour() {}

// Перегруженный оператор присваивания
CFour& CFour::operator=(const CFour& other) {
    if (this != &other) {
        CThree::operator=(other);
        d = other.d;
    }
    return *this;
}

// Методы доступа
double CFour::getD() const {
    return d;
}

void CFour::setD(double dValue) {
    d = dValue;
}

// Виртуальный метод print()
void CFour::print() const {
    std::cout << "CFour: d = " << d << std::endl;
    CThree::print();
}

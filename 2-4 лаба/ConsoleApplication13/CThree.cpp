// CThree.cpp
#include "CThree.h"

// Конструктор по умолчанию
CThree::CThree() : CTwo(), k(0) {}

// Конструктор с параметрами
CThree::CThree(const std::string& sValue, const COne& objValue, int kValue) : CTwo(sValue, objValue), k(kValue) {}

// Конструктор копирования
CThree::CThree(const CThree& other) : CTwo(other), k(other.k) {}

// Деструктор
CThree::~CThree() {}

// Перегруженный оператор присваивания
CThree& CThree::operator=(const CThree& other) {
    if (this != &other) {
        CTwo::operator=(other);
        k = other.k;
    }
    return *this;
}

// Методы доступа
int CThree::getK() const {
    return k;
}

void CThree::setK(int kValue) {
    k = kValue;
}

// Виртуальный метод print()
void CThree::print() const {
    std::cout << "CThree: k = " << k << std::endl;
    CTwo::print();
}

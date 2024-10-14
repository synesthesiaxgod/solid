// CTwo.cpp
#include "CTwo.h"

// Конструктор по умолчанию
CTwo::CTwo() : s(""), obj() {}

// Конструктор с параметрами
CTwo::CTwo(const std::string& sValue, const COne& objValue) : s(sValue), obj(objValue) {}

// Конструктор копирования
CTwo::CTwo(const CTwo& other) : s(other.s), obj(other.obj) {}

// Деструктор
CTwo::~CTwo() {}

// Перегруженный оператор присваивания
CTwo& CTwo::operator=(const CTwo& other) {
    if (this != &other) {
        s = other.s;
        obj = other.obj;
    }
    return *this;
}

// Методы доступа
std::string CTwo::getS() const {
    return s;
}

COne CTwo::getObj() const {
    return obj;
}

void CTwo::setS(const std::string& sValue) {
    s = sValue;
}

void CTwo::setObj(const COne& objValue) {
    obj = objValue;
}

// Виртуальный метод print()
void CTwo::print() const {
    std::cout << "CTwo: s = " << s << std::endl;
    obj.print();
}

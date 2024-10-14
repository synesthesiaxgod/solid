// COne.cpp
#include "COne.h"

// Конструктор по умолчанию
COne::COne() : f(0.0f), ps(nullptr) {
    ps = new char[1];
    ps[0] = '\0';
}

// Конструктор с параметрами
COne::COne(float fValue, const char* psValue) : f(fValue), ps(nullptr) {
    if (psValue) {
        ps = new char[strlen(psValue) + 1];
        strcpy(ps, psValue);
    }
    else {
        ps = new char[1];
        ps[0] = '\0';
    }
}

// Конструктор копирования
COne::COne(const COne& other) : f(other.f), ps(nullptr) {
    if (other.ps) {
        ps = new char[strlen(other.ps) + 1];
        strcpy(ps, other.ps);
    }
    else {
        ps = new char[1];
        ps[0] = '\0';
    }
}

// Деструктор
COne::~COne() {
    delete[] ps;
}

// Перегруженный оператор присваивания
COne& COne::operator=(const COne& other) {
    if (this != &other) {
        f = other.f;
        delete[] ps;
        if (other.ps) {
            ps = new char[strlen(other.ps) + 1];
            strcpy(ps, other.ps);
        }
        else {
            ps = new char[1];
            ps[0] = '\0';
        }
    }
    return *this;
}

// Методы доступа
float COne::getF() const {
    return f;
}

const char* COne::getPs() const {
    return ps;
}

void COne::setF(float fValue) {
    f = fValue;
}

void COne::setPs(const char* psValue) {
    delete[] ps;
    if (psValue) {
        ps = new char[strlen(psValue) + 1];
        strcpy(ps, psValue);
    }
    else {
        ps = new char[1];
        ps[0] = '\0';
    }
}

// Метод print()
void COne::print() const {
    std::cout << "COne: f = " << f << ", ps = " << ps << std::endl;
}

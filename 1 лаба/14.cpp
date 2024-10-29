#include <iostream>
#include <stdexcept>

class Rational {
private:
    int numerator;   // числитель
    int denominator; // знаменатель

    // приведение к одному знаменателю
    void reduce() {
        int gcdValue = gcd(abs(numerator), abs(denominator));
        numerator /= gcdValue;
        denominator /= gcdValue;
        // Обеспечиваем положительный знаменатель
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    // наибольший общие делитель
    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

public:
    Rational() : numerator(0), denominator(1) {}

    
    Rational(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw std::invalid_argument("Знаменатель не может быть равен нулю.");
        }
        reduce();
    }

    // сложение
    Rational operator+(const Rational& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    // вычитание
    Rational operator-(const Rational& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    // умножение
    Rational operator*(const Rational& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    // деление
    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Деление на ноль.");
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Rational(num, denom);
    }

    // операторы сравнения
    bool operator==(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    bool operator<(const Rational& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Rational& other) const {
        return other < *this;
    }

    bool operator<=(const Rational& other) const {
        return !(*this > other);
    }

    bool operator>=(const Rational& other) const {
        return !(*this < other);
    }

    // вывод рационального числа на экран
    void print() const {
        if (denominator == 1) {
            std::cout << numerator << '\n';
        }
        else if (numerator == 0) {
            std::cout << "0\n";
        }
        else {
            std::cout << numerator << '/' << denominator << '\n';
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    try {
        Rational r1(2, 5);
        Rational r2(3, 10);

        std::cout << "r1 = ";
        r1.print();

        std::cout << "r2 = ";
        r2.print();

        Rational sum = r1 + r2;
        std::cout << "Сумма r1 + r2 = ";
        sum.print();

        Rational diff = r1 - r2;
        std::cout << "Разность r1 - r2 = ";
        diff.print();

        Rational prod = r1 * r2;
        std::cout << "Произведение r1 * r2 = ";
        prod.print();

        Rational quot = r1 / r2;
        std::cout << "Частное r1 / r2 = ";
        quot.print();

        if (r1 == r2) {
            std::cout << "r1 и r2 равны\n";
        }
        else {
            std::cout << "r1 и r2 не равны\n";
        }

        if (r1 > r2) {
            std::cout << "r1 больше r2\n";
        }
        else {
            std::cout << "r1 не больше r2\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}

#include <iostream>
#include <stdexcept>
#include <clocale>

template<typename T>
class Array {
private:
    T* data;
    size_t size;   // размер массива
    size_t count;  // количество занятых элементов

    void resize(size_t newSize) {
        T* newData = new T[newSize];
        for (size_t i = 0; i < count; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

public:
    Array(size_t size) : size(size), count(0) {
        data = new T[size];
    }

    // конструктор копирования
    Array(const Array& other) : size(other.size), count(other.count) {
        data = new T[size];
        for (size_t i = 0; i < count; ++i) {
            data[i] = other.data[i];
        }
    }

    // оператор присваивания
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            count = other.count;
            data = new T[size];
            for (size_t i = 0; i < count; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] data;
    }

    void input() {
        std::cout << "Введите количество элементов для ввода (не больше " << size << "): ";
        size_t n;
        std::cin >> n;
        if (n > size) {
            std::cerr << "Ошибка: количество элементов превышает размер массива.\n";
            return;
        }
        count = n;
        std::cout << "Введите " << n << " элементов:\n";
        for (size_t i = 0; i < n; ++i) {
            std::cin >> data[i];
        }
    }

    void output() const {
        std::cout << "Элементы массива: ";
        for (size_t i = 0; i < count; ++i) {
            std::cout << data[i] << ' ';
        }
        std::cout << '\n';
    }

    // Добавление элемента в конец занятой части массива
    void push_back(const T& element) {
        if (count == size) {
            // Расширяем массив
            resize(size * 2);
        }
        data[count++] = element;
    }

    Array merge(const Array& other) const {
        Array result(count + other.count);
        for (size_t i = 0; i < count; ++i) {
            result.data[result.count++] = data[i];
        }
        for (size_t i = 0; i < other.count; ++i) {
            result.data[result.count++] = other.data[i];
        }
        return result;
    }

    T sum() const {
        T total = T();
        for (size_t i = 0; i < count; ++i) {
            total += data[i];
        }
        return total;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Array<double> arr(5);
    arr.push_back(4.777);
    arr.push_back(2.5);
    arr.output();
    std::cout << "Сумма элементов: " << arr.sum() << '\n';
    return 0;
}

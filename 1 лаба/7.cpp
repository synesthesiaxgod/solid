#include <iostream>
#include <stdexcept>

class Array {
private:
    int* data;
    size_t size;   //  размер массива
    size_t count;  //колво занятых элементов

    void resize(size_t newSize) {
        int* newData = new int[newSize];
        for (size_t i = 0; i < count; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

public:
    
    Array(size_t size) : size(size), count(0) {
        data = new int[size];
    }

    // конструктор копирования
    Array(const Array& other) : size(other.size), count(other.count) {
        data = new int[size];
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
            data = new int[size];
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

    // добавка элемента в конец занятой части массива
    void push_back(int element) {
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

    int sum() const {
        int total = 0;
        for (size_t i = 0; i < count; ++i) {
            total += data[i];
        }
        return total;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Array arr1(5);
    arr1.input();
    arr1.output();

    arr1.push_back(10);
    std::cout << "После добавления элемента 10:\n";
    arr1.output();

    Array arr2(5);
    arr2.push_back(20);
    arr2.push_back(30);

    std::cout << "Второй массив:\n";
    arr2.output();

    Array merged = arr1.merge(arr2);
    std::cout << "Объединенный массив:\n";
    merged.output();

    std::cout << "Сумма элементов объединенного массива: " << merged.sum() << '\n';

    return 0;
}

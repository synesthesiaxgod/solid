#include "COne.h"
#include "CTwo.h"
#include "CThree.h"
#include "CFour.h"

void printAll(CTwo* arr[], int n);

int main() {
    // Создание объектов
    COne one1(3.14f, "Test1");
    COne one2(2.71f, "Test2");

    CTwo two("String in CTwo", one1);
    CThree three("String in CThree", one2, 42);
    CFour four("String in CFour", one1, 100, 9.81);

    // Тестирование методов
    one1.print();
    two.print();
    three.print();
    four.print();

    // Тестирование оператора присваивания
    COne oneCopy;
    oneCopy = one1;
    oneCopy.print();

    // Тестирование конструктора копирования
    CTwo twoCopy(two);
    twoCopy.print();

    // Создание массива указателей
    CTwo* arr[3];
    arr[0] = &two;
    arr[1] = &three;
    arr[2] = &four;

    // Вызов функции printAll
    printAll(arr, 3);

    return 0;
}

void printAll(CTwo* arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i]->print();
        std::cout << std::endl;
    }
}

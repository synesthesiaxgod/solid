#include <iostream>
#include <stdexcept>
#include <clocale>

template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& data) : data(data), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;  // указатель на первый элемент списка
    size_t count;   // количество элементов в списке

public:
    // Конструктор по умолчанию
    LinkedList() : head(nullptr), count(0) {}

    // Деструктор
    ~LinkedList() {
        clear();
    }

    // Добавление элемента в начало списка
    void push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        ++count;
    }

    // Добавление элемента в конец списка
    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        ++count;
    }

    // Удаление первого элемента списка
    void pop_front() {
        if (!head) {
            throw std::out_of_range("Список пуст");
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        --count;
    }

    // Удаление последнего элемента списка
    void pop_back() {
        if (!head) {
            throw std::out_of_range("Список пуст");
        }
        if (!head->next) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* current = head;
            while (current->next->next) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        --count;
    }

    // Вывод элементов списка
    void display() const {
        Node<T>* current = head;
        std::cout << "Элементы списка: ";
        while (current) {
            std::cout << current->data << ' ';
            current = current->next;
        }
        std::cout << '\n';
    }

    // Очистка списка
    void clear() {
        while (head) {
            pop_front();
        }
    }

    // Получение количества элементов в списке
    size_t size() const {
        return count;
    }

    // Поиск элемента в списке
    bool find(const T& value) const {
        Node<T>* current = head;
        while (current) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    // Слияние двух списков
    void merge(const LinkedList& other) {
        if (!other.head)
            return;
        Node<T>* current = other.head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

    // Вычисление суммы элементов списка (только для числовых типов)
    T sum() const {
        if (!std::is_arithmetic<T>::value) {
            throw std::logic_error("Операция sum доступна только для числовых типов");
        }
        T total = T();
        Node<T>* current = head;
        while (current) {
            total += current->data;
            current = current->next;
        }
        return total;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    LinkedList<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);

    std::cout << "Первый список:\n";
    list1.display();

    LinkedList<int> list2;
    list2.push_front(5);
    list2.push_front(3);
    list2.push_front(1);

    std::cout << "Второй список:\n";
    list2.display();

    list1.merge(list2);
    std::cout << "Объединенный список:\n";
    list1.display();

    std::cout << "Сумма элементов объединенного списка: " << list1.sum() << '\n';

    // Пример с нечисловым типом данных
    LinkedList<std::string> stringList;
    stringList.push_back("Привет");
    stringList.push_back("мир");
    std::cout << "Список строк:\n";
    stringList.display();

    return 0;
}

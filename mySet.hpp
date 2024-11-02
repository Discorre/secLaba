#ifndef MYSET_HPP
#define MYSET_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    int size;
    template <typename U>
    friend class MySet;

public:
    List() : head(nullptr), size(0) {}

    // Добавление элемента в конец списка
    void add(T element) {
        Node* newNode = new Node(element);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    // Удаление элемента из списка
    void remove(T element) {
        if (!head) return;

        if (head->data == element) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != element) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
        }
    }

    // Проверка наличия элемента в списке
    bool contains(T element) const {
        Node* current = head;
        while (current) {
            if (current->data == element) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Получение размера списка
    int getSize() const {
        return size;
    }

    // Очистка списка
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    // Печать списка (для отладки)
    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    Node* getHead() const {
        return head;
    }

    // Функция поиска элемента на заданной позиции
    bool find(int index, T value) const {
        if (index < 0 || index >= size) {
            return false; // Индекс выходит за пределы списка
        }

        Node* current = head;
        int currentIndex = 0;

        while (current) {
            if (currentIndex == index) {
                return current->data == value;
            }
            current = current->next;
            currentIndex++;
        }

        return false; // Элемент не найден
    }

    // Деструктор для очистки памяти
    ~List() {
        clear();
    }
};

template <typename T>
class MySet {
private:
    List<T> list; // Используем MyList для хранения уникальных элементов

public:
    // Добавление элемента
    void SETADD(T element) {
        if (!list.contains(element)) { // Добавляем только если элемент отсутствует
            list.add(element);
        }
    }

    // Удаление элемента
    void SETDEL(T element) {
        if (list.contains(element)) { // Удаляем только если элемент существует
            list.remove(element);
        } else {
            std::cout << "Элемент " << element << " не найден в множестве." << std::endl;
        }
    }

    // Проверка наличия элемента
    bool SET_AT(T element) const {
        return list.contains(element);
    }

    T SETGET(int index) const {
        if (index < 0 || index >= list.getSize()) {
            throw std::out_of_range("Индекс вне диапазона");
        }

        typename List<T>::Node* current = list.head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    // Оператор сравнения
    bool operator==(const MySet<T>& other) const {
        // Сравниваем размеры множеств
        if (list.getSize() != other.list.getSize()) {
            return false;
        }

        // Проверяем, содержатся ли все элементы из current в other
        for (int i = 0; i < list.getSize(); ++i) {
            if (!other.SET_AT(list.get(i))) {
                return false; // Если элемент не найден, множества не равны
            }
        }

        return true; // Все элементы совпадают
    }

    // Загрузка множества из файла
    void loadFromFile(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile.is_open()) {
            throw std::runtime_error("Не удалось открыть файл для чтения");
        }

        T element;
        while (infile >> element) {
            SETADD(element);
        }

        infile.close();
    }

    // Выгрузка множества в файл
    void saveToFile(const std::string& filename) const {
        std::ofstream outfile(filename);
        if (!outfile.is_open()) {
            throw std::runtime_error("Не удалось открыть файл для записи");
        }

        typename List<T>::Node* current = list.head;
        while (current) {
            outfile << current->data << std::endl;
            current = current->next;
        }

        outfile.close();
    }

    // Печать множества
    void print() const {
        std::cout << "Множество: ";
        list.print();
    }

    // Получение размера множества
    int getSize() const {
        return list.getSize();
    }

    // Очистка множества
    void clear() {
        list.clear();
    }
};

#endif // MYSET_HPP
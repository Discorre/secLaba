#ifndef MYSET_HPP
#define MYSET_HPP

#include <iostream>

// Класс односвязного списка
template <typename T>
class List {
private:
    struct Node {
        T data;          // Данные узла
        Node* next;     // Указатель на следующий узел

        Node(T value) : data(value), next(nullptr) {}
    };


    Node<T>* head;  // Указатель на голову списка

public:
    List() : head(nullptr) {}

    // Добавление элемента в конец списка
    void add(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Удаление элемента
    void remove(T value) {
        if (!head) return;

        // Удаление головы
        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node<T>* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // Проверка наличия элемента
    bool contains(T value) {
        Node<T>* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Освобождение памяти
    ~List() {
        Node<T>* current = head;
        while (current) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

// Класс множества
template <typename T>
class MySet {
private:
    List<T> list; // Список для хранения уникальных элементов

public:
    // Добавление элемента
    void add(T element) {
        if (!list.contains(element)) { // Добавляем только если элемент отсутствует
            list.add(element);
        }
    }

    // Удаление элемента
    void remove(T element) {
        if (list.contains(element)) { // Удаляем только если элемент существует
            list.remove(element);
        } else {
            std::cout << "Элемент " << element << " не найден в множестве." << std::endl;
        }
    }

    // Проверка наличия элемента
    bool contains(T element) {
        return list.contains(element);
    }

    

    // Печать множества
    void print() {
        std::cout << "Множество: { ";
        for (int i = 0; i < 100; ++i) { // Можно перебрать диапазон значений
            if (contains(i)) {
                std::cout << i << " ";
            }
        }
        std::cout << "}" << std::endl;
    }
};

#endif // MYSET_HPP
#ifndef MYBINARYSEARCHTREE_HPP
#define MYBINARYSEARCHTREE_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "myQueue.hpp"

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
private:
    Node<T>* root;  // Корень дерева

    // Вспомогательная функция для вставки элемента
    Node<T>* insert(Node<T>* node, T value) {
        if (node == nullptr) {
            return new Node<T>(value); // Указываем, что Node - это Node<T>
        }

        // Вставляем элемент в подходящее место (меньше - влево, больше - вправо)
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Вспомогательная функция для поиска элемента
    bool search(Node<T>* node, T value) const {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }

        // Поиск в левом и правом поддереве
        if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    // Вспомогательная функция для удаления элемента (удаление узлов с учетом 2 потомков)
    Node<T>* deleteNode(Node<T>* node, T value) {
        if (node == nullptr) {
            return nullptr;
        }

        // Поиск удаляемого узла
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Если у узла нет потомков
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            // Если только один потомок
            if (node->left == nullptr) {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            }

            // Если 2 потомка, находим минимальное значение в правом поддереве
            Node<T>* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = deleteNode(node->right, minNode->data);
        }

        return node;
    }

    // Вспомогательная функция для поиска минимального значения
    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // In-order обход для чтения
    void inOrder(Node<T>* node) const {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Сохранение дерева по уровням в файл
    void saveLevelOrder(Node<T>* node, std::ofstream& file) const {
        if (node == nullptr) {
            return;
        }

        Queue<Node<T>*> q;
        q.Q_PUSH(node);

        while (!q.isEmpty()) {
            Node<T>* current = q.Q_POP();
            if (current == nullptr) {
                file << "# ";
            } else {
                file << current->data << " ";
                q.Q_PUSH(current->left);
                q.Q_PUSH(current->right);
            }
        }
    }

    // Загрузка дерева по уровням из файла
    Node<T>* loadLevelOrder(std::ifstream& file) {
        std::string val;
        if (!(file >> val) || val == "#") {
            return nullptr;
        }

        Node<T>* root = new Node<T>(std::stoi(val));
        Queue<Node<T>*> q;
        q.Q_PUSH(root);

        while (!q.isEmpty()) {
            Node<T>* current = q.Q_POP();
            if (!(file >> val)) {
                break;
            }
            if (val != "#") {
                current->left = new Node<T>(std::stoi(val));
                q.Q_PUSH(current->left);
            }
            if (!(file >> val)) {
                break;
            }
            if (val != "#") {
                current->right = new Node<T>(std::stoi(val));
                q.Q_PUSH(current->right);
            }
        }

        return root;
    }

public:
    // Конструктор
    BinarySearchTree() : root(nullptr) {}

    // Деструктор (рекурсивное удаление всех узлов)
    ~BinarySearchTree() {
        clear(root);
    }

    // Очистка дерева
    void clear(Node<T>* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    // Операция TINSERT — добавление элемента
    void TINSERT(T value) {
        root = insert(root, value);
    }

    // Операция TDEL — удаление элемента
    void TDEL(T value) {
        root = deleteNode(root, value);
    }

    // Операция TGET — поиск элемента
    bool TGET(T value) const {
        return search(root, value);
    }

    // Чтение дерева (in-order traversal)
    void print() const {
        inOrder(root);
        std::cout << std::endl;
    }

    // Сохранение дерева в файл по уровням
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file for writing");
        }
        saveLevelOrder(root, file);  // Сохраняем дерево в level-order обходе
        file.close();
    }

    // Загрузка дерева из файла по уровням
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file for reading");
        }
        clear(root);  // Очищаем текущее дерево перед загрузкой
        root = loadLevelOrder(file);  // Загружаем дерево из файла
        file.close();
    }

    // Вывод корневого элемента
    void printRoot() const {
        if (root != nullptr) {
            std::cout << "Root element: " << root->data << std::endl;
        } else {
            std::cout << "Tree is empty, no root element." << std::endl;
        }
    }

    Node<T>* getRoot(){
        if (root != nullptr){
            return root;
        } else {
            std::cout << "Net" << std::endl;
        }
    }
};

#endif
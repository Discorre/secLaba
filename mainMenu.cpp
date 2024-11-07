#include <iostream>
#include <stdexcept>
#include <fstream>
#include "myListKV.hpp"
#include "myArray.hpp"
#include "mySinglyLinkedList.hpp"
#include "myStack.hpp"
#include "myHashMap.hpp"
#include "myBinarySearchTree.hpp"
#include "mySet.hpp"
#include "Zadanie1.hpp"
#include "Zadanie3.hpp"
#include "Zadanie6.hpp"

static void Zad1Menu(){
    std::string expression;
    std::cout << "Введите математическое выражение (например, 3 + 4 * 2 + 5: ";
    std::getline(std::cin, expression);
    try {
        // Преобразование инфиксного выражения в постфиксное
        std::string postfix = infixToPostfix(expression);
        std::cout << "Постфиксная форма: " << postfix << std::endl;

        // Вычисление результата постфиксного выражения
        int result = evaluatePostfix(postfix);
        std::cout << "Результат: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}

static void Zad2Menu(){
    MySet<int> mySet; // Создание множества
    std::string command;
    int element;

    while (true) {
        std::cout << "Введите команду (add, delete, contains, size, load, save, back): ";
        std::cin >> command;

        if (command == "add") {
            std::cout << "Введите элемент для добавления: ";
            std::cin >> element;
            mySet.SETADD(element);
            std::cout << "Элемент " << element << " добавлен." << std::endl;

        } else if (command == "delete") {
            std::cout << "Введите элемент для удаления: ";
            std::cin >> element;
            mySet.SETDEL(element);

        } else if (command == "contains") {
            std::cout << "Введите элемент для проверки: ";
            std::cin >> element;
            if (mySet.SET_AT(element)) {
                std::cout << "Элемент " << element << " присутствует в множестве." << std::endl;
            } else {
                std::cout << "Элемент " << element << " отсутствует в множестве." << std::endl;
            }

        } else if (command == "size") {
            std::cout << "Размер множества: " << mySet.getSize() << std::endl;

        } else if (command == "load") {
            std::string filename;
            std::cout << "Введите имя файла для загрузки: ";
            std::cin >> filename;
            try {
                mySet.loadFromFile(filename);
                std::cout << "Множество загружено из файла " << filename << "." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

        } else if (command == "save") {
            std::string filename;
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            try {
                mySet.saveToFile(filename);
                std::cout << "Множество сохранено в файл " << filename << "." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

        } else if (command == "back") {
            std::cout << "Выход из программы." << std::endl;
            break;

        } else {
            std::cout << "Неизвестная команда. Попробуйте снова." << std::endl;
        }

        // Опционально: вывод текущего состояния множества
        mySet.print();
    }
}

static void Zad3Menu(){
    MySet<int> mySet; // Создание множества
    std::string command;
    int element;

    while (true) {
        std::cout << "Введите команду (add, delete, contains, size, load, save, partit, back): ";
        std::cin >> command;

        if (command == "add") {
            std::cout << "Введите элемент для добавления: ";
            std::cin >> element;
            mySet.SETADD(element);
            std::cout << "Элемент " << element << " добавлен." << std::endl;

        } else if (command == "delete") {
            std::cout << "Введите элемент для удаления: ";
            std::cin >> element;
            mySet.SETDEL(element);

        } else if (command == "contains") {
            std::cout << "Введите элемент для проверки: ";
            std::cin >> element;
            if (mySet.SET_AT(element)) {
                std::cout << "Элемент " << element << " присутствует в множестве." << std::endl;
            } else {
                std::cout << "Элемент " << element << " отсутствует в множестве." << std::endl;
            }

        } else if (command == "size") {
            std::cout << "Размер множества: " << mySet.getSize() << std::endl;

        } else if (command == "load") {
            std::string filename;
            std::cout << "Введите имя файла для загрузки: ";
            std::cin >> filename;
            try {
                mySet.loadFromFile(filename);
                std::cout << "Множество загружено из файла " << filename << "." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

        } else if (command == "save") {
            std::string filename;
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            try {
                mySet.saveToFile(filename);
                std::cout << "Множество сохранено в файл " << filename << "." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

        } else if(command == "partit"){
            std::cout << "Введите сумму для разделения: ";
            std::cin >> element;
            try {
                partitionSet(mySet, element);
            } catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
        } else if (command == "back") {
            std::cout << "Выход из программы." << std::endl;
            break;

        } else {
            std::cout << "Неизвестная команда. Попробуйте снова." << std::endl;
        }

        // Опционально: вывод текущего состояния множества
        mySet.print();
    }
}

static void Zad4Menu(){
    MyArray<std::string> myArray; // Создание массива
    std::string command;
    int index;
    std::string element;

    while (true) {
        std::cout << "Введите команду (add, insert, delete, get, size, load, save, print, generate, clear, back): ";
        std::cin >> command;

        if (command == "add") {
            std::cout << "Введите элемент для добавления: ";
            std::cin >> element;
            myArray.MPUSH(element);
            std::cout << "Элемент " << element << " добавлен." << std::endl;

        } else if (command == "insert") {
            std::cout << "Введите индекс и элемент для вставки: ";
            std::cin >> index >> element;
            try {
                myArray.MPUSH(index, element);
                std::cout << "Элемент " << element << " вставлен на позицию " << index << "." << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

        } else if (command == "delete") {
            std::cout << "Введите индекс элемента для удаления: ";
            std::cin >> index;
            try {
                myArray.MDEL(index);
                std::cout << "Элемент на позиции " << index << " удалён." << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

        } else if (command == "get") {
            std::cout << "Введите индекс элемента для получения: ";
            std::cin >> index;
            try {
                element = myArray.MGET(index);
                std::cout << "Элемент на позиции " << index << ": " << element << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

        } else if (command == "size") {
            std::cout << "Размер массива: " << myArray.lengtharr() << std::endl;

        } else if (command == "load") {
            std::string filename;
            std::cout << "Введите имя файла для загрузки: ";
            std::cin >> filename;
            try {
                myArray.loadFromFile(filename);
                std::cout << "Массив загружен из файла " << filename << "." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

        } else if (command == "save") {
            std::string filename;
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            try {
                myArray.saveToFile(filename);
                std::cout << "Массив сохранён в файл " << filename << "." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

        } else if (command == "print") {
            std::cout << "Элементы массива: ";
            myArray.print();


        } else if (command == "clear") {
            myArray.clear();
            std::cout << "Массив очищен." << std::endl;

        } else if(command == "generate"){
            myArray.generateSubsets();
        } else if (command == "back") {
            std::cout << "Выход из программы." << std::endl;
            break;

        } else {
            std::cout << "Неизвестная команда. Попробуйте снова." << std::endl;
        }
    }
}

static void Zad5Menu(){
    BinarySearchTree<int> tree;

    std::string choice;
    int value;
    std::string filename;

    while (true) {
        std::cout << "Введите команду (add, delete, contains, isfull, print, save, load, back): ";
        std::cin >> choice;

        if(choice == "add") {
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            tree.TINSERT(value);
            std::cout << "Элемент добавлен." << std::endl;

        } else if (choice == "delete") {
            std::cout << "Введите значение для удаления: ";
            std::cin >> value;
            tree.TDEL(value);
            std::cout << "Элемент удален." << std::endl;

        } else if (choice == "contains"){
            std::cout << "Введите значение для поиска: ";
            std::cin >> value;
            if (tree.TGET(value)) {
                std::cout << "Элемент найден в дереве." << std::endl;
            } else {
                std::cout << "Элемент не найден в дереве." << std::endl;
            }


        } else if (choice == "print"){
            std::cout << "Дерево (in-order): ";
            tree.print();

            tree.printRoot();

        } else if (choice == "save"){
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            try {
                tree.saveToFile(filename);
                std::cout << "Дерево сохранено в файл " << filename << "." << std::endl;
            } catch (const std::runtime_error& e) {
                std::cerr << "Ошибка при сохранении: " << e.what() << std::endl;
            }

        } else if (choice == "load"){
            std::cout << "Введите имя файла для загрузки: ";
            std::cin >> filename;
            try {
                tree.loadFromFile(filename);
                std::cout << "Дерево загружено из файла " << filename << "." << std::endl;
            } catch (const std::runtime_error& e) {
                std::cerr << "Ошибка при загрузке: " << e.what() << std::endl;
            }

        } else if (choice == "back"){
            std::cout << "Выход из программы." << std::endl;
            return;

        } else {
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
        }        
    }
}

static void Zad6Menu(){
    MyHashMap<std::string, std::string> myHashMap; // Создание хэш-таблицы
    std::string command;
    std::string key;
    std::string value;

    while (true) {
        std::cout << "Введите команду (add, remove, get, load, save, print, isomorfik, clear, back): ";
        std::cin >> command;

        if (command == "add") {
            std::cout << "Введите ключ и значение для добавления: ";
            std::cin >> key >> value;
            myHashMap.HSET(key, value);
            std::cout << "Элемент добавлен." << std::endl;

        } else if (command == "remove") {
            std::cout << "Введите ключ для удаления: ";
            std::cin >> key;
            myHashMap.HDEL(key);

        } else if (command == "get") {
            std::cout << "Введите ключ для поиска: ";
            std::cin >> key;
            try {
                value = myHashMap.HGET(key);
                std::cout << "Значение для ключа " << key << ": " << value << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

        } else if (command == "load") {
            std::string filename;
            std::cout << "Введите имя файла для загрузки: ";
            std::cin >> filename;
            try {
                myHashMap.loadFromFile(filename);
                std::cout << "Хэш-таблица загружена из файла " << filename << "." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

        } else if (command == "save") {
            std::string filename;
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            try {
                myHashMap.saveToFile(filename);
                std::cout << "Хэш-таблица сохранена в файл " << filename << "." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
        } else if (command == "isomorfik"){
            std::cout << "Введите первую строку: ";
            std::cin >> key;
            std::cout << "Введите вторую строку: ";
            std::cin >> value;
            if(areIsomorphic(key, value)){
                std::cout << "Строки изоморфны" << std::endl;
            } else {
                std::cout << "Строки не изоморфны" << std::endl;
            }
        } else if (command == "print") {
            myHashMap.print();

        } else if (command == "clear") {
            myHashMap.clear();
            std::cout << "Хэш-таблица очищена." << std::endl;

        } else if (command == "back") {
            std::cout << "Выход из программы." << std::endl;
            break;

        } else {
            std::cout << "Неизвестная команда. Попробуйте снова." << std::endl;
        }
    }
}

static void mainMenu(){
    std::string commandMain;
    while(true){
        std::cout << "Введите номер задания(1-6) или exit для выхода из программы: ";
        std::getline(std::cin, commandMain);
        if(commandMain == "1"){
            Zad1Menu();
        } else if (commandMain == "2"){
            Zad2Menu();
        } else if (commandMain == "3"){
            Zad3Menu();
        } else if (commandMain == "4"){
            Zad4Menu();
        } else if (commandMain == "5"){
            Zad5Menu();
        } else if (commandMain == "6"){
            Zad6Menu();
        } else if (commandMain == "exit"){
            break;
        }
    }
    
}

int main() {
    system("chcp 65001");
    mainMenu();
    return 0;
}
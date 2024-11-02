#include <iostream>
#include <stdexcept>
#include <fstream>
#include "myListKV.hpp"
#include "myArray.hpp"
#include "mySinglyLinkedList.hpp"
#include "myStack.hpp"
#include "myHashMap.hpp"
#include "myFullBinaryTree.hpp"
#include "mySet.hpp"
#include "Zadanie1.hpp"
#include "Zadanie3.hpp"
#include "Zadanie6.hpp"

static void Zad1Menu(){
    std::string expression;
    std::cout << "Введите математическое выражение (например, 3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3): ";
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

}

int main() {
    system("chcp 65001");
    Zad1Menu();

    MySet<int> mySet;

    mySet.loadFromFile("123.txt");
    mySet.print();
    /*MySet<int> mySet;
    mySet.SETADD(4);
    mySet.SETADD(10);
    mySet.SETADD(5);
    mySet.SETADD(1);
    mySet.SETADD(3);
    mySet.SETADD(7);

    MySet<int> mySet2;
    mySet2.SETADD(4);
    mySet2.SETADD(10);
    mySet2.SETADD(5);
    mySet2.SETADD(1);
    mySet2.SETADD(3);
    mySet2.SETADD(7);

    mySet.print();
    int subsetSum = 10; // Укажите нужную сумму для каждого подмножества

    partitionSet(mySet, subsetSum);
    
    mySet.print();*/

    return 0;

    

}
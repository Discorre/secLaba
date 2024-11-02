#ifndef ZADANIE1_HPP
#define ZADANIE1_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "myStack.hpp"

// Функция для определения приоритета оператора
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Функция для выполнения операции
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Функция для преобразования выражения в обратную польскую запись
std::string infixToPostfix(const std::string& expression) {
    MyStack<char> operators;
    std::stringstream output;
    std::string token;
    int i = 0;

    while (i < expression.length()) {
        char c = expression[i];

        // Если текущий символ - число, добавляем его в выходную строку
        if (isdigit(c)) {
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            output << num << " ";
            continue;
        }

        // Если текущий символ - открывающая скобка, добавляем её в стек
        if (c == '(') {
            operators.SPUSH(c);
        }
        // Если текущий символ - закрывающая скобка, выталкиваем операторы из стека в выходную строку
        else if (c == ')') {
            while (operators.size() > 0 && operators.SPOP() != '(') {
                output << operators.SPOP() << " ";
                operators.SDEL();
            }
            if (operators.size() > 0) {
                operators.SDEL(); // Удаляем '('
            }
        }
        // Если текущий символ - оператор, выталкиваем операторы с более высоким или равным приоритетом
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (operators.size() > 0 && precedence(operators.SPOP()) >= precedence(c)) {
                output << operators.SPOP() << " ";
                operators.SDEL();
            }
            operators.SPUSH(c);
        }

        i++;
    }

    // Выталкиваем оставшиеся операторы из стека в выходную строку
    while (operators.size() > 0) {
        output << operators.SPOP() << " ";
        operators.SDEL();
    }

    return output.str();
}

// Функция для вычисления выражения в обратной польской записи
int evaluatePostfix(const std::string& postfix) {
    MyStack<int> values;
    std::stringstream ss(postfix);
    std::string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            values.SPUSH(std::stoi(token));
        } else {
            int b = values.SPOP();
            values.SDEL();
            int a = values.SPOP();
            values.SDEL();
            values.SPUSH(applyOp(a, b, token[0]));
        }
    }

    return values.SPOP();
}

#endif
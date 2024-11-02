#ifndef ZADANIE3_HPP
#define ZADANIE3_HPP
#include <iostream>
#include "MySet.hpp" // Предполагаем, что MySet и List определены в этом заголовочном файле

bool findNonOverlappingSubsets(MySet<int>& set, int subsetSum, int currentSum, MySet<int>& currentSet) {
    // Если текущее подмножество заполнено, выводим его и удаляем элементы
    if (currentSum == subsetSum) {
        std::cout << "Найдено подмножество: ";
        currentSet.print();

        // Удаляем элементы текущего подмножества из исходного множества
        for (int i = 0; i < currentSet.getSize(); ++i) {
            set.SETDEL(currentSet.SETGET(i));
        }
        return true; // Указываем, что мы нашли подмножество
    }

    // Перебор элементов для добавления в текущее подмножество
    for (int i = 0; i < set.getSize(); ++i) {
        int element = set.SETGET(i);
        
        // Проверяем, был ли элемент уже добавлен в текущее подмножество
        if (currentSet.SET_AT(element)) continue;

        // Добавляем элемент в текущее подмножество
        currentSet.SETADD(element);

        // Рекурсивный вызов для поиска подмножеств
        if (findNonOverlappingSubsets(set, subsetSum, currentSum + element, currentSet)) {
            return true; // Если нашлось решение, возвращаемся
        }

        // Откат, если не удалось найти подходящее подмножество
        currentSet.SETDEL(element);
    }

    return false; // Возвращаем false, если подмножества не найдены
}

void partitionSet(MySet<int>& set, int subsetSum) {
    // Проверка на возможность деления
    int totalSum = 0;
    for (int i = 0; i < set.getSize(); ++i) {
        totalSum += set.SETGET(i);
    }

    if (totalSum % subsetSum != 0 || totalSum < subsetSum) {
        std::cout << "Множество не может быть разделено на подмножества с равной суммой." << std::endl;
        return;
    }

    // Повторяем поиск подмножеств, пока они находятся
    MySet<int> currentSet;

    MySet<int> InpSetClone;
    // Переносим данные из set в currentSet
    for (int i = 0; i < set.getSize(); ++i) {
        InpSetClone.SETADD(set.SETGET(i));
    }

    while (true) {
        bool foundSubset = findNonOverlappingSubsets(InpSetClone, subsetSum, 0, currentSet);
        if (!foundSubset) {
            break; // Если не найдено больше подмножеств, выходим из цикла
        }
        currentSet.clear(); // Очищаем текущее подмножество для поиска следующего
    }

    // Проверяем, найдены ли подмножества
    if (currentSet.getSize() == 0) {
        std::cout << "Не удалось найти непересекающиеся подмножества." << std::endl;
    }
}

#endif // ZADANIE3_HPP
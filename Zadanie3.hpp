#ifndef ZADANIE3_HPP
#define ZADANIE3_HPP

#include "mySet.hpp"
#include <iostream>

template <typename T>
bool canPartitionHelper(MySet<T>& set, int targetSum, MySet<MySet<T>>& subsets, int currentSubsetIndex, T* currentSubsetSum, T* elements, int size) {
    if (currentSubsetIndex == subsets.getSize()) {
        return true;
    }

    for (int i = 0; i < size; ++i) {
        if (elements[i] != -1) {
            T value = elements[i];
            if (currentSubsetSum[currentSubsetIndex] + value <= targetSum) {
                currentSubsetSum[currentSubsetIndex] += value;
                elements[i] = -1;
                subsets.SETADD(MySet<T>());
                subsets.SET_AT(currentSubsetIndex).SETADD(value);

                if (canPartitionHelper(set, targetSum, subsets, currentSubsetIndex, currentSubsetSum, elements, size)) {
                    return true;
                }

                currentSubsetSum[currentSubsetIndex] -= value;
                elements[i] = value;
                subsets.SETDEL(subsets.getSize() - 1);
            }
        }
    }

    return false;
}

template <typename T>
bool canPartition(MySet<T>& set, int k, MySet<MySet<T>>& subsets) {
    int size = set.getSize();
    if (size < k) {
        return false;
    }

    T totalSum = 0;
    T* elements = new T[size];
    int index = 0;

    // Заполняем массив элементов из множества
    for (int i = 0; i < size; ++i) {
        T value;
        for (int j = 0; j < set.getSize(); ++j) {
            if (set.SET_AT(j)) {
                value = j;
                set.SETDEL(j);
                break;
            }
        }
        totalSum += value;
        elements[index++] = value;
    }

    if (totalSum % k != 0) {
        delete[] elements;
        return false;
    }

    T targetSum = totalSum / k;
    T* currentSubsetSum = new T[k]();

    bool result = canPartitionHelper(set, targetSum, subsets, 0, currentSubsetSum, elements, size);

    delete[] elements;
    delete[] currentSubsetSum;

    return result;
}

#endif // ZADANIE3_HPP
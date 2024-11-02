#ifndef ZADANIE6_HPP
#define ZADANIE6_HPP

#include <iostream>
#include <string>
#include "myHashMap.hpp" // Ваш класс MyHashMap

// Функция для проверки изоморфности строк
bool areIsomorphic(const std::string& a, const std::string& b) {
    if (a.length() != b.length()) {
        return false; // Если длины не равны, строки не могут быть изоморфными
    }

    MyHashMap<std::string, std::string> mapAB; // Отображение из символов a в b
    MyHashMap<std::string, std::string> mapBA; // Отображение из символов b в a

    for (size_t i = 0; i < a.length(); ++i) {
        std::string charA(1, a[i]); // Преобразуем символ в строку
        std::string charB(1, b[i]); // Преобразуем символ в строку

        // Проверяем отображение из a в b
        try {
            if (mapAB.HGET(charA) != charB) {
                return false; // Если уже отображено, но не совпадает
            }
        } catch (std::out_of_range&) {
            mapAB.HSET(charA, charB); // Создаем новое отображение
        }

        // Проверяем отображение из b в a
        try {
            if (mapBA.HGET(charB) != charA) {
                return false; // Если уже отображено, но не совпадает
            }
        } catch (std::out_of_range&) {
            mapBA.HSET(charB, charA); // Создаем новое отображение
        }
    }

    return true; // Все символы успешно сопоставлены
}

#endif // ZADANIE6_HPP
#pragma once
#include <cstdio>

// Структура для збереження грошових сум
struct Money {
    int grn;
    short int kop;
};

// Прототипи функцій
Money createMoney(int grn, short int kop);
Money normalize(Money m);
Money add(Money m1, Money m2);
Money multiply(Money m, int count);
Money roundToTenKop(Money m);
void printMoney(Money m);

// Функція для читання файлу та обчислення чеку
void processFile(FILE* file);
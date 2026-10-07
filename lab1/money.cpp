#include "money.h"
#include <cstdio>

// Створення суми та її автоматична нормалізація
Money createMoney(int grn, short int kop) {
    Money m = { grn, kop };
    return normalize(m);
}

// Переведення копійок (якщо їх >= 100) у гривні
Money normalize(Money m) {
    if (m.kop >= 100) {
        m.grn += m.kop / 100;
        m.kop %= 100;
    }
    return m;
}

// Додавання двох грошових сум
Money add(Money m1, Money m2) {
    Money result;
    result.grn = m1.grn + m2.grn;
    result.kop = m1.kop + m2.kop;
    return normalize(result);
}

// Множення ціни на кількість товару
Money multiply(Money m, int count) {
    Money result;
    result.grn = m.grn * count;
    result.kop = m.kop * count;
    return normalize(result);
}

// Заокруглення копійок за правилами НБУ (до 10 коп.)
Money roundToTenKop(Money m) {
    m = normalize(m);
    
    int totalKop = m.grn * 100 + m.kop;
    int remainder = totalKop % 10;

    if (remainder < 5) {
        totalKop -= remainder;
    } else {
        totalKop += (10 - remainder);
    }

    m.grn = totalKop / 100;
    m.kop = totalKop % 100;
    return m;
}

// Виведення суми на екран
void printMoney(Money m) {
    printf("%d грн %02d коп.", m.grn, m.kop);
}

// Зчитування файлу та підрахунок чеку
void processFile(FILE* file) {
    Money totalSum = { 0, 0 };
    int grn = 0;
    short int kop = 0;
    int count = 0;

    printf("--- Зчитані товари з файлу ---\n");

    while (fscanf_s(file, "%d %hd %d", &grn, &kop, &count) == 3) {
        Money itemPrice = createMoney(grn, kop);
        Money itemTotal = multiply(itemPrice, count);

        printf("Ціна: ");
        printMoney(itemPrice);
        printf(" | Кількість: %d шт | Разом: ", count);
        printMoney(itemTotal);
        printf("\n");

        totalSum = add(totalSum, itemTotal);
    }

    fclose(file);

    Money roundedSum = roundToTenKop(totalSum);

    printf("\n-----------------------------------\n");
    printf("Загальна сума чеку: ");
    printMoney(totalSum);
    printf("\n");

    printf("Сума до сплати (із заокругленням): ");
    printMoney(roundedSum);
    printf("\n");
}
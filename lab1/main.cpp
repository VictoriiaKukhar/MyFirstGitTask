#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "money.h"

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    setlocale(LC_ALL, ".UTF-8");

    FILE* my_file = NULL;

    fopen_s(&my_file, "input.txt", "r");

    if (my_file == NULL) {
        printf("Помилка: не вдалося відкрити файл input.txt!\n");
        return 1;
    }

    processFile(my_file);

    return 0;
}
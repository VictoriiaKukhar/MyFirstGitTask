#include <iostream>
#include <windows.h>
#include "triangle.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001); 

    // Створюємо трикутник із вершинами (0,0), (4,0), (0,3)
    Triangle t = { {0, 0}, {4, 0}, {0, 3} };

    cout << "Периметр трикутника: " << getPerimeter(t) << endl;
    cout << "Площа трикутника: " << getArea(t) << endl;

    // Створюємо 2 точки для перевірки
    Point pInside = { 1, 1 };
    Point pOutside = { 5, 5 };

    // Перевірка першої точки
    if (isPointInside(t, pInside)) {
        cout << "Точка (1, 1) знаходиться ВСЕРЕДИНІ" << endl;
    } else {
        cout << "Точка (1, 1) ЗОВНІ" << endl;
    }

    // Перевірка другої точки
    if (isPointInside(t, pOutside)) {
        cout << "Точка (5, 5) знаходиться ВСЕРЕДИНІ" << endl;
    } else {
        cout << "Точка (5, 5) ЗОВНІ" << endl;
    }

    return 0;
}
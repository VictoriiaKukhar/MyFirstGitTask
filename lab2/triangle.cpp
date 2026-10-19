#include "triangle.h"
#include <cmath>

// 1. Відстань між двома точками за формулою
double distance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// 2. Периметр — сума довжин 3 сторін
double getPerimeter(Triangle t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    
    return a + b + c;
}

// 3. Площа за формулою Герона
double getArea(Triangle t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double p = (a + b + c) / 2.0; // Півпериметр
    
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// 4. Перевірка: чи точка всередині трикутника
bool isPointInside(Triangle t, Point p) {
    double sMain = getArea(t); // Площа всього трикутника

    // Створюємо 3 трикутники з точкою P
    Triangle t1 = { p, t.A, t.B };
    Triangle t2 = { p, t.B, t.C };
    Triangle t3 = { p, t.C, t.A };

    // Сума площ 3 малих трикутників
    double sSum = getArea(t1) + getArea(t2) + getArea(t3);

    // Порівнюємо площі (з мікропохибкою 0.0001 через double)
    return std::abs(sMain - sSum) < 0.0001;
}
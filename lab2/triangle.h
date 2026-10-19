#pragma once

// Точка на площині
struct Point {
    double x;
    double y;
};

// Трикутник з 3 точок
struct Triangle {
    Point A;
    Point B;
    Point C;
};

// 4 основні функції
double distance(Point p1, Point p2);
double getPerimeter(Triangle t);
double getArea(Triangle t);
bool isPointInside(Triangle t, Point p);
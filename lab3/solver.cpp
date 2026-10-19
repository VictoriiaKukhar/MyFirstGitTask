#include "solver.h"
#include <iostream>
#include <cmath>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif

// Конструктор за замовчуванням із початковими значеннями
EquationSolver::EquationSolver() {
    left = 0.0;
    right = 0.0;
    precision = 0.0001;
}

void EquationSolver::setRange(double l, double r) {
    left = l;
    right = r;
}

void EquationSolver::setPrecision(double tolerance) {
    precision = tolerance;
}

// Варіант 8: e^x - e^(-x) - 2 = 0
double EquationSolver::func(double x) {
    return std::exp(x) - std::exp(-x) - 2.0;
}

// Наближене обчислення похідної
double EquationSolver::derivative(double x) {
    double step = 0.000001;
    return (func(x + step) - func(x)) / step;
}

// Метод ділення відрізка навпіл
void EquationSolver::bisection() {
    if (func(left) * func(right) > 0) {
        std::cout << "На цьому відрізку немає зміни знака функції." << std::endl;
        return;
    }

    double lo = left;
    double hi = right;
    int iterations = 0;

    while (std::abs(lo - hi) > precision) {
        double mid = (lo + hi) / 2.0;
        iterations++;

        if (func(lo) * func(mid) < 0) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    double answer = (lo + hi) / 2.0;
    std::cout << "[Ділення навпіл] x = " << answer << std::endl;
    std::cout << "[Ділення навпіл] Кількість ітерацій = " << iterations << std::endl;
}

// Метод Ньютона
void EquationSolver::newtonMethod() {
    double x = 1.0;
    int iterations = 0;
    const int maxIterations = 1000;

    while (std::abs(func(x)) > precision && iterations < maxIterations) {
        double d = derivative(x);

        if (std::abs(d) < 0.000000001) {
            std::cout << "Похідна близька до нуля. Обчислення зупинено." << std::endl;
            return;
        }

        x = x - func(x) / d;
        iterations++;
    }

    std::cout << "[Ньютон] x = " << x << std::endl;
    std::cout << "[Ньютон] Кількість ітерацій = " << iterations << std::endl;
}

// Деструктор
EquationSolver::~EquationSolver() {
    std::cout << "Об'єкт знищено." << std::endl;
}

// Головна функція запуску
void run() {
#ifdef _WIN32
    // Увімкнення UTF-8 для українського тексту в терміналі Windows
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    setlocale(LC_ALL, ".UTF-8");
#endif

    EquationSolver* solver = new EquationSolver();

    double l, r, tolerance;

    std::cout << "Рівняння: e^x - e^(-x) - 2 = 0 (варіант 8)" << std::endl;
    std::cout << "Введіть межі відрізка (наприклад, 0 1.5): ";
    std::cin >> l >> r;

    std::cout << "Введіть точність: ";
    std::cin >> tolerance;

    solver->setRange(l, r);
    solver->setPrecision(tolerance);

    solver->bisection();
    solver->newtonMethod();

    delete solver;
}
// NelderMead.cpp
#include "NelderMead.h"
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    std::vector<double> coords;
    double value;
    Point(int dim) : coords(dim), value(0) {}
};

// Сравнение точек по значению функции
bool ComparePoints(const Point& a, const Point& b) {
    return a.value < b.value;
}

void nelder_mead_optimize(
    ObjectiveFunction func,
    int dim,
    double* initial_point,
    double* result,
    NelderMeadParams* params
) {
    {
        assert(dim > 0 && "Dimension must be positive");
        assert(params->alpha > 0 && "Alpha must be positive");
        assert(params->gamma > 0 && "Gamma must be positive");
        assert(params->step > 0 && "Step must be positive");
    }
    std::vector<Point> simplex;
    simplex.reserve(dim + 1);

    // Инициализация начальной точки
    Point first_point(dim);
    std::copy(initial_point, initial_point + dim, first_point.coords.begin());
    first_point.value = func(first_point.coords.data());
    simplex.push_back(first_point);

    // Создание остальных точек симплекса
    for (int i = 0; i < dim; ++i) {
        Point p(dim);
        std::copy(initial_point, initial_point + dim, p.coords.begin());
        p.coords[i] += params->step;
        p.value = func(p.coords.data());
        simplex.push_back(p);
    }

    for (int iter = 0; iter < params->max_iterations; ++iter) {
        // Сортировка по возрастанию значения функции
        std::sort(simplex.begin(), simplex.end(), ComparePoints);

        // Проверка сходимости
        double avg = 0.0;
        for (const auto& p : simplex) avg += p.value;
        avg /= (dim + 1);

        double variance = 0.0;
        for (const auto& p : simplex) variance += (p.value - avg) * (p.value - avg);
        if (sqrt(variance / (dim + 1)) < params->tolerance) break;

        // Центр масс лучших точек
        Point centroid(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                centroid.coords[j] += simplex[i].coords[j];
            }
        }
        for (int j = 0; j < dim; ++j) {
            centroid.coords[j] /= dim;
        }

        // Отражение
        Point& worst = simplex.back();
        Point reflected(dim);
        for (int j = 0; j < dim; ++j) {
            reflected.coords[j] = centroid.coords[j] + params->alpha * (centroid.coords[j] - worst.coords[j]);
        }
        reflected.value = func(reflected.coords.data());

        if (reflected.value < simplex[0].value) {
            // Расширение
            Point expanded(dim);
            for (int j = 0; j < dim; ++j) {
                expanded.coords[j] = centroid.coords[j] + params->gamma * (reflected.coords[j] - centroid.coords[j]);
            }
            expanded.value = func(expanded.coords.data());
            simplex.back() = (expanded.value < reflected.value) ? expanded : reflected;
        }
        else if (reflected.value < simplex[dim - 1].value) {
            simplex.back() = reflected;
        }
        else {
            // Сжатие
            Point contracted(dim);
            for (int j = 0; j < dim; ++j) {
                contracted.coords[j] = centroid.coords[j] + params->beta * (worst.coords[j] - centroid.coords[j]);
            }
            contracted.value = func(contracted.coords.data());

            if (contracted.value < worst.value) {
                simplex.back() = contracted;
            }
            else {
                // Сокращение
                Point& best = simplex[0];
                for (size_t i = 1; i < simplex.size(); ++i) {
                    for (int j = 0; j < dim; ++j) {
                        simplex[i].coords[j] = best.coords[j] + params->sigma * (simplex[i].coords[j] - best.coords[j]);
                    }
                    simplex[i].value = func(simplex[i].coords.data());
                }
            }
        }
    }

    // Копирование результата
    std::sort(simplex.begin(), simplex.end(), ComparePoints);
    std::copy(simplex[0].coords.begin(), simplex[0].coords.end(), result);
}
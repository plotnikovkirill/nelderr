// NelderMead.h
#pragma once

#ifdef NELDERMEAD_EXPORTS
#define NELDERMEAD_API __declspec(dllexport)
#else
#define NELDERMEAD_API __declspec(dllimport)
#endif

extern "C" {
    // Тип для целевой функции
    typedef double (*ObjectiveFunction)(double*);

    // Параметры алгоритма
    typedef struct {
        double alpha;   // Коэффициент отражения
        double gamma;   // Коэффициент расширения
        double beta;    // Коэффициент сжатия
        double sigma;   // Коэффициент сокращения
        double step;   // Начальный шаг
        double tolerance; // Критерий остановки
        int max_iterations; // Макс. число итераций
    } NelderMeadParams;

    // Функция оптимизации
    NELDERMEAD_API void nelder_mead_optimize(
        ObjectiveFunction func,
        int dim,
        double* initial_point,
        double* result,
        NelderMeadParams* params
    );
}
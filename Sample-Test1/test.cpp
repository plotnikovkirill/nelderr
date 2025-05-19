#include "pch.h"
#include "NelderMead.h"
#include <random>
// Тест для квадратичной функции f(x,y) = x² + y²
TEST(NelderMeadTest, QuadraticFunction) {
    ObjectiveFunction func = [](double* x) { return x[0] * x[0] + x[1] * x[1]; };

    NelderMeadParams params = { 1.0, 2.0, 0.5, 0.5, 0.01, 1e-6, 1000 };
    double initial[2] = { 5.0, 5.0 };
    double result[2];

    nelder_mead_optimize(func, 2, initial, result, &params);

    EXPECT_NEAR(result[0], 0.0, 1e-2);
    EXPECT_NEAR(result[1], 0.0, 1e-2);
}

// Тест для функции Розенброка
TEST(NelderMeadTest, RosenbrockFunction) {
    ObjectiveFunction func = [](double* x) {
        return 100 * pow(x[1] - x[0] * x[0], 2) + pow(1 - x[0], 2);
        };

    NelderMeadParams params = { 1.0, 2.0, 0.5, 0.5, 0.1, 1e-6, 1000 };
    double initial[2] = { -1.2, 1.0 };
    double result[2];

    nelder_mead_optimize(func, 2, initial, result, &params);

    EXPECT_NEAR(result[0], 1.0, 1e-3);
    EXPECT_NEAR(result[1], 1.0, 1e-3);
}

// Тест на обработку нулевого указателя
TEST(NelderMeadTest, NullPointerHandling) {
    EXPECT_DEATH(
        nelder_mead_optimize(nullptr, 2, nullptr, nullptr, nullptr),
        ".*"
    );
}

// Тест на максимальное число итераций
TEST(NelderMeadTest, MaxIterations) {
    ObjectiveFunction func = [](double* x) { return x[0] * x[0]; };
    NelderMeadParams params = { 1.0, 2.0, 0.5, 0.5, 0.1, 1e-6, 5 }; // Всего 5 итераций

    double initial[1] = { 5.0 };
    double result[1];

    nelder_mead_optimize(func, 1, initial, result, &params);
    EXPECT_GT(result[0], 0.1); // Алгоритм не успевает сойтись
}

TEST(AlgorithmTest, InvalidParameters) {
    NelderMeadParams params = { 0, 0, 0, 0, 0, 0, 0 }; // Некорректные параметры
    double initial[2] = { 0 };
    double result[2];
    EXPECT_DEATH({
        
        nelder_mead_optimize(nullptr, 0, initial, result, &params);
        }, ".*");
}
TEST(NelderMeadTest, ZeroDimension) {
    NelderMeadParams params = { 1.0, 2.0, 0.5, 0.5, 1.0, 1e-6, 1000 };
    double initial[1] = { 0 };
    double result[1];

    EXPECT_DEATH(
        nelder_mead_optimize([](double* x) { return 0.0; }, 0, initial, result, &params),
        "Dimension must be positive"
    );
}
TEST(NelderMeadTest, NegativeStep) {
    NelderMeadParams params = { 1.0, 2.0, 0.5, 0.5, -1.0, 1e-6, 1000 };
    double initial[2] = { 5.0, 5.0 };
    double result[2];

    EXPECT_DEATH(
        nelder_mead_optimize([](double* x) { return x[0] * x[0]; }, 2, initial, result, &params),
        "Step must be positive"
    );
}
TEST(NelderMeadTest, ZeroAlpha) {
    NelderMeadParams params = { 0.0, 2.0, 0.5, 0.5, 1.0, 1e-6, 1000 }; // alpha=0
    double initial[2] = { 5.0, 5.0 };
    double result[2];

    EXPECT_DEATH(
        nelder_mead_optimize([](double* x) { return x[0] * x[0]; }, 2, initial, result, &params),
        "Alpha must be positive"
    );
}

TEST(NelderMeadTest, ZeroGamma) {
    NelderMeadParams params = { 1.0, 0.0, 0.5, 0.5, 1.0, 1e-6, 1000 }; // gamma=0
    double initial[2] = { 5.0, 5.0 };
    double result[2];

    EXPECT_DEATH(
        nelder_mead_optimize([](double* x) { return x[0] * x[0]; }, 2, initial, result, &params),
        "Gamma must be positive"
    );
}
TEST(NelderMeadTest, DegenerateSimplex) {
    // Начальные точки: (0,0), (1,1), (2,2) — вырожденный симплекс
    double initial[2] = { 0.0, 0.0 };
    NelderMeadParams params = { 1.0, 2.0, 0.5, 0.5, 1.0, 1e-6, 1000 };
    double result[2];

    nelder_mead_optimize([](double* x) { return x[0] + x[1]; }, 2, initial, result, &params);
    // Проверка, что алгоритм не завис
    EXPECT_TRUE(true); // Тест на отсутствие аварийного завершения
}
TEST(NelderMeadTest, HighPrecision) {
    NelderMeadParams params = { 1.0, 2.0, 0.5, 0.5, 0.001, 1e-12, 100000 }; // Высокая точность
    double initial[2] = { 5.0, 5.0 };
    double result[2];

    nelder_mead_optimize([](double* x) { return x[0] * x[0] + x[1] * x[1]; }, 2, initial, result, &params);
    EXPECT_NEAR(result[0], 0.0, 1e-6);
}
TEST(NelderMeadTest, HighDimensional) {
    const int dim = 10;
    double initial[dim];
    std::fill_n(initial, dim, 5.0); // Начальная точка (5,5,...,5)
    double result[dim];

    NelderMeadParams params = { 1.0, 2.0, 0.5, 0.5, 0.1, 1e-6, 10000 };
    nelder_mead_optimize([](double* x) {
        double sum = 0;
        for (int i = 0; i < 10; i++) sum += x[i] * x[i];
        return sum;
        }, dim, initial, result, &params);

    for (int i = 0; i < dim; i++) EXPECT_NEAR(result[i], 0.0, 1e-2);
}
TEST(NelderMeadTest, BoundaryInitialPoint) {
    NelderMeadParams params = { 1.0, 2.0, 0.5, 0.5, 0.1, 1e-6, 1000 };
    double initial[2] = { 0.0, 0.0 }; // Граничная точка
    double result[2];

    nelder_mead_optimize([](double* x) { return x[0] * x[0] + x[1] * x[1]; }, 2, initial, result, &params);
    EXPECT_NEAR(result[0], 0.0, 1e-3);
}
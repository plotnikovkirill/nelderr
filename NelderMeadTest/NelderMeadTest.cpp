#include <iostream>
#include "NelderMead.h"

// Тестовая функция: f(x, y) = x^2 + y^2
double quadratic_function(double* x) {
    return x[0] * x[0] + x[1] * x[1];
}

int main() {
    const int dim = 2;
    double initial[dim] = { 5.0, 5.0 };
    double result[dim];

    NelderMeadParams params = {
        1.0,   // alpha
        2.0,   // gamma
        0.5,   // beta
        0.5,   // sigma
        0.1,   // step
        1e-6,  // tolerance
        1000   // max_iterations
    };

    nelder_mead_optimize(
        quadratic_function,
        dim,
        initial,
        result,
        &params
    );

    std::cout << "Optimal point: (" << result[0] << ", " << result[1] << ")\n";
    return 0;
}
#include "function.hpp"

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>

void expectNear(double actual, double expected) {
    if (!std::isfinite(actual) || std::abs(actual - expected) > 1e-12 * expected) {
        throw std::runtime_error("Unexpected function value");
    }
}

int main() {
    try {
        expectNear(f(0, 7), 1.0);
        expectNear(f(2, 3), 6.082762530298219);
        expectNear(f(-2, 3), 6.082762530298219);
        expectNear(f(1.5, 2.0), 3.1622776601683795);
        expectNear(f(-1.5, -2.0), 3.1622776601683795);
        expectNear(f<int>(0, 7), 1.0);
        expectNear(f<int>(2, 3), 6.082762530298219);
        expectNear(f<int>(-2, 3), 6.082762530298219);
        expectNear(f<double>(1.5, 2.0), 3.1622776601683795);
        expectNear(f<double>(-1.5, -2.0), 3.1622776601683795);
        const int maximum = std::numeric_limits<int>::max();
        const double product = static_cast<double>(maximum) * maximum;
        expectNear(f(maximum, maximum), product);
        expectNear(f<int>(maximum, maximum), product);
        expectNear(f(1e100, 1e100), 1e200);
        expectNear(f<double>(1e100, 1e100), 1e200);
        std::cout << "All tests passed\n";
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}

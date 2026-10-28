#include "function.hpp"

#include <iomanip>
#include <iostream>

int main() {
    const int x = 2, y = 3;
    const double a = 1.5, b = 2.0;

    std::cout << std::setprecision(12)
              << "Overload int: " << f(x, y) << '\n'
              << "Template int: " << f<int>(x, y) << '\n'
              << "Overload double: " << f(a, b) << '\n'
              << "Template double: " << f<double>(a, b) << '\n';
}

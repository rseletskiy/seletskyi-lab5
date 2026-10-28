#pragma once

#include <cmath>

template <typename T>
double f(T x, T y) {
    return std::hypot(1.0, static_cast<double>(x) * static_cast<double>(y));
}

inline double f(int x, int y) {
    return std::hypot(1.0, static_cast<double>(x) * y);
}

inline double f(double x, double y) {
    return std::hypot(1.0, x * y);
}

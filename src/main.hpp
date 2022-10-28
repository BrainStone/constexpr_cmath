#pragma once

constexpr int Factorial(int n) {
    if (n < 1) return 0;

    int out = 1;

    for (int i = 1; i <= n; ++i) {
        out *= i;
    }

    return out;
}

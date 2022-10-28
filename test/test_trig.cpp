// This file tests the trigonometry functions
#include <cmath>
#include <limits>

#include "gtest/gtest.h"

#include "constrexpr_cmath.hpp"

TEST(TrigonometryTest, Sin) {
    long double diff;
    long double abs_diff;
    long double max_abs_diff = 0.0L;
    long double max_diff;
    long double param;

    for (long double x = -10.0L; x < 10.0L; x += 1e-6L) {
        diff = std::sin(x) - constexpr_cmath::sin(x);
        abs_diff = std::abs(diff);

        if (abs_diff > max_abs_diff) {
            max_abs_diff = abs_diff;
            max_diff = diff;
            param = x;
        }
    }

    std::cout.precision(std::numeric_limits<long double>::max_digits10 + 2);
    std::cout << "sin max diff " << max_diff << " at " << param << std::endl;

    const long double std_val{std::sin(param)};
    long double constexpr_cmath_val{constexpr_cmath::sin(param)};
    size_t steps_off = 0;

    for (; constexpr_cmath_val != std_val; ++steps_off) {
        constexpr_cmath_val = std::nexttoward(constexpr_cmath_val, std_val);
    }

    EXPECT_LT(steps_off, 10);
}

TEST(TrigonometryTest, Cos) {
    long double diff;
    long double abs_diff;
    long double max_abs_diff = 0.0L;
    long double max_diff;
    long double param;

    for (long double x = -10.0L; x < 10.0L; x += 1e-6L) {
        diff = std::cos(x) - constexpr_cmath::cos(x);
        abs_diff = std::abs(diff);

        if (abs_diff > max_abs_diff) {
            max_abs_diff = abs_diff;
            max_diff = diff;
            param = x;
        }
    }

    std::cout.precision(std::numeric_limits<long double>::max_digits10 + 2);
    std::cout << "cos max diff " << max_diff << " at " << param << std::endl;

    const long double std_val{std::cos(param)};
    long double constexpr_cmath_val{constexpr_cmath::cos(param)};
    size_t steps_off = 0;

    for (; constexpr_cmath_val != std_val; ++steps_off) {
        constexpr_cmath_val = std::nexttoward(constexpr_cmath_val, std_val);
    }

    EXPECT_LT(steps_off, 10);
}

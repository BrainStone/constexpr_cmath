// This file tests the trigonometry functions
#include <cmath>
#include <limits>

#include "gtest/gtest.h"

#include "constrexpr_cmath.hpp"

TEST(TrigonometryTest, Sin) {
    const long double delta = std::abs(1 - std::sin(constexpr_cmath::internal::HALF_PI<long double>));
    constexpr long double value = constexpr_cmath::sin(1.0L);

    std::cout.precision(std::numeric_limits<long double>::max_digits10 + 2);
    std::cout << delta << std::endl;

    std::cout << constexpr_cmath::sin(1.0L) - std::sin(1.0L) << std::endl;
    std::cout << constexpr_cmath::sin(1.0L) - 0.8414709848078965066525023216302989996225630607983710656727517099L
              << std::endl;

    std::cout << std::sin(1.0L) << std::endl;
    std::cout << constexpr_cmath::sin(1.0L) << std::endl;
    std::cout << 0.8414709848078965066525023216302989996225630607983710656727517099L << std::endl;

    EXPECT_NEAR(constexpr_cmath::sin(1.0L), std::sin(1.0L), delta);
    EXPECT_NEAR(constexpr_cmath::sin(1.0L), 0.8414709848078965066525023216302989996225630607983710656727517099L, delta);
}

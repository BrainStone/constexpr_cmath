#ifndef CONSTEXPR_CMATH_CONSTREXPR_CMATH_HPP
#define CONSTEXPR_CMATH_CONSTREXPR_CMATH_HPP

#include <cmath>
#include <concepts>

// Little helper to reduce bloat
#define float_t template<std::floating_point T> constexpr T

namespace constexpr_cmath {
    namespace internal {
        using count_t = std::size_t;

        float_t PI{3.14159265358979323846264338327};
        float_t TWO_PI{PI<T> * 2.0};
        float_t HALF_PI{PI<T> / 2.0};
        constexpr count_t sin_iterations{30};

        float_t sin_half_arc(const T x) {
            const T x2{x * x};
            T divisor_inverted{1.0};
            T pow_x{x};
            T out{x};

            for (count_t i = 1; i < sin_iterations; ++i) {
                pow_x *= x2;
                divisor_inverted /= (2 * i) * (2 * i + 1);

                if ((i & 1) == 0)
                    out += pow_x * divisor_inverted;
                else
                    out -= pow_x * divisor_inverted;
            }

            return out;
        }
    }

    float_t sin(const T x) {
        // TODO: fmod is not constexpr in C++20

        // Reducing to a single period
        T adjusted{std::fmod(std::fmod(x, internal::TWO_PI<T>) + internal::TWO_PI<T>, internal::TWO_PI<T>)};
        // Reducing to a half period and saving the sign
        const bool positive = adjusted < internal::PI<T>;
        adjusted = std::fmod(adjusted, internal::PI<T>);
        // Reducing to a half ark (first shifting by half pi to the left, getting absolute value and flipping it back)
        adjusted = internal::HALF_PI<T> - std::abs(adjusted - internal::HALF_PI<T>);

        if (positive)
            return internal::sin_half_arc(adjusted);
        else
            return -internal::sin_half_arc(adjusted);
    }

    float_t cos(const T x) {
        return sin(x + internal::HALF_PI<T>);
    }
}

#undef float_t

#endif //CONSTEXPR_CMATH_CONSTREXPR_CMATH_HPP

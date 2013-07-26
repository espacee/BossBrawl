#ifndef UTIL_MATH_HPP
#define UTIL_MATH_HPP

/**
 * @brief Math utility functions
 */
namespace math {

template <typename T>
/**
 * @brief Clamp a variable's value to a range
 * @param var Variable to clamp
 * @param min Minimum value the variable can have
 * @param max Maximum value the variable can have
 */
void clamp(T& var, T min, T max)
{
    if (var < min)
        var = min;

    if (var > max)
        var = max;
}

}

#endif // UTIL_MATH_HPP

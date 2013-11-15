#ifndef UTIL_MATH_HPP
#define UTIL_MATH_HPP

#include <random>
#include <chrono>
#include <iostream>

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

template <typename T>
/**
 * @brief Get a random Variable to a range
 * @param min Minimum value the variable can have
 * @param max Maximum value the variable can have
 */

int getRandomValue(T min, T max)
{
    unsigned int seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine reng(seed);
    std::uniform_int_distribution<int> distribution(min,max);

    return distribution(reng);
}

}

#endif // UTIL_MATH_HPP

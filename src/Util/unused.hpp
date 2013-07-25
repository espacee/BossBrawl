/// @file unused.hpp
/// @brief Definition of BRAWL_UNUSED

#ifndef UTIL_UNUSED_HPP
#define UTIL_UNUSED_HPP

/**
 * @brief Macro to mark a function argument as unused
 *
 * Useful to avoid "unused parameter" warnings from compilers, and
 * otherwise tell the reader that this argument is unused
 */
#define BRAWL_UNUSED(arg) static_cast<void>(arg)

#endif // UTIL_UNUSED_HPP

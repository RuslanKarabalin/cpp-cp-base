#ifndef COMPARABLE_H_
#define COMPARABLE_H_

#include <concepts>

namespace krt {
// Concept for comparable types
template <typename T>
concept Comparable = requires(const T& a, const T& b) {
    { a < b } -> std::convertible_to<bool>;
    { a <= b } -> std::convertible_to<bool>;
    { a > b } -> std::convertible_to<bool>;
    { a >= b } -> std::convertible_to<bool>;
    { a == b } -> std::convertible_to<bool>;
    { a != b } -> std::convertible_to<bool>;
};
}  // namespace krt

#endif  // COMPARABLE_H_

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

namespace krt {
// Stack based on std::vector
template <typename T>
class Stack {
   public:
    bool empty() const { return data.empty(); }

    std::size_t size() const { return data.size(); }

    void push(const T& value) { data.push_back(value); }

    void push(T&& value) { data.push_back(std::move(value)); }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Empty stack!");
        }
        data.pop_back();
    }

    T& top() {
        if (empty()) {
            throw std::out_of_range("Empty stack!");
        }
        return data.back();
    }

    const T& top() const {
        if (empty()) {
            throw std::out_of_range("Empty stack!");
        }
        return data.back();
    }

    void clear() { data.clear(); }

    void swap(Stack& other) { data.swap(other.data); }

    template <typename... Args>
    void emplace(Args&&... args) {
        data.emplace_back(std::forward<Args>(args)...);
    }

    // Standard operator<< overloading for krt::Stack<T>
    // From "top" to "bottom"
    friend std::ostream& operator<<(std::ostream& out, const Stack<T>& s) {
        out << "[";
        for (size_t i = 0; i < s.data.size(); ++i) {
            out << s.data[s.data.size() - i - 1];
            if (i < s.data.size() - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

   private:
    std::vector<T> data;
};
}  // namespace krt

#endif  // STACK_H_

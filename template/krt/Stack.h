#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
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

#endif  // VECTOR_H_

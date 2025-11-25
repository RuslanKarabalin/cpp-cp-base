#include <iostream>
#include <vector>

// Namespace for my developments
namespace krt {
    // Concept for comparable types
    template <typename T>
    concept Comparable = requires(const T& a, const T& b) {
        { a <  b } -> std::convertible_to<bool>;
        { a <= b } -> std::convertible_to<bool>;
        { a >  b } -> std::convertible_to<bool>;
        { a >= b } -> std::convertible_to<bool>;
        { a == b } -> std::convertible_to<bool>;
        { a != b } -> std::convertible_to<bool>;
    };

    // Stack based on std::vector
    template <typename T>
    class Stack {
    public:
        bool empty() const {
            return data.empty();
        }

        std::size_t size() const {
            return data.size();
        }

        void push(const T& value) {
            data.push_back(value);
        }

        void push(T&& value) {
            data.push_back(std::move(value));
        }

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

}

// Standard operator<< overloading for std::vector<T>
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    out << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        const auto &x = v[i];
        out << x;
        if (i < v.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;

    std::vector<int> vector;
    krt::Stack<int> krtStack;

    for (size_t i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        vector.push_back(v);
        krtStack.push(v);
    }

    std::cout << "std::vector<T>: " << vector << std::endl;
    std::cout << "krt::Stack<T>: " << krtStack << std::endl;
    return 0;
}

#include <iostream>
#include <vector>

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

    std::vector<int> vec;

    for (size_t i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        vec.emplace_back(v);
    }

    std::cout << vec << std::endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {};

// Standard operator<< overloading for std::vector<T>
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    out << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        const auto& x = v[i];
        out << x;
        if (i < v.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;

    return 0;
}

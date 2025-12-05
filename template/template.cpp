#include <iostream>
#include <vector>
#include "krt/Stack.h"
#include "krt/VectorOut.h"

int main() {
    std::ios_base::sync_with_stdio(false);
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

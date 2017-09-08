#include <iostream>

template <class T>
T sum(T a, T b) {
    return a + b;
}

template <class T>
T calc(T a, T b, T (*phepTinh)(T, T)) {
    return phepTinh(a, b);
}

int main() {
    std::cout << calc(2, 3, sum);
    return 0;
}

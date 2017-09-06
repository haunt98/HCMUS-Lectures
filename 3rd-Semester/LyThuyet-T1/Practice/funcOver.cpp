#include <iostream>

int sum(int a, int b) {
    std::cout << "int" << std::endl;
    return a + b;
}

double sum(double a, double b) {
    std::cout << "double" << std::endl;
    return a + b;
}

int main() {
    sum(2.0, 3.2);
    return 0;
}

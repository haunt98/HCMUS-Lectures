#include <iostream>

int main() {
    std::string prev = "";
    std::string cur;
    while (std::cin >> cur) {
        if (cur == prev) {
            std::cout << "repeated word: " << cur << std::endl;
            break;
        }
        prev = cur;
    }
    return 0;
}

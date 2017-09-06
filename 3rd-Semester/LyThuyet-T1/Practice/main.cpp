#include <iostream>
#include <string>

int main() {
    std::cout << "Input names : ";

    // read name
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";

    const std::string spaces(greeting.size(), ' ');
    const std::string star(greeting.size() + 2, '*');
    std::cout << star << std::endl;
    std::cout << "*" << spaces << "*" << std::endl;
    std::cout << "*" << greeting << "*" << std::endl;
    std::cout << "*" << spaces << "*" << std::endl;
    std::cout << star << std::endl;
    return 0;
}

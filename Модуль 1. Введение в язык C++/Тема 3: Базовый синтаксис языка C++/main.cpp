#include <iostream>
#include <random>

int main() {
    int a;
    int b;
    std::cin >> a >> b;

    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;

    int c;
    std::cin >> c;
    std::string str = c % 2 == 0 ? "even" : "odd";
    std::cout << str << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);
    int num = dis(gen);
    int input;
    while ((std::cin >> input) && input != num) {
        if (input > num) {
            std::cout << "less" << '\n';
        } else if (input < num) {
            std::cout << "more" << '\n';
        }
    }

    std::cout << "good" << std::endl;
}
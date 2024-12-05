#include <iostream>
#include <ostream>
#include <stdexcept>

int Dev(int a, int b) {
    try {
      return a / b;
    } catch (...) {
        return -1; // error
    }
}

class ZeroDev: public std::runtime_error {
    public:
    ZeroDev() : std::runtime_error("") {}

    const char *what() const throw() override {
        return "ZeroDev";
    }
};

int Dev2(int a, int b) {
    if (b == 0) {
        throw ZeroDev();
    }

    return a / b;
}

int main() {
    std::cout << Dev(10, 3) << std::endl;

    try {
        Dev2(212, 0);
    } catch (ZeroDev &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "!!!" << std::endl;
    }
}
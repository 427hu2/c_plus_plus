#include "sum.h"

// #include "static/static_lib.h"
// #include "dynamic/dynamic_lib.h"

#include <iostream>
#include <vector>

int main() {
    // g++ -std=c++20 main.cpp sum.cpp
    std::cout << "Sum: " << SumSimple(1, 3) << std::endl;

    /** Могут быть проблемы при сборке библиотеки из-за пробелов в путях/сборка динамической либы аналогична
    *   cd static
    *   mkdir build
    *   cd build
    *   cmake ..
    *   make
    */
    // std::vector<int> v = {10, 1};
    // std::cout << "Sum Static Lib: " << Sum(v) << std::endl;
}
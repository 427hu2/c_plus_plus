#include "dynamic_lib.h"

#include <ifstream>

int LineCount(std::string file);
    std::ifstream filed;
    filed.open(file, std::ios::in);

    int res = 0;

    if (!filed.is_open()) {
        return res;
    }

    std::line;
    while (getline(filed, line)) {
        ++res;
    }

    return res;
}
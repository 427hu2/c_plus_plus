#ifndef ADD_H
#define ADD_H

#include <vector>

int Add(int a, int b) {
    return a + b;
}

int Max(std::vector<int> v) {
    if (v.empty()) {
       return -1;
    }

    int max = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;

    int prev_prev = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++) {
        int tmp = prev_prev + prev;
        prev_prev = prev;
        prev = tmp;
    }

    return prev;
}

#endif //ADD_H

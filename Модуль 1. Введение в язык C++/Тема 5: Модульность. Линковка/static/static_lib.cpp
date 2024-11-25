#include "static_lib.h"

int Sum(std::vector<int> vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return sum;
}

int Min(std::vector<int> vec) {
    int min = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] < min) {
            min = vec[i];
        }
    }
    return min;
}

int Max(std::vector<int> vec) {
    int max = vec[0];
    for (int i = 1; i < vec.size(); i++) {
      if (vec[i] > max) {
        max = vec[i];
      }
    }
    return max;
}
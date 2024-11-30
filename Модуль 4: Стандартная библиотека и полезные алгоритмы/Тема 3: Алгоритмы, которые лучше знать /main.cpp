#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

int main() {
    std::vector<int> v = {3, 9, 2, 4, 6, 8, 5, 7, 1, 0, 100};
    std::sort(v.begin(), v.end(), [](int a, int b) {
      return a < b;
    });
    for (int i = 0; i < v.size(); i++) {
      std::cout << v[i] << "\n";
    }

    int sum = std::accumulate(v.begin(), v.end(), 0, [](int acc, int it) {
      return acc + it;
    });

    std::cout << sum << std::endl;

    int count_per = 0;
    // печаем первые 5 перестановок
    while (std::next_permutation(v.begin(), v.end()) && count_per < 5) {
      for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << "\n";
      }
      count_per++;
    }
    std::cout << count_per << std::endl;
}
#include <iostream>

int Sum(int a, int b) {
    return a + b;
}

// 1 * 2 * 3 * 4 * 5
int Factorial(int a) {
    if (a == 1) return 1;
    return a * Factorial(a - 1);
}

// 0, 1
// 0, 1, 1
// 0, 1, 1, 2
// 0, 1, 1, 2, 3
// 0, 1, 1, 2, 3, 5
int FibonacciR(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  return FibonacciR(n - 1) + FibonacciR(n - 2);
}

int FibonacciC(int n) {
    int prev_prev = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++) {
        int tmp = prev_prev + prev;
        prev_prev = prev;
        prev = tmp;
    }

    return prev;
}

int FibonacciV(int n) {
  std::vector<int> res = {0, 1};

  for (int i = 2; i <= n; i++) {
    res.push_back(res[i - 1] + res[i - 2]);
  }

  return res[n];
}

int main() {
    std::cout << Sum(3, 5) << std::endl;
    std::cout << Sum(13, 445) << std::endl;
    std::cout << Sum(89, 435) << std::endl;

    std::cout << "Factorial: " << Factorial(6) << std::endl;

    std::cout << "FibonacciV: " << FibonacciV(7) << std::endl;
    std::cout << "FibonacciC: " << FibonacciC(7) << std::endl;
    std::cout << "FibonacciR: " << FibonacciR(7) << std::endl;
}
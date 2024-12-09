#include <iostream>

int** createArray(const int size) {
  int **arr = new int*[size];
  for (int i = 0; i < size; i++) {
    arr[i] = new int[size];
  }
  return arr;
}

int main() {
    int *a = new int[10];

    for (int i = 0; i < 10; i++) {
      std::cout << a[i] << std::endl;
    }

    for (int i = 0; i < 10; i++) {
      a[i] = i;
    }

    for (int i = 0; i < 10; i++) {
      std::cout << a[i] << std::endl;
    }

  delete[] a;

  int **mat = createArray(10);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      mat[i][j] = i + j;
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << mat[i][j] << std::endl;
    }
  }
}
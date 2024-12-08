#include <iostream>

class Test {
  int _data;

  public:
    Test() {
      std::cout << "constructor" << std::endl;
    }

    Test(const Test &other) {
       std::cout << "copy constructor" << std::endl;
    }

    Test(Test &&other) noexcept {
        std::cout << "move constructor" << std::endl;
    }

  Test &operator=(const Test &other) {
      std::cout << "copy assignment" << std::endl;
      if (this != &other) {
        this->_data = other._data;
      }

      return *this;
    }

    ~Test() {
      std::cout << "destructor" << std::endl;
    }

  int GetData() const noexcept {
      return _data;
    }
};

void copy(Test c) {
  std::cout << "copy fn" << std::endl;
}
void move(Test &&c) {
  std::cout << "move fn" << std::endl;
}

void not_perfect_2(Test &&c) {
  move(std::forward<Test>(c));
}

template <typename T>
void perfect(T&& c) {
  move(std::forward<T>(c));
}

void perfect_2(Test &&c) {
  move(std::move(c));
}

int main() {
  Test t;
   std::cout << "copy" << std::endl;
   copy(t);
   std::cout << "move" << std::endl;
   move(std::move(t));
   move(Test());

  not_perfect_2(Test());
  perfect(Test());

  std::cout << t.GetData() << std::endl;
}
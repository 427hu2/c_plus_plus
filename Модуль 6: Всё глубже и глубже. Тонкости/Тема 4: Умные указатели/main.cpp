#include <memory>
#include <iostream>
#include <memory>
#include <memory>

class Test {
  public:
    Test() {
      std::cout << "Test()" << std::endl;
    }
    ~Test() {
      std::cout << "~Test()" << std::endl;
    }
    void Test1() {

    }
};

/*
void processWidget(std::shared_ptr<Test>(new Test), computePriority()) {
порядок вычисления параметров может быть любой

1.Выполнить new Widget
2.Выполнить computePriority
3.Вызвать конструктор std::shared_ptr

computePriority() выбросит исключение то new Widget не будет сохранен в std::shared_ptr == утечка

}
*/
int main() {
  {
    std::unique_ptr<Test> test = std::make_unique<Test>();
  }
  std::cout << "```````````````" << std::endl;

  std::unique_ptr<Test> test = std::make_unique<Test>();
  {
    test = std::make_unique<Test>();
    test->Test1();
  }
  std::cout << "```````````````" << std::endl;


  Test *test2 = new Test();
  std::shared_ptr<Test> test3(test2);
  std::shared_ptr<Test> test4(test2);
  test3->Test1();

  std::shared_ptr<int> s = std::make_shared<int>(1);
  std::weak_ptr<int>w(s);
  std::cout << w.lock() << std::endl;
  s = nullptr;
  std::cout << w.lock() << std::endl;
}
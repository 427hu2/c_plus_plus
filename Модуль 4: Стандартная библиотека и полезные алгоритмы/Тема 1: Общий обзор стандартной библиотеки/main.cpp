#include <vector>
#include <iostream>
#include <list>
#include <set>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "vector" << std::endl;
    for (int i : v) {
      std::cout << i << std::endl;
    }

    std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l.push_front(1);
    l.push_back(1);
    l.insert(l.end(), 1);
    std::cout << "list" << std::endl;
    for (int i : l) {
      std::cout << i << std::endl;
    }

    std::cout << "set" << std::endl;
    std::set<int> s = { 1, 5, 10, 2, 4, 10 };
    s.insert(1);
    for (auto i : s) {
      std::cout << i << std::endl;
    }
}
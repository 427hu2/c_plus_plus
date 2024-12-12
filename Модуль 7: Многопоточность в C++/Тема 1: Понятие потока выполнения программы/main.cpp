#include <iostream>
#include <thread>
#include <vector>

void print() {
    std::cout << 2 << std::endl;
}

int main() {
    const unsigned int threads =  std::thread::hardware_concurrency();
    if (threads == 0) {
        std::cout << "Error" << std::endl;
    } else {
        std::cout << "Thread count: " << threads << std::endl;
    }


    std::cout << 1 << std::endl;
    std::thread t(print);
    // t.detach(); // после завершения основного потом дочерний может продолжить выполняться
    // t.join(); // ждать выполнения
    std::cout << 3 << std::endl;

    // потоки не видят друг друга, но используют общее адресное пространство

    // если операция не атомарна, то другой потом может получить промежуточное значение

    std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
    int sum = 0;
    std::mutex m;
    std::thread t1([&]() {
        for (unsigned int i = 0; i < 5; i++) {
            m.lock();
            sum += v[i];
            m.unlock();
        }
    });

    std::thread t2([&]() {
        for (unsigned int i = 5; i < 10; i++) {
            m.lock();
            sum += v[i];
            m.unlock();
        }
    });

    t1.join();
    t2.join();

    std::cout << sum << std::endl;

    std::atomic<int> count{0};
    std::thread t11([&]() {
        for (unsigned int i = 0; i < 5; i++) {
            count += v[i];
        }
    });

    std::thread t22([&]() {
        for (unsigned int i = 5; i < 10; i++) {
            count += v[i];
        }
    });

    t11.join();
    t22.join();

    std::cout << sum << std::endl;
}
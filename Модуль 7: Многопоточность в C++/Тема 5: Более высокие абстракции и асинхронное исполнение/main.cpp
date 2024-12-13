#include <future>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // std::launch::async => std::thread
    std::future<int> sum = std::async(std::launch::async, [&]() {
        int sum1 = 0;
        for (int i = 0; i < 10; i++) {
            sum1 += v[i];
        }
        std::cout << "in async" << std::endl;
        return sum1;
    });

    std::cout << "start" << std::endl;
    // std::cout << sum.get() << std::endl;
    std::cout << "end" << std::endl;

    // std::launch::deferred => lazy computing, when call Get
    std::future<int> sum2 = std::async(std::launch::deferred, [&]() {
        int sum1 = 0;
        for (int i = 0; i < 10; i++) {
            sum1 += v[i];
        }
        std::cout << "in deferred" << std::endl;
        return sum1;
    });

    std::cout << "start" << std::endl;
    std::cout << sum2.get() << std::endl;
    std::cout << "end" << std::endl;

    std::promise<int> promise;
    std::future<int> f = promise.get_future();

    std::thread t1([&]() {
        std::cout << "sleping ...." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::cout << "set promise" << std::endl;
        promise.set_value(1001);
    });

    std::thread t2([&]() {
        std::cout << "start wait promise" << std::endl;
        int v = f.get();
        std::cout << "end wait: " << v << std::endl;
    });

    t1.join();
    t2.join();
}

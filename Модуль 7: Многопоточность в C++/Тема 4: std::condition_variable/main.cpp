#include <condition_variable>
#include <exception>
#include <iostream>
#include <thread>

class Throw {
public:
    Throw() = default;

    void Set() {
        std::unique_lock<std::mutex> lock(mtx);

        std::cout << "set" << std::endl;
        data = 1000;

        cv.notify_all();
    }
    int Get() {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "get " << std::endl;

        cv.wait(lock, [&] {
            return data != -1;
        });

        if (data == -1) {
            throw std::exception();
        }

        return data;
    }
private:
    int data{-1};
    std::condition_variable cv;
    std::mutex mtx;
};

int main() {
    Throw t;

    std::thread t1([&t]() {
        t.Get();
    });

    std::thread t2([&t]() {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        t.Set();
    });

    t1.join();
    t2.join();
}

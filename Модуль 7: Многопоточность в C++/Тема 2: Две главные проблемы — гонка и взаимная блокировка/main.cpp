#include <thread>
#include <iostream>


class Store {
public:
    int data = 0;

    Store() = default;

    int Print(const std::string &t_name) {
        std::cout << t_name << " : " << data << std::endl;
        return data++;
    }

    int Get() const {
        return data;
    }
};

int main() {
    unsigned long long g_count = 0;
    std::mutex m;
    std::thread t1([&]() {
        while (g_count < 100) {
            m.lock();
            ++g_count;
            m.unlock();
        }
    });

    std::thread t2([&]() {
        while (g_count < 100) {
            m.lock();
            ++g_count;
            m.unlock();
        }
    });

    t1.join();
    t2.join();

    std::cout << g_count << std::endl;
    std::mutex m2;
    Store s;
    std::thread t([&]() {
        int i = 0;
        while (i < 10) {
            std::lock_guard<std::mutex> guard(m2);
            s.Print("One");
            std::cout << s.Get() << std::endl;
            ++i;
        }
    });
    std::thread t22([&]() {
        int i = 0;
        while (i < 10) {
            std::lock_guard<std::mutex> guard(m2);
            s.Print("Two");
            std::cout << s.Get() << std::endl;
            ++i;
        }
    });
    std::thread t33([&]() {
        int i = 0;
        while (i < 10) {
            std::lock_guard<std::mutex> guard(m2);
            s.Print("Three");
            std::cout << s.Get() << std::endl;
            ++i;
        }
    });

    t22.join();
    t33.join();
    t.join();
}

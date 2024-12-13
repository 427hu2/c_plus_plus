#include <queue>
#include <iostream>
#include <thread>

int COUNT = 100;
std::mutex g_mutex;

void Write(std::queue<int> &q, int it) {
    g_mutex.lock();
    q.push(it);
    g_mutex.unlock();
}

void Read(std::queue<int> &q, const std::string &txt) {
    g_mutex.lock();
    if (!q.empty()) {
        std::cout << q.front() << " " << txt << std::endl;
        q.pop();
    }
    g_mutex.unlock();
}

void Race() {
    std::queue<int> q;

    std::thread t1([&]() {
        std::cout << "start two" << std::endl;
        for (int i = COUNT; i < COUNT * 2; i++) {
            Write(q, i);
            Read(q, "two");
        }
    });

    std::thread t([&]() {
        std::cout << "start one" << std::endl;
        for (int i = 0; i < COUNT; i++) {
            Write(q, i);
            Read(q, "one");
        }
    });

    t.join();
    t1.join();
}

class LockQueue {
public:
    void push(int i) {
        std::unique_lock<std::mutex> lock(m_);
        std::cout << "add: " << i << std::endl;
        q_.push(i);
        cond_.notify_all();
    }

    void back() {
        std::unique_lock<std::mutex> lock(m_);
        cond_.wait(lock, [this] {               // Ждём, пока очередь не станет непустой или работа не завершится
           return !q_.empty();
       });

        std::cout <<  "back: " << q_.back() << std::endl;
    }
private:
    std::mutex m_;
    std::queue<int> q_;
    std::condition_variable cond_;
};

int main() {
    LockQueue ql;


    std::thread read([&]() {
        for (int i = 0; i < COUNT; i++) {
            ql.back();
        }
    });

    std::thread write([&]() {
        for (int i = 0; i < COUNT; i++) {
            ql.push(i);
        }
    });

    write.join();
    read.join();
}

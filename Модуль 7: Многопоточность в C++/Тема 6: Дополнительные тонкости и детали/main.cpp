#include <iostream>
#include <mutex>
#include <thread>

std::once_flag flag;

void one() {
    std::cout << "once call" << std::endl;
}

void two() {
    std::cout << "two start call" << std::endl;
    std::call_once(flag, one);
    std::cout << "two end call" << std::endl;
}


thread_local int global_value = 10;

int main() {
    std::thread t1(two);
    two();
    std::thread t2(two);
    two();
    std::thread t3(two);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "global_value: " << global_value << std::endl;
    std::thread give_me_a_name([&]() {
        global_value += 10;
        std::cout << "global_value_1: " << global_value << std::endl;
    });
    std::thread give_me_a_name2([&]() {
        global_value += 100;
        std::cout << "global_value_2: " << global_value << std::endl;
    });
    std::cout << "global_value: " << global_value << std::endl;

    give_me_a_name.join();
    give_me_a_name2.join();
}

#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    // момент врмени с полудня
    // 2024-11-22 14:16:13.945981
    std::chrono::time_point now = std::chrono::system_clock::now();
    std::chrono::time_point system = std::chrono::steady_clock::now();

    // - system_clock системное время подверженно внешним изменения (может меняться юзером в системе и не подхоит для большенсва задач)
    // - steady_clock устойчивые часы не подверженны внешним изменениям (обычно времени работы системы после включения)

    std::time_t now_t = std::time(0);
    std::tm* now_ptr = std::localtime(&now_t);

    std::cout << "Hello World!" << '\n';

    std::cout << "Now ms: " << now_t << '\n';

    std::cout << "Year: " << now_ptr->tm_year + 1900 << '\n';
    std::cout << "Month: " << now_ptr->tm_mon + 1 << '\n';
    std::cout << "Day: " << now_ptr->tm_mday << '\n';

    std::cout << "Full data: " << std::ctime(&now_t) << '\n';

    std::string name;
    std::cin >> name;
    std::cout << "Hello " << name << '\n';
}
#include <fmt/core.h>

#include <string>

int main()
{
    // vcpkg установить как в проект локально
    fmt::print("Hello World!\n");
    std::string s = fmt::format("I'd rather be {1} than {0}.", "right", "happy");
    fmt::print(s);
    return 0;
}

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

/*
*1. Напишите программу, которая использует std::map для подсчёта количества вхождений каждого слова в строке.
2. Напишите программу, которая читает строки из файла с помощью std::ifstream, обрабатывает их и сохраняет в контейнер std::vector.
3. Напишите программу, которая использует std::unordered_map для подсчёта частоты слов и затем выводит 5 самых часто встречающихся слов.
*/

std::vector<std::string> split(std::string s, char delim) {
    int start = 0;
    int end = 0;
    std::vector <std::string> result;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == delim) {
            result.push_back(s.substr(start, end - start));
            start = end + 1;
        }
        ++end;
    }
    result.push_back(s.substr(start, end - start));
    return result;
}

int main() {
    std::vector<std::string> r = split("Hello test one two test hello one test", ' ');
    std::map<std::string, int> c;

    for (const std::string & i : r) {
        c[i]++;
    }

    for (const auto & i : c) {
        std::cout << i.first << " " << i.second << std::endl;
    }

    std::ifstream file("test.txt");
    std::vector<std::string> lines;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
    }

    for (const auto & i : lines) {
        std::cout << i << std::endl;
    }

    std::unordered_map<std::string, int> count;
    for (const std::string & i : r) {
        count[i]++;
    }
}

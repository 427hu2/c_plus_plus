#include "lib.h"

#include <gtest/gtest.h>
#include <vector>

TEST(LibTest, AddTest) {
    int r = Add(1, 2);
    EXPECT_EQ(r, 3);

    int r1 = Add(0, 0);
    EXPECT_EQ(r1, 0);
}

TEST(LibTest, MaxTest) {
    std::vector<int> emp;
    int m = Max(emp);
    EXPECT_EQ(m, -1);

    int max = 1001;
    std::vector<int> v = {1, 2, 100, 3, 5};
    v.push_back(max);

    int m1 = Max(v);
    EXPECT_EQ(m1, max);

    std::vector<int> v2 = {0, 0, 0, 0, 0, 0};
    int m2 = Max(emp);
    EXPECT_EQ(m2, 0);
}

TEST(LibTest, FibonacciTest) {
    int f = Fibonacci(0);
    EXPECT_EQ(f, 0);

    int f1 = Fibonacci(1);
    EXPECT_EQ(f1, 1);

    int f2 = Fibonacci(2);
    EXPECT_EQ(f2, 1);

    int f3 = Fibonacci(9);
    EXPECT_EQ(f3, 21);

    int f4 = Fibonacci(20);
    EXPECT_EQ(f4, 4181);
}
#include <array>
#include <iostream>
#include <span>

struct Foo
{
    int a{ };
    int b{ };
    int c{ };
};

consteval int sum(std::span<const int>    a)
{
    int s{ 0 };
    for (auto n : a)
        s += n;
    return s;
}

auto sum(auto x, auto y) -> decltype(x + y)
{
    return x + y;
}

int main() 
{
    constexpr std::array a{ 3, 2, 1 };
    constexpr int s{ sum(a) };
    Foo f1( .a = 1, .c = 3);
    std::cout << sum(f1.a, f1.c) << std::endl;
    return 0;
}


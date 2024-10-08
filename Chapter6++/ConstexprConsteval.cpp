#include <iostream>
#include <type_traits>

constexpr int isGreater(int x, int y)
{
    return (x > y ? x : y);

}


constexpr int someFunc()
{
    if (std::__is_constant_evaluated())
        return 0;
    else
        return 1;   
}


// Uses abbreviated function template (C++20) and `auto` return type to make this function work with any type of value
// See 'related content' box below for more info (you don't need to know how these work to use this function)
consteval auto compileTime(auto value)
{
    return value;
}

constexpr int greater(int x, int y) // function is constexpr
{
    return (x > y ? x : y);
}





int main()
{
    constexpr int x{ 5 };
    constexpr int y{ 6 };

    constexpr int g{ isGreater(x, y)};

    std::cout << g << "is greater";
    std::cout << isGreater(x, y) << "is greater"; 

    std::cout << greater(5, 6) << '\n';              // may or may not execute at compile-time
    std::cout << compileTime(greater(5, 6)) << '\n'; // will execute at compile-time

    // int x { 5 };
    std::cout << greater(x, 6) << '\n';              // we can still call the constexpr version at runtime if we wish

    return 0;
}
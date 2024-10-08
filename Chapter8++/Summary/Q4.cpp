#include <iostream>

template <typename T>
int count(T) // This is the same as int count(T x), except we're not giving the parameter a name since we don't use the parameter
{
    static int c { 0 };
    return ++c;
}

int main()
{
    std::cout << count(1) << '\n'; //int 1 -> First instantiation
    std::cout << count(1) << '\n'; // int 2 -> static (global variables) int 1 + 1
    std::cout << count(2.3) << '\n'; //numeric conversion float -> int (first instantiation) -> 1 
    std::cout << count<double>(1) << '\n'; //int 2 -> reuse the instantiated instance (1 + 1)

    return 0;
}
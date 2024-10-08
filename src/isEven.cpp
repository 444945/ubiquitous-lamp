#include "isEven.h"
#include <iostream>

int inputInteger() {
    std::cout << "Input an integer:";
    int x{};
    std::cin >> x;
    return x;
}

constexpr bool isEven(int x) {
    return x % 2 == 0;
};

void isEven() {
    int x {inputInteger()};
    if (isEven(x))
    std::cout << "Integer is even!\n";
    else
    std::cout << "Integer is not even!\n";
}

#include "decToHex.h"
#include <iostream>

void decToHex() {
    std::int32_t x{};
    std::cin >> x;
    std::cout << std::hex << x << '\n';
}

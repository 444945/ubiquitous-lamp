#include "stringGen.h"
#include <iostream>

const std::string generator() {
    constexpr std::string_view chars { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };
    std::string result{};
    result.reserve(30);
    for (int i = 0; i < 30; ++i) {
        result += chars[rand() % chars.length()];
    }
    return result;
}

void showString(){
    std::cout << "Your randomly generated string is:" << generator() <<'\n';
}

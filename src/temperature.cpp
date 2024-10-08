#include "temperature.h"
#include <iostream>

void convertTemperature() {
    std::cout << "What's the temperature outside?: ";
    double temp;
    std::cin >> temp;
    std::cout << "Celsius (C) or Fahrenheit (F) ?: ";
    std::string unit;
    std::cin >> unit;
    if (unit == "c" || unit == "C" || unit == "Celsius" || unit == "celsius") {
        std::cout << temp << " Celsius is " << 1.8 * temp + 32 << " in Fahrenheit!\n";
    }
    else if (unit == "f" || unit == "F" || unit == "Fahrenheit" || unit == "fahrenheit") {
        std::cout << temp << " Fahrenheit is " <<(temp - 32) / 1.8 << " in Celsius!\n";
    }
    else {
        std::cout << unit << "Is not valid!\n";
    }
}

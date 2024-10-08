#include "calc.h"
#include <iostream>

void calculator() {
    std::cout << "Enter two numbers:\n";
    double f1{};
    double f2{};
    std::cin >> f1 >> f2;
    std::cout << "Enter an operator(+, -, *, /):\n";
    char op{};
    std::cin >> op;
    if (op=='+') {
        std::cout << f1 + f2 << '\n';
    }
    else if (op=='-') {
        std::cout << f1-f2 << '\n';
    }
    else if (op=='*') {
        std::cout << f1*f2 << '\n';
    }
    else if (op=='/') {
        if (f2==0){
            std::cout << "Error: Division by zero.\n";
        }
        std::cout << f1/f2 << '\n';
    }
    else std::cout << "Error: Invalid operator\n";
}

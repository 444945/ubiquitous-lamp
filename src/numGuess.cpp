#include "numGuess.h"
#include <iostream>

void numGuess() {
    int tries{};
    int guess{};
    srand(time(NULL));
    int num {rand() % 100 + 1};
    do {
        tries++;
        std::cout << "Guess the number! (1-100): ";
        std::cin >> guess;
        if (guess>num) std::cout << "Too high!\n";
        else if (guess<num) std::cout << "Too low!\n";
        else std::cout <<"Congratulations! The number was: " << num << '\n' << "It took you " << tries <<" tries.\n";;
    }
    while (num!=guess);
}

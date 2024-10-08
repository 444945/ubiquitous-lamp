#include "dice.h"
#include <iostream>
#include <random>

void rollDice(){
    std::cout << "Welcome to the Casino.\nYou will roll a random number.\n1-49 = Lose\n50-100 = Win\nAre you ready?:\n";
    std::string yn{};
    std::string again{};
    std::cin >> yn;
    if (!yn.starts_with("y") && !yn.starts_with("Y")) {};
    // srand(time(NULL));
    // int x { (rand() % 100) + 1 };
    do {
    std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);
    std::cout << "The dice rolled: " << dist(gen) << ".\n";
    std::cout << "Try again?: ";
    std::cin >> again;
    }
    while (again.starts_with("y") || again.starts_with("Y"));
    {};
}

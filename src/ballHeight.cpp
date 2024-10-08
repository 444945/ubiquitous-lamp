#include "ballHeight.h"
#include <iostream>

double bbb(double h, double sec) {
 constexpr double gravity { 9.8 };
 double dist { gravity * (sec * sec) / 2};
 double ballHeight { h - dist };
 if (ballHeight < 0.0)
		return 0.0;

return ballHeight;
}

void ballFalling() {
    std::cout << "Enter the height of tower (In the superior unit of measure, Meters):\n";
    double h{};
    std::cin >> h;
    std::cout << "At 0 seconds, the ball is at height: " << h << " meters\n";
    std::cout << "At 1 seconds, the ball is at height: " << bbb(h, 1) << " meters\n";
    std::cout << "At 2 seconds, the ball is at height: " << bbb(h, 2) << " meters\n";
    std::cout << "At 3 seconds, the ball is at height: " << bbb(h, 3) << " meters\n";
    std::cout << "At 4 seconds, the ball is at height: " << bbb(h, 4) << " meters\n";
    std::cout << "At 5 seconds, the ball is at height: " << bbb(h, 5) << " meters\n";
}

#include "ballHeight.h"
#include "calc.h"
#include "decToHex.h"
#include "dice.h"
#include "isEven.h"
#include "numGuess.h"
#include "stringGen.h"
#include "temperature.h"
#include <iostream>


int main() {
    std::cout << "What would you like to access?\n";
    std::cout << "1. Calculate ball height\n2. Basic calculator\n3. Decimal to hex conversion tool"
              << "\n4. Number guessing game\n5. String generator\n6. Temperature conversion tool\n7. Casino\n8. isEven\n";
    int x{};
    std::cin >> x;

    switch(x){
        case 1:
            ballFalling();
            break;
        case 2:
            calculator();
            break;
        case 3:
            decToHex();
            break;
        case 4:
            numGuess();
            break;
        case 5:
            showString();
            break;
        case 6:
            convertTemperature();
            break;
        case 7:
            rollDice();
            break;
        case 8:
            isEven();
            break;
    }
    return 0;
}

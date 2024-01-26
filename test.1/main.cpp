#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "main.h"

int main()
{

    std::cout << "_________Basic Arithmetic Calculator_________ \n";
    while(true)
    {
        std::cout << "_____________________________________________ \n ";
        std::string equation{};
        std::cout << "Enter the arithmetic equation using the operators +,-,*,/,^: \n" << " Eq: ";
        std::cin >> equation;

        std::vector<double> values {numericVals(equation)};
        std::vector<char> operators{operate(equation)};

        int numberOfBracket{bracketCount(operators)};


        if (errorCheck(equation,operators) == true)
        {
            std::cout << " Ans: " << bracketSolve(values,operators,numberOfBracket,equation) << "\n";
        }

    }

    return 0;
}

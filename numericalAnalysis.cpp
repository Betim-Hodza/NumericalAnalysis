// NumericalAnalysis.cpp

#include <iostream>
#include <string>
#include "MathApproximator.h"

void displayMenu()
{
    std::cout << "Simpson's & Trapezoidal Approximation\n";
    std::cout << "Choose a method:\n";
    std::cout << "1. Simpson's Method\n";
    std::cout << "2. Trapezoidal Method\n";
    std::cout << "Enter your choice: ";
}

int main()
{
    try
    {
        // vars we need
        int N, a, b;
        // function prototype ?
        std::string function;
        char choice;

        displayMenu();
        // get user choice
        std::cin >> choice;
        std::cin.ignore();

        if (choice != '1' && choice != '2')
        {
            throw std::invalid_argument("Invalid choice.");
        }

        std::cout << "Enter the function to integrate: ";
        // get the line and store it in our function var
        std::getline(std::cin, function);
        // get the rest of our inputs
        std::cout << "Enter the number of intervals (N): ";
        std::cin >> N;
        std::cout << "Enter the lower bound (a): ";
        std::cin >> a;
        std::cout << "Enter the upper bound (b): ";
        std::cin >> b;

        // define a math approximator object
        MathApproximator approximator(N, a, b, function);

        double result = (choice == '1') ? approximator.simpsonsApprox() : approximator.trapezoidalApprox();

        std::cout << (choice == '1' ?  "Simpson's" : "Trapezoidal") << " Approximation result: " << result << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
// MathApproximator.h
#ifndef MATH_APPROXIMATOR_H
#define MATH_APPROXIMATOR_H

#include <string>

class MathApproximator 
{
    public:
        MathApproximator(int intervals, int lowerbound, int upperbound, const std::string& func);
        double simpsonsApprox();
        double trapezoidalApprox();
    
    private:
        int N, a, b;
        double deltaX;
        std::string function;
};


#endif 
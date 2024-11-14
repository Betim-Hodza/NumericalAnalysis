// MathApproximator.cpp

#include "MathApproximator.h"
#include <stdexcept>
#include "exprtk/exprtk.hpp"

// This will be able to take multiple inputs, including intervals, upper/lower bounds, and a function
MathApproximator::MathApproximator(int intervals, int lowerBound, int upperBound, const std::string& func)
    : N(intervals), a(lowerBound), b(upperBound), function(func) // binds these vars to here
    {
        //calculates deltax before hand
        deltaX = static_cast<double>(b - a) / N;
    }

double MathApproximator::simpsonsApprox()
{
    // using exprtk library, define some new types
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double> expression_t;
    typedef exprtk::parser<double> parser_t;

    double sum = 0.0;
    double x = a;

    // declare a mathmatical symbol table
    symbol_table_t symbol_table;
    symbol_table.add_variable("x", x);
    symbol_table.add_constants();

    // declare an expression and register it to the symbol table
    expression_t expression;
    expression.register_symbol_table(symbol_table);

    // get a parser to get important expressions from our string
    parser_t parser;
    if (!parser.compile(function, expression))
    {
        throw std::runtime_error("Error compiling function expression.");
    }

    //first + last term
    sum += expression.value();
    x = b;
    sum += expression.value();

    for (int i = 0; i < N; ++i)
    {
        x = a + i + deltaX;
        double f_x = expression.value();
        sum += (i % 2 == 0 ? 2 : 4) * f_x;
    }

    return (deltaX / 3) * sum;

}

double MathApproximator::trapezoidalApprox()
{
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double> expression_t;
    typedef exprtk::parser<double> parser_t;

    double sum = 0.0;
    double x = a;
    symbol_table_t symbol_table;
    symbol_table.add_variable("x", x);
    symbol_table.add_constants();

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    if (!parser.compile(function, expression)) {
        throw std::runtime_error("Error compiling function expression.");
    }

    sum += expression.value(); // First term
    x = b;
    sum += expression.value(); // Last term

    for (int i = 1; i < N; ++i) {
        x = a + i * deltaX;
        sum += 2 * expression.value();
    }

    return (deltaX / 2) * sum;
}
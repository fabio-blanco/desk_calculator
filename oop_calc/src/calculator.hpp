#ifndef DC_CALCULATOR_HPP
#define DC_CALCULATOR_HPP

#include "lexer.hpp"
#include "parser.hpp"
#include <iostream>
#include <map>
#include <string>

class Calculator {  
    public:
        Calculator(std::istream* in);
        ~Calculator();
        int run();

    private:
        int no_of_errors;
        std::istream* input;
        std::map<std::string, double> table;
        Lexer lexer;
        Parser parser;

        void skip();
};

#endif // DC_CALCULATOR_HPP

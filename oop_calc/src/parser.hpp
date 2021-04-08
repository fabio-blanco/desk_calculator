#ifndef DC_CALCULATOR_PARSER_HPP
#define DC_CALCULATOR_PARSER_HPP

#include "lexer.hpp"
#include <map>
#include <string>

class Parser {
    public:
        Parser(Lexer* l, std::map<std::string, double>* t);
        double expr(bool get);

        class Zero_divide{};

    private:
        Lexer* lexer;
        std::map<std::string, double>* table;

        double prim(bool get);
        double term(bool get);
};

#endif // DC_CALCULATOR_PARSER_HPP

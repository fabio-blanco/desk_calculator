#ifndef CALC_PARSER_IMPL_HPP
#define CALC_PARSER_IMPL_HPP

#include "parser.hpp"
#include "error.hpp"
#include "lexer.hpp"
#include "table.hpp"

namespace Parser {
    double prim(bool get);
    double term(bool get);
    //double expr(bool get);
    using Parser::expr;

    using Lexer::get_token;
    using Lexer::curr_tok;
}

#endif // CALC_PARSER_IMPL_HPP

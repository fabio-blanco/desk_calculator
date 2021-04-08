#include "parser.hpp"

Parser::Parser(Lexer* l, std::map<std::string, double>* t) {
    lexer = l;
    table = t;
}

/*
 * Handle primaries
 */
double Parser::prim(bool get) {
    if(get) lexer->get_token();
    Lexer::Token_value curr_tok = lexer->get_curr_token();

    switch(curr_tok) {
        case Lexer::NUMBER: //floating-point constant
            lexer->get_token();
            return lexer->get_number_value();
        case Lexer::NAME:
            {
                double& v = (*table)[lexer->get_string_value()];
                if(lexer->get_token() == Lexer::ASSIGN) {
                    v = expr(true);
                }
                return v;
            }
        case Lexer::MINUS: // unary minus
            return -prim(true);
        case Lexer::LP:
            {
                double e = expr(true);
                if(lexer->get_curr_token() != Lexer::RP) {
                    throw Lexer::Syntax_error("')' expected");
                }
                lexer->get_token(); //eat ')'
                return e;
            }
        case Lexer::END:
            return 1;
        default:
            throw Lexer::Syntax_error("primary expected");
    }
}

/*
 * Multiplication and Division
 */
double Parser::term(bool get) {
    double left=prim(get);

    for(;;)
        switch(lexer->get_curr_token()) {
            case Lexer::MUL:
                left *= prim(true);
                break;
            case Lexer::DIV:
                if(double d = prim(true)) {
                    left /= d;
                    break;
                }
                throw Zero_divide();
            default:
                return left;
        }
}

/*
 * Add and subtract
 */
double Parser::expr(bool get) {
    double left=term(get);

    for(;;)
        switch(lexer->get_curr_token()) {
            case Lexer::PLUS:
                left += term(true);
                break;
            case Lexer::MINUS:
                left -= term(true);
                break;
            default:
                return left;
        }
}

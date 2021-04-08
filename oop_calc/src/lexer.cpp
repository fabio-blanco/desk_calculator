#include "lexer.hpp"
#include <cctype>

Lexer::Lexer(std::istream* in) {
    input = in;
}

Lexer::Token_value Lexer::get_token() {
    char ch;

    do {
        if(!input->get(ch)) return curr_tok=END;
    } while( ch != '\n' && isspace(ch) );

    switch(ch) {
        case ';':
        case '\n':
            return curr_tok=PRINT;
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return curr_tok=Token_value(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            input->putback(ch);
            *input >> number_value;
            return curr_tok=NUMBER;
        default:
            if(isalpha(ch)) {
                string_value = ch;
                while(input->get(ch) && isalnum(ch)) {
                    string_value.push_back(ch);
                }
                input->putback(ch);

                if(string_value == "end") {
                    return curr_tok=END;
                }

                return curr_tok=NAME;
            }
            throw Syntax_error("bad token");
            return curr_tok=PRINT;
    }
}

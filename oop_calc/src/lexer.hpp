#ifndef DC_LEXER_HPP
#define DC_LEXER_HPP

#include <string>
#include <sstream>

class Lexer {
    public:

        enum Token_value {
            NAME,       NUMBER,     END,
            PLUS='+',   MINUS='-',  MUL='*',    DIV='/',
            PRINT=';',  ASSIGN='=', LP='(',     RP=')'
        };

        struct Syntax_error {
            const char* p;
            Syntax_error(const char* q) {p=q;}
        };

        Lexer(std::istream* in);

        Token_value get_token();
        Token_value get_curr_token() const;
        double get_number_value() const;
        std::string get_string_value() const;
   private:

        Token_value curr_tok;
        double number_value;
        std::string string_value;
        std::istream* input;
};

inline Lexer::Token_value Lexer::get_curr_token() const
{
    return curr_tok;
}

inline double Lexer::get_number_value() const
{
    return number_value;
}

inline std::string Lexer::get_string_value() const
{
    return string_value;
}

#endif // DC_LEXER_HPP

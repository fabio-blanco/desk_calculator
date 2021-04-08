#include "calculator.hpp"

Calculator::Calculator(std::istream* in)
    : lexer(in), parser(&lexer, &table)
{
    input = in;

    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;
}

Calculator::~Calculator() {
    //TODO: destruct allocated members if needed
}

void Calculator::skip() {
    no_of_errors++;

    while(*input) {
        char ch;
        input->get(ch);

        switch(ch) {
            case '\n':
            case ';':
                input->get(ch);
                return;
        }
    }
}

int Calculator::run() {
    using namespace std;

    while(*input) {
        try {
            lexer.get_token();
            if(lexer.get_curr_token() == Lexer::END) break;
            if(lexer.get_curr_token() == Lexer::PRINT) break;
            cout << parser.expr(false) << '\n';
        } catch(Parser::Zero_divide) {
            cerr << "attempt to divide by zero\n";
            skip();
        } catch(Lexer::Syntax_error e) {
            cerr << "syntax error" << e.p << "\n";
            skip();
        }
    }

    return no_of_errors;
}

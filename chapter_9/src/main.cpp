#include "parser.hpp"
#include "lexer.hpp"
#include "error.hpp"
#include "table.hpp"
#include "driver.hpp"

#include <sstream>

int main(int argc, char* argv[]) {
    using namespace std;
    using namespace Driver;

    switch(argc) {
        case 1:
            input = &cin;
            break;
        case 2:
            input = new istringstream(argv[1]);
            break;
        default:
            cerr << "too many arguments\n";
            return 1;
    }

    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;

    while(*input) {
        try{
            Lexer::get_token();
            if (Lexer::curr_tok == Lexer::END) break;
            if (Lexer::curr_tok == Lexer::PRINT) continue;
            cout << Parser::expr(false) << '\n';
        } catch(Error::Zero_divide) {
            cerr << "attempt to divide by zero\n";
            skip();
        } catch(Error::Syntax_error e) {
            cerr << "syntax error:" << e.p << "\n";
            skip();
        }

    }

    if(input != &cin) delete input;
    return no_of_errors;
}

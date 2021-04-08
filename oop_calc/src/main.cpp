#include "calculator.hpp"
#include <sstream>

int main(int argc, char* argv[]) {
    using namespace std;

    istream* input;

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

    Calculator calculator(input);
    int no_of_errors = calculator.run();

    if(input != &cin) delete input;
    return no_of_errors;
}

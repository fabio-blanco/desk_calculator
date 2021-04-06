#include "driver.hpp"

int Driver::no_of_errors;
std::istream* Driver::input;

void Driver::skip() {
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


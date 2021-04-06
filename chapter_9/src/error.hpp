#ifndef CALC_ERROR_HPP
#define CALC_ERROR_HPP

namespace Error {
    struct Zero_divide{};

    struct Syntax_error {
        const char* p;
        Syntax_error(const char* q) {p=q; }
    };
}

#endif // CALC_ERROR_HPP

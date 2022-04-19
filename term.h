#ifndef LAB_TERM_H
#define LAB_TERM_H

#include <istream>
#include <ostream>
#include "polynomial.h"

class term {
public:
    term(int num = 0, int pow = 0);

    term operator+(const term &t);

    friend
    std::ostream &operator<<(std::ostream &out, const term &t);

    friend
    std::istream &operator>>(std::istream &in, const term &t);

    friend polynomial;

private:
    void _string_to_term(char *s);


    int pow;
    int num;
};

std::ostream &operator<<(std::ostream &out, const term &t);

std::istream &operator>>(std::istream &in, term &t);

#endif //LAB_TERM_H

#include "term.h"

term::term(int num, int pow): pow(pow), num(num) {
}

term term::operator+(const term &t) {

    return term(t.pow, this->num + t.num);
}

std::ostream &operator<<(std::ostream &out, const term &t) {
    if (t.num == -1) {
        out << '-';
    } else if (t.num == 0) {
        out << 0;
        return out;
    } else if (t.num != 1) {
        out << t.num;
    }

    if (t.pow == 0 && t.num == 1) {
        out << 1;
        return out;
    } else if (t.pow != 0) {
        out << 'x';
    }

    if (t.pow != 1 && t.pow != 0) {
        out << '^' << t.pow;
    }

    return out;
}

// std::istream &operator>>(std::istream &in, const term &t) {

// }
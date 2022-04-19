#include "term.h"
#include <cctype>
#include <sstream>

using namespace std;

static const int MAX_INPUT = 40;

term::term(int num, int pow): pow(pow), num(num) {
}

void term::_string_to_term(char *s) {
    char *beg = s;

    bool neg = false;
    bool deg_sep = false;

    stringstream num_ss;
    stringstream pow_ss;

    while(*beg) {
        if (*beg == '-') {
            neg = true;
        }
        if (*beg == '^') {
            deg_sep = true;
        }

        if (isdigit(*beg) && !deg_sep) {
            num_ss << *beg;
        }

        if (isdigit(*beg) && deg_sep) {
            pow_ss << *beg;
        }



        beg++;
    }
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

std::istream &operator>>(std::istream &in, term &t) {
    char s[MAX_INPUT];
    in.getline(s, MAX_INPUT);
    t._string_to_term(s);
    return in;
}


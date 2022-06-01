#include "term.h"
#include <cctype>
#include <sstream>

static const int MAX_INPUT = 100;

term::term(int num, int pow) : pow(pow), num(num) {
}

term term::operator+(const term &t) {
    return term(t.num + this->num, t.pow);
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

void term::_string_to_term(char *s) {
    char *beg = s;

    bool neg = false;
    bool deg_sep = false;

    std::stringstream num_ss("");
    std::stringstream pow_ss("");

    this->num = 0;
    this->pow = 0;
    while (*beg) {
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

        if (*(beg + 1) == 0 || *(beg + 1) == '+') {
            int num_temp = 1;
            if (num_ss.str() != "") num_ss >> num_temp;
            // num_ss.clear();
            // num_ss.str("");
            num_ss = std::stringstream("");
            if (neg) {
                num_temp *= -1;
            }
            this->num += num_temp;

            int pow_temp = 1;
            if (pow_ss.str() != "") pow_ss >> pow_temp;
            // pow_ss.clear();
            // pow_ss.str("");
            pow_ss = std::stringstream("");

            this->pow = pow_temp;

            neg = false;
            deg_sep = false;
        }
        beg++;
    }
}

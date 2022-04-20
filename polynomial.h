#ifndef LAB_POLYNOMIAL_H
#define LAB_POLYNOMIAL_H

#include "term.h"
#include <ostream>
#include "vector.h"

// class term;

class polynomial {
public:
    polynomial();
    polynomial(int x);
    polynomial(term t);

    polynomial &operator=(const &polynomial p);

    polynomial &operator+=(const &polynomial p);
    polynomial &operator*=(const &polynomial p);

    polynomial operator*(const &polynomial p) const;
    polynomial operator+(const &polynomial p) const;

    friend
    std::ostream &operator<<(std::ostream &out, const polynomial &p);

private:
    int degree;
    vector<term> poly;

};

std::ostream &operator<<(std::ostream &out, const polynomial &p);

#endif //LAB_POLYNOMIAL_H

#ifndef LAB_PILYNOMIAL_H
#define LAB_PILYNOMIAL_H

#include "term.h"
#include "MyVector.h"

class polynomial {
public:
    polynomial();
    polynomial(int x);
    polynomial(term t);


private:
    int degree;
    MyVector<term> poly;

};



#endif //LAB_PILYNOMIAL_H

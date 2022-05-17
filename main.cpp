#include "polynomial.h"
#include <iostream>
// #include "vector.h"

// using namespace std;

int main() {
    // term t(5, 2);
    polynomial p = term(5, 2);
    p += term(2, 1);

    polynomial p1 = term(3, 2);
    p1 += term(1, 1);


    std::cout << p + p1 << std::endl << p * p1 << std::endl;

    return 0;
}
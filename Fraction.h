#ifndef LAB_FRACTION_H
#define LAB_FRACTION_H

#include <ostream>

static const int N_DEC = 4;

class Fraction {
public:
    Fraction(const char *s);

    Fraction(double n);

    Fraction(int num = 0, int denom = 1);

    Fraction operator+(const Fraction &fr) const;
    // Fraction operator+=(const Fraction &fr);

    Fraction operator+(const int x) const;
    // Fraction operator+=(const int x);

    Fraction operator+(const double x) const;
    // Fraction operator+=(const double x);

    friend
    Fraction operator+(const int x, const Fraction &fr);

    friend
    Fraction operator+(const double x, const Fraction &fr);

    static int gcd(int a, int b);

    friend
    std::ostream &operator<<(std::ostream &out, const Fraction &fr);

private:
    static void _FractionStringToIntArr(const char *s, int *arr);

    void Conv();

    int numerator;
    int denominator;
    int floor;
    bool neg;
};

std::ostream &operator<<(std::ostream &out, const Fraction &fr);

Fraction operator+(const int x, const Fraction &fr);

Fraction operator+(const double x, const Fraction &fr);

#endif //LAB_FRACTION_H

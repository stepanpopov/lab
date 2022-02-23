#include "Fraction.h"

#include <cmath>
#include <cstring>

// #include <iostream> // Debug

Fraction::Fraction(const char *s) {
    int temp_i[3];
    _FractionStringToIntArr(s, temp_i);

    if (temp_i[2] == 0) {
        floor = 0;
        numerator = temp_i[0];
        denominator = temp_i[1];
    } else {
        floor = temp_i[0];
        numerator = temp_i[1];
        denominator = temp_i[2];
    }

    Conv();
}

void Fraction::_FractionStringToIntArr(const char *s, int *arr) {
    int len = strlen(s);
    char temp[len];

    arr[2] = 0;
    for (int i = 0, j = 0, z = 0; i < len; i++) {
        if (s[i] == ' ' || s[i] == '/') {
            temp[j] = '\0';
            arr[z] = atoi(temp);
            z++;
            j = 0;
        } else {
            temp[j] = s[i];
            j++;
        }
        if (i == len - 1) {
            temp[j] = '\0';
            arr[z] = atoi(temp);
        }
    }
}

Fraction::Fraction(double n) : floor(0) {
    numerator = n * pow(10, N_DEC);
    denominator = pow(10, N_DEC);

    Conv();
}

Fraction::Fraction(int num, int denom) : numerator(num),
                                         denominator(denom),
                                         floor(0) {
    Conv();
}

Fraction Fraction::operator+(const Fraction &fr) const {
    Fraction sumFr;

    int nod = gcd(denominator, fr.denominator);

    int mul1 = fr.denominator / nod;
    int mul2 = denominator / nod;

    sumFr.denominator = denominator * mul1;

    int num1 = numerator + abs(floor) * denominator;
    if (floor < 0) num1 *= -1;

    int num2 = fr.numerator + abs(fr.floor) * fr.denominator;
    if (fr.floor < 0) num2 *= -1;

    sumFr.numerator = mul1 * num1 + mul2 * num2;

    // std::cout << "DEBUG " << sumFr.numerator << " " << sumFr.denominator << std::endl;

    sumFr.Conv();
    return sumFr;
}

Fraction Fraction::operator+(const int x) const {
    Fraction xFr(x, 1);
    return (*this + xFr);
}

Fraction Fraction::operator+(const double x) const {
    Fraction xFr(x);
    return (*this + xFr);
}

Fraction operator+(const int x, const Fraction &fr) {
    return (fr + x);
}

Fraction operator+(const double x, const Fraction &fr) {
    return (fr + x);
}

void Fraction::Conv() {
    if (denominator == 0) {  // ????
        numerator = 0;
        return;
    }

    int neg = 1;
    if (floor < 0) {
        neg *= -1;
        floor *= -1;
    }
    if (numerator < 0) {
        neg *= -1;
        numerator *= -1;
    }

    floor += numerator / denominator;
    numerator = numerator % denominator;

    int nod = gcd(numerator, denominator);
    numerator /= nod;
    denominator /= nod;

    if (floor == 0) {
        numerator *= neg;
    } else {
        floor *= neg;
    }
}

int Fraction::gcd(int a, int b) {
    if (b != 0) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}

std::ostream &operator<<(std::ostream &out, const Fraction &fr) {
    if (fr.numerator == 0) {
        out << fr.floor;
    } else if (fr.floor == 0) {
        out << fr.numerator << "/" << fr.denominator;
    } else {
        out << fr.floor << " " << fr.numerator << "/" << fr.denominator;
    }

    return out;
}


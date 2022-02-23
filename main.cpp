#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {

    // Fraction x(65, 5);
    Fraction x("9/7");
    Fraction y("-5/7");
    // Fraction x(-0.0005);
    // cout << x << endl << y << endl;
    cout << 0.25 + x << endl;
    // cout << Fraction::gcd(5, 45) << endl;

    // cout << endl << Fraction(26, 7);


/*//ввод дроби с клавиатуры
    cout << "Введите дробь: \n";
    fraction z;
    cin >> z;
    cout << "z=" << z << endl;
//проверка конструкторов
    fraction fr1(10, 14), fr2;
    cout << "fr2=" << fr2 << endl;
    cout << "fr1=" << fr1 << endl;
    fraction fr = "-1 4/8";
    cout << "fr=" << fr << endl;
    fraction x(z), y;
    cout << "x=" << x << endl;
    double dbl = -1.25;
    fraction f = dbl;
    cout << "f=" << f << endl;
//проверка перегруженной операции "+"
    y = x + z;
    cout << "y=" << y << endl;
    y += x;
    f += dbl / 2;
    cout << "f=" << f << endl;
    y = x + dbl;
    cout << "y=" << y << endl;
    y = dbl + y;
    cout << "y=" << y << endl;
    y += dbl;
    cout << "y=" << y << endl;
    int i = 5;
    y += i;
    cout << "y=" << y << endl;
    y = i + x;
    cout << "y=" << y << endl;
    y = x + i;
    cout << "y=" << y << endl;
    y += dbl + i + x;
    cout << "y=" << y << endl;*/
    return 0;
}

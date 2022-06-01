#include "polynomial.h"
#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    cout << "Введите количество термов ";
    int n;
    cin >> n;
    cin.ignore(100, '\n');

    vector<term> vec;
    for(int i = 0; i < n; ++i) {
        term temp;
        cin >> temp;
        vec.add_element(temp);
    }
    cout << endl;
    for(int i = 0; i < n; ++i) {
        cout << vec[i] << endl;
    }
    cout << endl;

    term t1(5, 2);
    term t2(4, 2);

    cout << t1 << " + " << t2 << " = " << t1 + t2 << endl << endl;

    polynomial p;
    for(int i = 0; i < n; ++i) {
        p += vec[i];
    }
    cout << "p состоящий из введенных термов : " << p << endl;

    polynomial p1 = term(5, 2);
    p1 += term(2, 1);

    polynomial p2 = term(3, 2);
    p2 += term(1, 1);

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;

    cout << "Конструктор копирования : p3(p1) = ";
    polynomial p3(p1);
    cout << p3 << endl;

    cout << "Оператор присваивания : p3 = p2 ";
    p3 = p2;
    cout << p2 << endl;

    return 0;
}
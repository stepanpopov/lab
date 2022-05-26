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
        // cout << temp << endl;
        vec.add_element(temp);
    }
    cout << endl;
    for(int i = 0; i < n; ++i) {
        cout << vec[i] << endl;
    }
    cout << endl;

    term t1(5, 2);
    term t2(4, 2);

    cout << t1 << " + " << t2 << " = " << t1 + t2 << endl;


    /*polynomial p = term(5, 2);
    p += term(2, 1);

    polynomial p1 = term(3, 2);
    p1 += term(1, 1);


    std::cout << p + p1 << std::endl << p * p1 << std::endl;*/

    return 0;
}
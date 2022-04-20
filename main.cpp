#include "term.h"
#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    term t(5, 2);

    vector<term> v(t);
    v.add_element(term(3, 2));

    cout << v[1];

    return 0;
}
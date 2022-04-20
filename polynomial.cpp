#include "polynomial.h"

polynomial::polynomial(): poly(term(0, 0)), degree(0) {}

polynomial::polynomial(int x): poly(term(x, 0)), degree(0) {}

polynomial::polynomial(term t): poly(t), degree(t.pow) {}

/*polynomial &polynomial::operator=(const &polynomial p)

polynomial &polynomial::operator+=(const &polynomial p);
polynomial &polynomial::operator*=(const &polynomial p);

polynomial polynomial::operator*(const &polynomial p) const;
polynomial polynomial::operator+(const &polynomial p) const;*/

std::ostream &operator<<(std::ostream &out, const polynomial &p) {
    for(int i = 0; i < poly.get_size(); ++i) {
        if (i != 0 && i != poly.get_size) {
            cout << " + ";
        }
        cout << poly[i];
    }
    cout << endl;
    return out;
}
#include "polynomial.h"

polynomial::polynomial() : poly(term(0, 0)), degree(0) {}

polynomial::polynomial(int x) : poly(term(x, 0)), degree(0) {}

polynomial::polynomial(term t) : degree(t.pow) {
    for (int i = 0; i <= degree; ++i) {
        if (i == degree) {
            poly.add_element(t);
        } else {
            poly.add_element(term(0, i));
        }
    }
}

// polynomial &polynomial::operator=(const polynomial &p)

polynomial &polynomial::operator+=(const polynomial &p) {
    *this = *this + p;
    return *this;
}

polynomial &polynomial::operator*=(const polynomial &p) {
    *this = *this * p;
    return *this;
}

polynomial polynomial::operator*(const polynomial &p) const {
    const vector<term> &vec1 = this->poly;
    const vector<term> &vec2 = p.poly;

    polynomial mul_res(term(0, p.degree + this->degree));

    for (int i = 0; i < vec1.get_size(); ++i) {
        for (int j = 0; j < vec2.get_size(); ++j) {
            mul_res.poly[i + j].num += vec1[i].num * vec2[j].num;
        }
    }

    return mul_res;
}

polynomial polynomial::operator+(const polynomial &p) const {
    polynomial sum_res(p.poly[0].num + this->poly[0].num);

    int max_degree = std::max(p.degree, this->degree);
    sum_res.degree = max_degree;
    for (int i = 1; i <= max_degree; ++i) {
        int num = 0;
        if (i <= p.degree) {
            num += p.poly[i].num;
        }
        if (i <= this->degree) {
            num += this->poly[i].num;
        }
        sum_res.poly.add_element(term(num, i));
    }
    return sum_res;
}

std::ostream &operator<<(std::ostream &out, const polynomial &p) {
    int poly_size = p.poly.get_size();
    for (int i = poly_size - 1; i >= 0; --i) {
        bool flag = 0;
        if (i == 0 && p.poly[i].get_num() != 0) {
            flag = 1;
        } else if (p.poly[i].get_pow() != 0 && p.poly[i].get_num() != 0) {
            flag = 1;
        }

        if (i != poly_size - 1 && flag) {
            out << " + ";
        }
        if (flag) {
            out << p.poly[i];
        }

    }
    // out << std::endl;
    return out;
}
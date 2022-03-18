#include "MySet.h"

ostream &operator<<(ostream &out, MySet &s);

MySet operator+(MySet &s1, MySet &s2);

MySet operator-(MySet &s1, MySet &s2);

MySet operator*(MySet &s1, MySet &s2);

bool MySet::operator==(MySet &s);

MySet &MySet::operator+=(MySet &s);

MySet &MySet::operator-=(MySet &s);

MySet &MySet::operator*=(MySet &s);

void MySet::add_element(char *el);

void MySet::delete_element(char *el) {
    int ind = binarySearch(el);
    if (ind != -1) {
        for(int i = ind; i < size - 1; ++i) {
            pdata[i] = pdata[i + 1];
        }
    }
    size--;
}

bool MySet::is_element(char *el) {
    return (binarySearch(el) != -1);
}

int MySet::binarySearch(char *el) {
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (strcmp(pdata[m], el) == 0) {
            return m;
        } else if (strcmp(pdata[m], el) < 0) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}
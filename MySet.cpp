#include "MySet.h"

/*ostream &operator<<(ostream &out, MySet &s) {

}*/

MySet operator+(MySet &s1, MySet &s2) {
    MySet sRes;

    bool isElement[s2.size];
    for (int i = 0; i < s2.size; ++i) {
        isElement[i] = false;
    }

    for (int i = 0; i < s1.size; ++i) {
        sRes.MyVector::add_element(s1[i]);
        int indS2 = s2.binarySearch(s1[i]);
        if (indS2 != -1) isElement[indS2] = true;
    }

    for (int i = 0; i < s2.size; ++i) {
        if (!isElement[i]) {
            sRes.MyVector::add_element(s2[i]);
        }
    }
    sRes.MyVector::sort();

    /*MySet *sMaxSize, *sMinSize;
    if (s1.size >= s2.size) {
        sMaxSize = &s1;
        sMinSize = &s2;
    } else {
        sMaxSize = &s2;
        sMinSize = &s1;
    }

    int j = 0;
    for(int i = 0; i < sMaxSize->size; ++i) {
        if (j == sMinSize->size) {
            sRes.MyVector::add_element(sMaxSize->pdata[i]);
        } else if (strcmp(sMaxSize->pdata[i],sMinSize->pdata[j]) <= 0) {
            sRes.MyVector::add_element(sMaxSize->pdata[i]);
        } else {
            while (strcmp(sMaxSize->pdata[i],sMinSize->pdata[j]) > 0 && j < sMinSize->size) {
                sRes.MyVector::add_element(sMinSize->pdata[j]);
                j++;
            }
        }
    }*/
    return sRes;
}

MySet operator-(MySet &s1, MySet &s2) {
    MySet sRes;

    for (int i = 0; i < s1.size; ++i) {
        if (s2.binarySearch(s1[i]) == -1) {
            sRes.MyVector::add_element(s1[i]);
        }
    }

    return sRes;
}

MySet operator*(MySet &s1, MySet &s2) {
    MySet sRes;

    for (int i = 0; i < s1.size; ++i) {
        if (s2.binarySearch(s1[i]) != -1) {
            sRes.MyVector::add_element(s1[i]);
        }
    }

    return sRes;
}

bool MySet::operator==(MySet &s) {
    if (size != s.size) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        if (strcmp(pdata[i], s.pdata[i]) != 0) {
            return false;
        }
    }

    return true;
}

MySet &MySet::operator+=(MySet &s) {
    *this = *this + s;
    return *this;
}

MySet &MySet::operator-=(MySet &s) {
    *this = *this - s;
    return *this;
}

MySet &MySet::operator*=(MySet &s) {
    *this = *this * s;
    return *this;
}

void MySet::add_element(char *el) {
    if (binarySearch(el) == -1) {
        MyVector::add_element(el);
        MyVector::sort();
    }
}

void MySet::delete_element(char *el) {
    int ind = binarySearch(el);
    if (ind != -1) {
        MyVector::delete_element(ind);
    }
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
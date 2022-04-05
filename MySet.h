#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include "MyVector.h"

using namespace std;

template<class T>
class MySet : public MyVector<T> {
public:
    MySet(T el = NULL) : MyVector<T>(el) {};

    // MySet(const MySet &s) : MyVector(s) {};   ??????????
    // MySet &operator=(const MySet &s) {};      ???????????
    // friend ostream &operator<<(ostream &out, MySet &s);

    friend MySet<T> operator+(MySet<T> &s1, MySet<T> &s2) {
        MySet<T> sRes;

        bool isElement[s2.size];
        for (int i = 0; i < s2.size; ++i) {
            isElement[i] = false;
        }

        for (int i = 0; i < s1.size; ++i) {
            sRes.MyVector<T>::add_element(s1[i]);
            int indS2 = s2.binarySearch(s1[i]);
            if (indS2 != -1) isElement[indS2] = true;
        }

        for (int i = 0; i < s2.size; ++i) {
            if (!isElement[i]) {
                sRes.MyVector<T>::add_element(s2[i]);
            }
        }
        sRes.MyVector<T>::sort();

        return sRes;
    }

    friend MySet<T> operator-(MySet<T> &s1, MySet<T> &s2) {
        MySet<T> sRes;

        for (int i = 0; i < s1.size; ++i) {
            if (s2.binarySearch(s1[i]) == -1) {
                sRes.MyVector<T>::add_element(s1[i]);
            }
        }

        return sRes;
    }

    friend MySet<T> operator*(MySet<T> &s1, MySet<T> &s2) {
        MySet<T> sRes;

        for (int i = 0; i < s1.size; ++i) {
            if (s2.binarySearch(s1[i]) != -1) {
                sRes.MyVector<T>::add_element(s1[i]);
            }
        }

        return sRes;
    }

    bool operator==(MySet<T> &s);

    MySet<T> &operator+=(MySet<T> &s);

    MySet<T> &operator-=(MySet<T> &s);

    MySet<T> &operator*=(MySet<T> &s);

    void add_element(T el);

    void delete_element(T el);

    bool is_element(T el);

protected:
    using MyVector::maxsize;
    using MyVector::size;
    using MyVector::pdata;

private:
    int binarySearch(T el);
};

/*MySet operator+(MySet &s1, MySet &s2) {
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
}*/
// ostream &operator<<(ostream &out, MySet &s);
/*MySet operator+(MySet &s1, MySet &s2);
MySet operator-(MySet &s1, MySet &s2);
MySet operator*(MySet &s1, MySet &s2);*/

#include "MySet.cpp"

#endif


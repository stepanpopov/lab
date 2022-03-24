#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include "MyVector.h"


using namespace std;

class MySet : public MyVector {
public:
    MySet(char *el = NULL) : MyVector(el) {};

    // MySet(const MySet &s) : MyVector(s) {};   ??????????
    // MySet &operator=(const MySet &s) {};      ???????????

    // friend ostream &operator<<(ostream &out, MySet &s);

    friend MySet operator+(MySet &s1, MySet &s2);

    friend MySet operator-(MySet &s1, MySet &s2);

    friend MySet operator*(MySet &s1, MySet &s2);

    bool operator==(MySet &s);

    MySet &operator+=(MySet &s);

    MySet &operator-=(MySet &s);

    MySet &operator*=(MySet &s);

    void add_element(char *el);

    void delete_element(char *el);

    bool is_element(char *el);

protected:
    using MyVector::maxsize;
    using MyVector::size;
    using MyVector::pdata;

private:
    int binarySearch(char *el);
};

// ostream &operator<<(ostream &out, MySet &s);

MySet operator+(MySet &s1, MySet &s2);

MySet operator-(MySet &s1, MySet &s2);

MySet operator*(MySet &s1, MySet &s2);

#endif


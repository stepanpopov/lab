#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <string.h>

using namespace std;

const int MAX_SIZE = 5;

template<class T>
class MyVector {
public:
    MyVector(T el, int maxsz = MAX_SIZE);

    MyVector();

    // конструктор по умолчанию

    MyVector(const MyVector<T> &v);

    ~MyVector();

    void add_element(T el);

    bool delete_element(int i);

    T operator[](int i);

    void sort();

    int Size() { return size; }

    int Maxsize() { return maxsize; }

    int find(T el);

    MyVector<T> &operator=(const MyVector<T> &v);

    friend
    ostream &operator <<(ostream &out, MyVector<T> &v) {
        out << v.size << " " << v.maxsize << endl;
        for (int i = 0; i < v.size; ++i) {
            out << v.pdata[i] << endl;
        }
        return out;
    }

protected:
    int maxsize;
    int size;
    T *pdata;
private:
    void resize();
};

// template<class T> ostream &operator<<(ostream &out, MyVector<T> &v);

#include "MyVector.cpp"

#endif


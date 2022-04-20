#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string.h>

using namespace std;

const int MAX_SIZE = 5;

template<class T>
class vector {
public:
    vector(T el, int maxsz = MAX_SIZE);

    vector();

    vector(const vector<T> &v);

    ~vector();

    void add_element(T el);

    bool delete_element(int i);

    T operator[](int i);

    void sort();

    int get_size() { return size; }

    int get_maxsize() { return maxsize; }

    int find(T el);

    vector<T> &operator=(const vector<T> &v);

    friend
    ostream &operator <<(ostream &out, vector<T> &v) {
        out << "size:" << v.size << " maxsize:" << v.maxsize << endl;
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

#include "vector.cpp"

#endif


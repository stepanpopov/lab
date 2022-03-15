#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class MyVector {
public:
    MyVector(char *el = NULL, int maxsz = MAX_SIZE) : maxsize(maxsz) {
        pdata = new char * [maxsize];
        pdata[0] = el;
        for(int i = 1; i < maxsize; i++) {
            pdata[i] = NULL;
        }

    }

    MyVector(MyVector &v);

    ~MyVector();

    void add_element(char *el);

    bool delete_element(int i);

    char *operator[](int i);

    void sort();

    int Size() { return size; }

    int Maxsize() { return maxsize; }

    int find(char *el);

    MyVector &operator=(MyVector &v);

    friend ostream &operator<<(ostream &out, MyVector &v);

protected:
    int maxsize;
    int size;
    char **pdata;
private:
    void resize();
};

#endif


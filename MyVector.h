#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <string.h>

using namespace std;

const int MAX_SIZE = 5;

class MyVector {
public:
    MyVector(char *el = NULL, int maxsz = MAX_SIZE);

    MyVector(const MyVector &v);

    ~MyVector();

    void add_element(char *el);

    bool delete_element(int i);

    char *operator[](int i);

    void sort();

    int Size() { return size; }

    int Maxsize() { return maxsize; }

    int find(char *el);

    MyVector &operator=(const MyVector &v);

    friend ostream &operator<<(ostream &out, MyVector &v);

protected:
    int maxsize;
    int size;
    char **pdata;
private:
    void resize();
};

ostream &operator<<(ostream &out, MyVector &v);

#endif


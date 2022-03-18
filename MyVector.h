#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <string.h>

using namespace std;

const int MAX_SIZE = 5;

class MyVector {
public:
    MyVector(char *el = NULL, int maxsz = MAX_SIZE) : maxsize(maxsz) {
        pdata = new char *[maxsize];
        pdata[0] = el;
        for (int i = 1; i < maxsize; i++) {
            pdata[i] = NULL;
        }
    }

    MyVector(MyVector &v);

    ~MyVector() {
        delete[] pdata;
    }

    void add_element(char *el) {
        size++;
        if (size > maxsize) {
            resize();
        }
        pdata[size - 1] = el;
    }

    bool delete_element(int i) {
        for (int it = i; it < size - 1; ++it) {
            pdata[it] = pdata[it + 1];
        }
        size--;
        if (size < maxsize / 2) {
            resize();
        }
    }

    char *operator[](int i) {
        if (i < 0 || i >= size) {
            return NULL;
        } else {
            return pdata[i];
        }
    }

    void sort() {
        char *temp;
        for(int i = 0; i < size; ++i) {
            for(int j = i + 1; j < size; ++j) {
                if (strcmp(pdata[i],pdata[j]) > 0) {
                    t = pdata[i];
                    pdata[i] = pdata[j];
                    pdata[j] = t;
                }
            }
        }
    }

    int Size() { return size; }

    int Maxsize() { return maxsize; }

    int find(char *el) {
        for(int i = 0; i < size; ++i) {
            if (strcmp(el, pdata[i]) == 0) {
                return i;
            }
        }
    }

    MyVector &operator=(MyVector &v);

    friend ostream &operator<<(ostream &out, MyVector &v);

protected:
    int maxsize;
    int size;
    char **pdata;
private:
    void resize() {
        if (maxsize < size) {
            maxsize *= 1.5;
            char **newdata = new * char[maxsize];
            for (int i = 0; i < size; ++i) {
                newdata[i] = pdata[i];
            }
            for (int i = size; i < maxsize; ++i) {
                newdata[i] = NULL;
            }
            delete[] pdata;
            pdata = newdata;
        } else if (size < maxsize / 2) {
            maxsize /= 1.5;
        }
    }

    /*int binarySearch(char* arr[], int x)
    {
        int l = 0;
        int r = size - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (arr[m] == x)
                return m;

            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }*/

};

#endif


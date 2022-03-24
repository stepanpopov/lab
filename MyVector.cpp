#include "MyVector.h"

MyVector::MyVector(char *el, int maxsz) : maxsize(maxsz), size(0) {
    pdata = new char *[maxsize];
    if (el != NULL) {
        size++;
    }
    pdata[0] = el;
    for (int i = 1; i < maxsize; ++i) {
        pdata[i] = NULL;
    }
}

MyVector::MyVector(const MyVector &v) : pdata(NULL) {
    *this = v;
}

MyVector::~MyVector() {
    delete[] pdata;
}

void MyVector::add_element(char *el) {
    size++;
    if (size > maxsize) {
        resize();
    }
    pdata[size - 1] = el;
}

bool MyVector::delete_element(int i) {
    if (i < 0 || i >= size) {
        return false;
    }

    for (int it = i; it < size - 1; ++it) {
        pdata[it] = pdata[it + 1];
    }
    size--;
    if (size < maxsize / 2) {
        resize();
    }
    return true;
}

char *MyVector::operator[](int i) {
    if (i < 0 || i >= size) {
        return NULL;
    } else {
        return pdata[i];
    }
}

void MyVector::sort() {
    char *temp;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (strcmp(pdata[i], pdata[j]) > 0) {
                temp = pdata[i];
                pdata[i] = pdata[j];
                pdata[j] = temp;
            }
        }
    }
}

int MyVector::find(char *el) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(el, pdata[i]) == 0) {
            return i;
        }
    }
    return -1;
}

MyVector &MyVector::operator=(const MyVector &v) {
    size = v.size;
    maxsize = v.maxsize;

    if (pdata != NULL) {
        delete[]pdata;
    }
    pdata = new char *[maxsize];
    for (int i = 0; i < maxsize; ++i) {
        pdata[i] = v.pdata[i];
    }
    return *this;
}

ostream &operator<<(ostream &out, MyVector &v) {
    out << v.size << " " << v.maxsize << endl;
    for (int i = 0; i < v.size; ++i) {
        out << v.pdata[i] << endl;
    }
    return out;
}

void MyVector::resize() {
    if (maxsize < size) {
        if (maxsize < 2) {
            maxsize = MAX_SIZE;
        } else {
            maxsize *= 1.5;
        }
    } else if ((size < maxsize / 2) && size > MAX_SIZE) {
        maxsize /= 1.5;
    } else {
        return;
    }

    char **newdata = new char *[maxsize];
    for (int i = 0; i < maxsize; ++i) {
        newdata[i] = NULL;
    }
    for (int i = 0; i < size; ++i) {
        newdata[i] = pdata[i];
    }
    delete[] pdata;
    pdata = newdata;
}
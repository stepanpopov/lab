template<class T>
MyVector<T>::MyVector(T el, int maxsz) : maxsize(maxsz), size(1) {
    pdata = new T[maxsize];

    pdata[0] = el;
    for (int i = 1; i < maxsize; ++i) {
        pdata[i] = 0;                       // !!!!!!
    }
}

template<class T>
MyVector<T>::MyVector(const MyVector <T> &v) : pdata(0) {
    *this = v;
}

template<class T>
MyVector<T>::~MyVector() {
    delete[] pdata;
}

template<class T>
void MyVector<T>::add_element(T el) {
    size++;
    if (size > maxsize) {
        resize();
    }
    pdata[size - 1] = el;
}

template<class T>
bool MyVector<T>::delete_element(int i) {
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

template<class T>
T MyVector<T>::operator[](int i) {
    if (i < 0 || i >= size) {
        return 0;                           // !!!!
    } else {
        return pdata[i];
    }
}

template<class T>
void MyVector<T>::sort() {
    T temp;

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (pdata[i] > pdata[j]) {
                temp = pdata[i];
                pdata[i] = pdata[j];
                pdata[j] = temp;
            }
        }
    }
}

template<>
void MyVector<char *>::sort() {
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

template<class T>
int MyVector<T>::find(T el) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(el, pdata[i]) == 0) {
            return i;
        }
    }
    return -1;
}

template<class T>
MyVector <T> &MyVector<T>::operator=(const MyVector <T> &v) {
    size = v.size;
    maxsize = v.maxsize;

    if (pdata != NULL) {
        delete[]pdata;
    }
    pdata = new T[maxsize];
    for (int i = 0; i < maxsize; ++i) {
        pdata[i] = v.pdata[i];
    }
    return *this;
}

template<class T>
void MyVector<T>::resize() {
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

    T *newdata = new T[maxsize];
    for (int i = 0; i < maxsize; ++i) {
        newdata[i] = 0;                  // !!!!
    }
    for (int i = 0; i < size; ++i) {
        newdata[i] = pdata[i];
    }
    delete[] pdata;
    pdata = newdata;
}

/*template<class T>
ostream &operator<<(ostream &out, MyVector<T> &v) {
    out << v.size << " " << v.maxsize << endl;
    for (int i = 0; i < v.size; ++i) {
        out << v.pdata[i] << endl;
    }
    return out;
}*/
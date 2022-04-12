/*ostream &operator<<(ostream &out, MySet &s) {
}*/

template<class T>
bool MySet<T>::operator==(MySet<T> &s) {
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

template<class T>
MySet<T> &MySet<T>::operator+=(MySet<T> &s) {
    *this = *this + s;
    return *this;
}

template<class T>
MySet<T> &MySet<T>::operator-=(MySet<T> &s) {
    *this = *this - s;
    return *this;
}

template<class T>
MySet<T> &MySet<T>::operator*=(MySet &s) {
    *this = *this * s;
    return *this;
}

template<class T>
void MySet<T>::add_element(T el) {
    if (binarySearch(el) == -1) {
        MyVector<T>::add_element(el);
        MyVector<T>::sort();
    }
}

template<class T>
void MySet<T>::delete_element(T el) {
    int ind = binarySearch(el);
    if (ind != -1) {
        MyVector<T>::delete_element(ind);
    }
}

template<class T>
bool MySet<T>::is_element(T el) {
    return (binarySearch(el) != -1);
}

template<class T>
int MySet<T>::binarySearch(T el) {
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
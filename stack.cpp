
template<class INF>
MyStack<INF>::MyStack() : top(NULL) {

}

template<class INF>
MyStack<INF>::~MyStack() {
    while (!this->empty()) {
        this->pop();
    }
}

template<class INF>
bool MyStack<INF>::empty() {
    return (top == NULL);
}

template<class INF>
bool MyStack<INF>::push(INF n) {
    ListNode<INF, MyStack<INF>> *t = top;
    top = new ListNode<INF, MyStack<INF>>;
    top->next = t;

    top->d = n;

    return true;
}

template<class INF>
bool MyStack<INF>::pop() {
    if (this->empty()) {
        return false;
    }

    ListNode<INF, MyStack<INF>> *n = top->next;
    delete top;
    top = n;
    return true;
}

template<class INF>
INF * MyStack<INF>::top_inf() {
    if (this->empty()) {
        return NULL;
    } else {
        return &(top->d);
    }
}

#ifndef LAB_MYSTACK_H
#define LAB_MYSTACK_H

#include <stddef.h>

// #define NULL 0

template<class INF, class FRIEND>
class ListNode                //узел списка
{
private:
    INF d;                        //информационная часть узла
    ListNode *next;         //указатель на следующий узел списка
    ListNode() {
        next = NULL;
    }
    friend FRIEND;
};

template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF> > Node;
    Node *top;
public:
    MyStack();        // конструктор
    ~MyStack();            // освободить динамическую память
    bool empty();        // стек пустой?
    bool push(INF n);        // добавить узел в вершину стека
    bool pop();        // удалить узел из вершины стека
    INF *top_inf();        //считать информацию из вершины стека
};

#endif  // LAB_MYSTACK_H

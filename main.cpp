#include <iostream>
#include "stack.h"

using namespace std;

void Multipliers(int n, MyStack<int> &stack) {
    int n1 = n;
    for(int i = 2; i * i <= n1; i++) {
        while(n % i == 0) {
            n = n / i;
            stack.push(i);
        }
    }
}

template <class T>
void PrintStack(MyStack<T> &stack) {
    while(!stack.empty()) {
        cout << *(stack.top_inf()) << " ";
        stack.pop();
    }
    cout << endl;
}

int main() {
    MyStack<int> st1;
    MyStack<int> stRev;
    Multipliers(3960, st1);

    /*MyStack<int> st2(st1);
    MyStack<int> st3;
    st3 = st1;

    PrintStack(st1);
    PrintStack(st2);
    PrintStack(st3);*/

    cout << "3960 = ";
    while(!st1.empty()) {
        int top = *(st1.top_inf());
        cout << top << " ";
        stRev.push(top);
        st1.pop();
    }
    cout << endl;

    cout << "3960 = ";
    PrintStack(stRev);


    return 0;
}

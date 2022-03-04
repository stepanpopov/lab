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
    MyStack<int> st;
    MyStack<int> stRev;
    Multipliers(3960, st);

    cout << "3960 = ";
    while(!st.empty()) {
        int top = *(st.top_inf());
        cout << top << " ";
        stRev.push(top);
        st.pop();
    }
    cout << endl;

    cout << "3960 = ";
    PrintStack(stRev);


    return 0;
}

#include "MyStack.h"
// #include "MyStack.cpp"
#include <iostream>

using namespace std;

int main() {
    MyStack<int> st;
    st.push(5);
    st.push(6);

    cout << *(st.top_inf());
    st.pop();
    cout << *(st.top_inf());

    return 0;
}

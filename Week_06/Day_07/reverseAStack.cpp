#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(top);

}

void reverseStack(stack<int> &st) {
    if(st.empty())      return;

    int top = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, top);
}

void printStack(stack<int> st) {
    cout << "Stack (top to bottom): ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;

    // Push some elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original stack:\n";
    printStack(st);

    reverseStack(st);

    cout << "Reversed stack:\n";
    printStack(st);

    return 0;
}
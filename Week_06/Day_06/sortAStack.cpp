#include<iostream>
#include<stack>

using namespace std;

void insertInOrder(stack<int> &st, int x)
{
    if(st.empty() || x >= st.top())
    {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    insertInOrder(st, x);   // recurse deeper until we find correct spot

    st.push(top);      // restore the popped elements


}


void sortStack(stack<int> &st) 
{
    if(st.empty())  return;
    
    int top = st.top();
    st.pop();

    sortStack(st);  // recursively sort the rest
    insertInOrder(st, top); // put the element back in correct place
}


int main() 
{
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    sortStack(st);

    cout << "Sorted stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
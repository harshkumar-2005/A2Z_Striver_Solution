#include <iostream>
#include <stack>
using namespace std;

class StackQueue {
private:
    stack<int> inStack, outStack;

    // Move elements only when needed
    void transfer() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    StackQueue() {
    }

    // Push element (enqueue)
    void push(int x) {
        inStack.push(x);
    }

    // Pop element (dequeue)
    int pop() {
        transfer();
        if (outStack.empty()) {
            throw runtime_error("Queue Underflow");
        }
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    // Peek front element
    int peek() {
        transfer();
        if (outStack.empty()) {
            throw runtime_error("Queue is Empty");
        }
        return outStack.top();
    }

    // Check if empty
    bool isEmpty() {
        return inStack.empty() && outStack.empty();
    }
};


int main() {
    StackQueue q;
    q.push(5);       // null
    q.push(10);      // null
    cout << q.peek() << endl;  // 5
    cout << q.pop() << endl;   // 5
    cout << (q.isEmpty() ? "true" : "false") << endl; // false

    StackQueue q2;
    cout << (q2.isEmpty() ? "true" : "false") << endl; // true
}

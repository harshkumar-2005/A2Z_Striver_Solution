#include <iostream>
#include <queue>
using namespace std;

class QueueStack {
private:
    queue<int> q;

public:
    QueueStack() {
    }

    // Push element onto stack
    void push(int x) {
        q.push(x);
        int size = q.size();

        // Rotate the queue so new element is at front
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes and returns top element
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack Underflow");
        }
        int val = q.front();
        q.pop();
        return val;
    }

    // Returns top element
    int top() {
        if (isEmpty()) {
            throw runtime_error("Stack is Empty");
        }
        return q.front();
    }

    // Check if stack is empty
    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    QueueStack stack;

    stack.push(4);     // null
    stack.push(8);     // null
    cout << stack.pop() << endl;    // 8
    cout << stack.top() << endl;    // 4
    cout << (stack.isEmpty() ? "true" : "false") << endl; // false

    QueueStack stack2;
    cout << (stack2.isEmpty() ? "true" : "false") << endl; // true

    return 0;
}

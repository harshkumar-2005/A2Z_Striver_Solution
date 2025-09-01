#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
   private:
    stack<int> s;
    stack<int> minS;

   public:
    MinStack() {}

    void push(int value) {
        s.push(value);
        if (minS.empty() || value <= minS.top()) {
            minS.push(value);
        }
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() == minS.top()) {
            minS.pop();
        }
        s.pop();
    }

    int top() {
        if (!s.empty())
            return s.top();
        throw runtime_error("Stack is empty");
    }

    int getMin() {
        if (!minS.empty())
            return minS.top();
        throw runtime_error("Stack is empty");
    }
};

int main() {
    MinStack ms;

    // Push some values
    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);
    ms.push(8);

    cout << "Top element: " << ms.top() << endl;
    cout << "Current min: " << ms.getMin() << endl;

    ms.pop();
    cout << "After popping, top: " << ms.top() << endl;
    cout << "Current min: " << ms.getMin() << endl;

    ms.pop();  // pops 2
    cout << "After popping 2, top: " << ms.top() << endl;
    cout << "Current min: " << ms.getMin() << endl;

    return 0;
}

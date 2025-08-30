#include <iostream>
using namespace std;

class LinkedListStack {
private:
    // Node definition
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(nullptr) {}
    };

    Node* head;  // top of stack

public:
    LinkedListStack() {
        head = nullptr;
    }

    ~LinkedListStack() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Push element onto stack
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    // Pop element from stack
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack Underflow");
        }
        int val = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return val;
    }

    // Get top element
    int top() {
        if (isEmpty()) {
            throw runtime_error("Stack is Empty");
        }
        return head->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    LinkedListStack stack;

    stack.push(3);       // null
    stack.push(7);       // null
    cout << stack.pop() << endl;    // 7
    cout << stack.top() << endl;    // 3
    cout << (stack.isEmpty() ? "true" : "false") << endl; // false

    LinkedListStack stack2;
    cout << (stack2.isEmpty() ? "true" : "false") << endl; // true
}

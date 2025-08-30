#include<iostream>

using namespace std;

#include <iostream>
using namespace std;

class ArrayStack {
private:
    int* arr;        // dynamic array
    int capacity;    // current capacity of array
    int topIndex;    // index of top element

    // Resize the array when it's full
    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        // copy old elements to new array
        for (int i = 0; i <= topIndex; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;   // free old memory
        arr = newArr;
        capacity = newCapacity;
    }

public:
    ArrayStack(int initialCapacity = 2) {
        capacity = initialCapacity;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~ArrayStack() {
        delete[] arr;
    }
    
    // Push element onto stack
    void push(int x) {
        if (topIndex == capacity - 1) {
            resize(); // grow array when full
        }
        arr[++topIndex] = x;
    }
    
    // Pop element from stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1; // invalid
        }
        return arr[topIndex--];
    }
    
    // Get top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[topIndex];
    }
    
    // Check if stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Display stack contents
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    ArrayStack s;
    s.push(10);
    s.push(20);
    s.push(30); // triggers resize
    s.push(40);
    s.display();

    cout << "Top element: " << s.top() << "\n";
    cout << "Popped: " << s.pop() << "\n";
    s.display();
    
    return 0;
}
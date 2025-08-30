#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int* arr;        // dynamic array
    int capacity;    // size of array
    int front;       // index of front element
    int rear;        // index where next element goes
    int count;       // number of elements

    // Resize array when full
    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        // copy elements in proper order
        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(front + i) % capacity];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        front = 0;
        rear = count;
    }

public:
    ArrayQueue() {
        capacity = 2;
        arr = new int[capacity];
        front = 0;
        rear = 0;
        count = 0;
    }

    ~ArrayQueue() {
        delete[] arr;
    }

    // Enqueue
    void push(int x) {
        if (count == capacity) {
            resize();
        }
        arr[rear] = x;
        rear = (rear + 1) % capacity;
        count++;
    }

    // Dequeue
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Queue Underflow");
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        count--;
        return val;
    }

    // Peek at front
    int peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is Empty");
        }
        return arr[front];
    }

    // Check empty
    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    ArrayQueue q;
    q.push(5);
    q.push(10);
    cout << q.peek() << endl;   // should print 5
    cout << q.pop() << endl;    // should print 5
    cout << (q.isEmpty() ? "true" : "false") << endl; // false
    return 0;
}
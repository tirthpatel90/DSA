// Implementation of stack using Queue
#include <iostream>
#include <queue>
using namespace std;

// Time Complexity: O(n) for push operation, O(1) for pop and top operations
// Space Complexity: O(n) for storing elements in the queue
class Stack {
    queue<int> q; // Create a queue to implement stack operations

    public:
    // Function to push an element onto the stack
    void push(int value) {
        q.push(value); // Enqueue the new value into the queue
        int size = q.size(); // Get the current size of the queue

        // Rotate the queue to make the last added element at the front
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front()); // Move the front element to the back of the queue
            q.pop(); // Remove the front element from the queue
        }
    }

    // Function to pop the top element from the stack
    int pop() {
        if (q.empty()) { // Check for stack underflow
            cout << "Stack Underflow" << endl; // Stack is empty, cannot pop any elements
            return -1;
        }
        int topElement = q.front(); // Get the top element of the stack, which is at the front of the queue
        q.pop(); // Remove the front element from the queue, which is the top of the stack
        return topElement; // Return the popped element
    }

    // Function to get the top element of the stack without removing it
    int top() {
        if (q.empty()) { // Check if the stack is empty
            cout << "Stack is empty" << endl; // Stack is empty, cannot get top element
            return -1;
        }
        return q.front(); // Return the top element of the stack, which is at the front of the queue
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return q.empty(); // Return true if the stack is empty, false otherwise
    }
};

int main() {
    Stack s; // Create a stack object

    s.push(10); // Push elements onto the stack
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // Get the top element of the stack

    cout << "Popped element: " << s.pop() << endl; // Pop an element from the stack
    cout << "Top element after pop: " << s.top() << endl; // Get the new top element after popping
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Check if the stack is empty
    return 0;
}
// Implementation of Queue using Stack
#include <iostream>
#include <stack>
using namespace std;

// Time Complexity: O(n) for enqueue operation, O(1) for dequeue operation
// Space Complexity: O(n) for storing elements in the stacks
class Queue {
    stack<int> s1; // Create two stacks to implement queue operations
    stack<int> s2;

    public:
    // Function to enqueue an element into the queue
    void enqueue(int value) {
        s1.push(value); // Push the new value onto the first stack
    }

    // Function to dequeue an element from the queue
    int dequeue() {
        if (s2.empty()) { // Check if the second stack is empty
            if (s1.empty()) { // Check if the first stack is also empty
                cout << "Queue Underflow" << endl; // Queue is empty, cannot dequeue any elements
                return -1;
            }
            // Move all elements from the first stack to the second stack
            while (!s1.empty()) {
                s2.push(s1.top()); // Push the top element of the first stack onto the second stack
                s1.pop(); // Remove the top element from the first stack
            }
        }
        int frontElement = s2.top(); // Get the front element of the queue, which is at the top of the second stack
        s2.pop(); // Remove the top element from the second stack, which is the front of the queue
        return frontElement; // Return the dequeued element
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty(); // Return true if both stacks are empty, false otherwise
    }
};

int main() {
    Queue q; // Create a queue object

    q.enqueue(10); // Enqueue elements into the queue
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeued element: " << q.dequeue() << endl; // Dequeue an element from the queue
    cout << "Dequeued element: " << q.dequeue() << endl; // Dequeue another element from the queue

    return 0;
}
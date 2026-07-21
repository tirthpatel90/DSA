// Queue Implementation
#include <iostream>
using namespace std;

// Define a Queue class to implement queue operations
class Queue {
private:
    int* arr;
    int start;
    int end;
    int capacity;
public:
    // Constructor to initialize queue
    Queue(int size) {
    capacity = size;
    arr = new int[capacity];
    start = -1;
    end = -1;
}

// Function to add an element to the queue
    void enqueue(int value) {
        if (end == capacity - 1) { // Check for queue overflow
            cout << "Queue Overflow" << endl; // Queue is full, cannot enqueue more elements
            return;
        }
        if (start == -1) { // If the queue is empty, set start to 0
            start = 0;
        }
        arr[++end] = value; // Increment end and add the new value to the queue
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (start == -1 || end == -1 || start > end) { // Check for queue underflow
            cout << "Queue Underflow" << endl; // Queue is empty, cannot dequeue any elements
            return;
        }
        start++; // Increment start to remove the front element from the queue
    }

    // Function to get the front element of the queue without removing it
    int front() {
        if (start == -1 || end == -1 || start > end) { // Check if the queue is empty
            cout << "Queue is empty" << endl; // Queue is empty, cannot get front element
            return -1; // Return -1 to indicate that the queue is empty
        }
        return arr[start]; // Return the front element of the queue
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return start == -1 || end == -1 || start > end; // Return true if the queue is empty, false otherwise
    }
};

// Queue implementation using Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* front = nullptr; // Initialize front pointer to nullptr
Node* rear = nullptr; // Initialize rear pointer to nullptr
int queueSize = 0; // Initialize size of the queue to 0

void enqueue(int value) {
    Node* newNode = new Node(value);
    if (rear == nullptr) { // If the queue is empty
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    queueSize++;
}

void dequeue() {
    if (front == nullptr) { // Check for queue underflow
        cout << "Queue Underflow" << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) { // If the queue becomes empty
        rear = nullptr;
    }
    delete temp;
    queueSize--;
}

int getFront() {
    if (front == nullptr) { // Check if the queue is empty
        cout << "Queue is empty" << endl;
        return -1;
    }
    return front->data; // Return the front element of the queue
}

bool isEmpty() {
    return front == nullptr; // Return true if the queue is empty, false otherwise
}

int main() {
    Queue q(5); // Create a queue of size 5

    q.enqueue(10); // Enqueue elements
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; // Get the front element

    q.dequeue(); // Dequeue an element
    cout << "Front element after dequeue: " << q.front() << endl; // Get the front element after dequeue

    return 0;
}
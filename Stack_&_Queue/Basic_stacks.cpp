// Stack Implementation
#include <iostream>
using namespace std;

// Define a Stack class to implement stack operations
class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
// Constructor to initialize stack
    Stack(int size) { // Initialize the stack with a given size
        capacity = size; // Set the capacity of the stack
        arr = new int[capacity]; // Dynamically allocate memory for the stack array
        top = -1; // Initialize top to -1 to indicate that the stack is empty
    }

    void push(int value) { // Push an element onto the stack
        if (top == capacity - 1) { // Check for stack overflow
            cout << "Stack Overflow" << endl; // Stack is full, cannot push more elements
            return;
        }
        arr[++top] = value; // Increment top and add the new value to the stack
    }

    void pop() { // Remove the top element from the stack
        if (top == -1) { // Check for stack underflow
            cout << "Stack Underflow" << endl; // Stack is empty, cannot pop any elements
            return;
        }
        top--; // Decrement top to remove the top element from the stack
    }

    int peek() { // Return the top element of the stack without removing it
        if (top == -1) { // Check if the stack is empty
            cout << "Stack is empty" << endl; // Stack is empty, cannot peek any elements
            return -1; // Return -1 to indicate that the stack is empty
        }
        return arr[top]; // Return the top element of the stack
    }

    bool isEmpty() { // Check if the stack is empty
        return top == -1; // Return true if the stack is empty, false otherwise
    }
};


// Stack implementation using Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int value) { // Constructor to initialize a node with a given value
        data = value; // Set the data of the node
        next = nullptr; // Initialize next pointer to nullptr
    }
};
Node* top = nullptr; // Initialize top pointer to nullptr
int stackSize = 0; // Initialize size of the stack to 0

void push(int value) { // Push an element onto the stack
    Node* newNode = new Node(value); // Create a new node with the given value
    newNode->next = top; // Set the next pointer of the new node to the current top
    top = newNode; // Update top to point to the new node
    stackSize++; // Increment the size of the stack
}

void pop() { // Remove the top element from the stack
    if (top == nullptr) { // Check for stack underflow
        cout << "Stack Underflow" << endl; // Stack is empty, cannot pop any elements
        return;
    }
    Node* temp = top; // Store the current top node in a temporary variable
    top = top->next; // Update top to point to the next node
    delete temp; // Delete the old top node to free memory
    stackSize--; // Decrement the size of the stack
}

void peek() { // Return the top element of the stack without removing it
    if (top == nullptr) { // Check if the stack is empty
        cout << "Stack is empty" << endl; // Stack is empty, cannot peek any elements
        return;
    }
    cout << "Top element: " << top->data << endl; // Print the top element of the stack
}

void sizeOfStack() { // Return the size of the stack
    cout << "Size of stack: " << stackSize << endl; // Print the size of the stack
}

int main() {
    Stack s(5); // Create a stack of size 5

    s.push(10); // Push elements onto the stack
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl; // Peek at the top element

    s.pop(); // Pop an element from the stack
    cout << "Top element after pop: " << s.peek() << endl; // Peek at the top element after pop

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Check if the stack is empty

    return 0;
}

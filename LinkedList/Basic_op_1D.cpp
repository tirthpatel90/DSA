// Basics operations on a linked list
#include <iostream>
using namespace std;
// construct self defined data type linked list
struct Node {
    int data;
    Node* next;
    Node (int data1, Node* next1) {
        data = data1;
        next = next1;   
    }
};

// Function to create a new node
Node* createNode(int data) {
    return new Node(data, nullptr);
}

//-----------------------------------------------------------------------------------------------
// Delete a node from linked list:
//-----------
// function to delete head node of linked list
Node* deleteHead(Node* head) {
    if (head == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }
    Node* temp = head; // Store the current head node in a temporary variable
    head = head->next; // Move the head pointer to the next node
    delete temp; // Delete the old head node to free memory
    return head; // Return the new head of the list
}
//----------
// function to delete tail node of linked list
Node* deleteTail(Node* head) {
    if (head == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }
    if (head->next == nullptr) {
        delete head; // If there's only one node, delete it and return nullptr
        return nullptr;
    }
    Node* current = head; // Start from the head of the list
    while (current->next->next != nullptr) { // Traverse to the second last node
        current = current->next;
    }
    delete current->next; // Delete the last node
    current->next = nullptr; // Set the next of second last node to nullptr
    return head; // Return the head of the list
}
//-----------
// function to delete a node with a specific position from linked list
Node* deleteAtPosition(Node* head, int position) {
    if (head == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }
    if (position == 0) {
        return deleteHead(head); // If position is 0, delete the head node
    }
    if (position == 1) {
        return deleteTail(head); // If position is 1, delete the tail node
    }
    Node* current = head; // Start from the head of the list
    int cnt = 0; // Initialize a counter to keep track of the current position
    Node* previous = nullptr; // Initialize a pointer to keep track of the previous node

    while (current != nullptr && cnt < position) { // Traverse the list until the desired position is reached or the end of the list is encountered
        cnt++; // Increment the counter
        if (cnt == position) { // If the current position matches the desired position
            previous->next = previous->next->next; // Bypass the current node by linking the previous node to the next node
            delete current; // Delete the current node to free memory
            return head; // Return the head of the list
        }
        previous = current; // Update the previous node
        current = current->next; // Move to the next node
    }
    return head; // Return the head of the list
}    
//-----------
// function to delete a node with a specific value from linked list
Node* deleteByValue(Node* head, int value) {
    if (head == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }
    if (head->data == value) {
        return deleteHead(head); // If the head node contains the value, delete the head node
    }
    Node* current = head; // Start from the head of the list
    Node* previous = nullptr; // Initialize a pointer to keep track of the previous node

    while (current != nullptr) { // Traverse the list until the end is encountered
        if (current->data == value) { // If the current node contains the value
            previous->next = previous->next->next; // Bypass the current node by linking the previous node to the next node
            delete current; // Delete the current node to free memory
            return head; // Return the head of the list
        }
        previous = current; // Update the previous node
        current = current->next; // Move to the next node
    }
    return head; // Return the head of the list if the value was not found
}
//----------------------------------------------------------------------------------------------------

// insert node to linked list
//-----------

// function to insert a node at the head of the linked list
Node* insertAtHead(Node* head, int data) {
    Node* temp = new Node(data, head); // Create a new node with the given data and set its next pointer to the current head
    return temp; // Return the new node as the new head of the list
}
//-----------
// function to insert a node at the tail of the linked list
Node* insertAtTail(Node* head, int data) {
    Node* newNode = new Node(data, nullptr); // Create a new node with the given data and set its next pointer to nullptr
    if (head == nullptr) {
        return newNode; // If the list is empty, return the new node as the head of the list
    }
    Node* temp = head; // Start from the head of the list
    while (temp->next != nullptr) { // Traverse to the last node of the list
        temp = temp->next;
    }
    temp->next = newNode; // Link the last node to the new node
    return head; // Return the head of the list
}
//-------------
// function to insert a node at a specific position in the linked list
Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = new Node(data, nullptr); // Create a new node with the given data and set its next pointer to nullptr
    if (head == nullptr || position == 0) {
        newNode->next = head; // If the list is empty or position is 0, insert the new node at the head
        return newNode; // Return the new node as the new head of the list
    }
    if (position == 1) {
        Node* temp = head; // Store the current head node in a temporary variable
        return temp; // Return the current head of the list
    }
    int cnt = 0; // Initialize a counter to keep track of the current position
    Node* temp = head; // Start from the head of the list
    while (temp != nullptr) { // Traverse the list until the desired position is reached or the end of the list is encountered
        cnt++; // Increment the counter
        if (cnt == position - 1) { // If the current position matches the desired position
            newNode->next = temp->next; // Link the new node to the next node
            temp->next = newNode; // Link the current node to the new node
            return head; // Return the head of the list
        }
        temp = temp->next; // Move to the next node
    } 
    return head; // Return the head of the list
}
//-------------
// function to insert a node with a specific value in the linked list
Node* insertByValue(Node* head, int data, int value) {
    Node* newNode = new Node(data, nullptr); // Create a new node with the given data and set its next pointer to nullptr
    if (head == nullptr) {
        return newNode; // If the list is empty, return the new node as the head of the list
    }
    if (head->data == value) {
        newNode->next = head; // If the head node contains the value, insert the new node at the head
        return newNode; // Return the new node as the new head of the list
    }
    Node* temp = head; // Start from the head of the list
    while (temp->next != nullptr) { // Traverse the list until the end is encountered
        if (temp->next->data == value) { // If the current node contains the value
            newNode->next = temp->next; // Link the new node to the next node
            temp->next = newNode; // Link the current node to the new node
            return head; // Return the head of the list
        }
        temp = temp->next; // Move to the next node
    }
    return head; // Return the head of the list if the value was not found
}
//---------------------------------------------------------------------------------------------------

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Delete the head node
    head = deleteHead(head); // List becomes: 2 -> 3 -> 4

    // Delete the tail node
    head = deleteTail(head); // List becomes: 2 -> 3

    // Delete a node at position 0 (head)
    head = deleteAtPosition(head, 0); // List becomes: 3

    // Delete a node by value
    head = deleteByValue(head, 3); // List becomes empty

    return 0;
}
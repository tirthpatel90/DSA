// Basic Operations on 2D Linked List
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* down;
    Node* back;

    Node(int data, Node* next = nullptr, Node* back = nullptr)
        : data(data), next(next), down(nullptr), back(back) {}
};

class LinkedList2D {
public:
    Node* head;
    LinkedList2D();
    void insert(int data);
    void display();
    void deleteHead2D();
    void deleteTail2D();
    void deleteAtPosition2D(int position);
    void deleteByValue2D(int value);
};

// Constructor to initialize the head of the 2D linked list
LinkedList2D::LinkedList2D() {
    head = nullptr; // Initialize head to nullptr
}

void LinkedList2D::insert(int data) {
    if (head == nullptr) {
        head = new Node(data);
        return;
    }
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    Node* newNode = new Node(data, nullptr, tail);
    tail->next = newNode;
}

void LinkedList2D::display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

void LinkedList2D::deleteHead2D() {
    head = ::deleteHead2D(head);
}

void LinkedList2D::deleteTail2D() {
    head = ::deleteTail2D(head);
}

void LinkedList2D::deleteAtPosition2D(int position) {
    head = ::deleteAtPosition2D(head, position);
}

void LinkedList2D::deleteByValue2D(int value) {
    head = ::deleteByValue2D(head, value);
}

//-------------------------------------------------------------------------------------
// Delete a node from 2D linked list:
//-----------------------------

// function to delete head node of 2D linked list
Node* deleteHead2D(Node* head) {
    if (head == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }
    Node* prev = head; // Store the current head node in a temporary variable
    head = head->next; // Move the head pointer to the next node in the down direction
    
    head->back = nullptr; // Set the back pointer of the new head to nullptr
    prev->next = nullptr; // Set the next pointer of the old head to nullptr

    delete prev; // Delete the old head node to free memory
    return head; // Return the new head of the list
}

// function to delete tail node of 2D linked list
Node* deleteTail2D(Node* head) {
    if (head == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }
    if (head->next == nullptr) {
        delete head; // If there's only one node, delete it and return nullptr
        return nullptr;
    }
    Node* tail = head; // Start from the head of the list
    while (tail->next != nullptr) { // Traverse to the last node in the down direction
        tail = tail->next;
    }
    Node* newTail = tail->back; // Get the second last node
    newTail->next = nullptr; // Set the next pointer of the second last node to nullptr
    tail->back = nullptr; // Set the back pointer of the old tail to nullptr

    delete tail; // Delete the old tail node to free memory
    return head; // Return the head of the list
}

// function to delete a node with a specific position from 2D linked list
Node* deleteAtPosition2D(Node* head, int position) {
    Node* temp = head; // Start from the head of the list
    int cnt = 0; // Initialize a counter to keep track of the current position
    while (temp != nullptr && cnt < position) { // Traverse to the node at the specified position
        cnt++;
        if (cnt == position) break; // If the current position matches the specified position, break the loop
        temp = temp->next; // Move to the next node in the down direction
    }
    Node* prev = temp->back; // Get the previous node in the back direction
    Node* front = temp->next; // Get the next node in the down direction

    if (prev == NULL && front == NULL) { // If the node to be deleted is the only node in the list
        delete temp; // Delete the node
        return nullptr; // Return nullptr as the new head of the list
    }

    else if (prev == NULL) { // If the node to be deleted is the head node
        deleteHead2D(head); // Call the deleteHead2D function to delete the head node
        return head; // Return the new head of the list
    }
    else if (front == NULL) { // If the node to be deleted is the tail node
        deleteTail2D(head); // Call the deleteTail2D function to delete the tail node
        return head; // Return the head of the list
    }

    else { // If the node to be deleted is in the middle of the list
        prev->next = front; // Link the previous node to the next node
        front->back = prev; // Link the next node back to the previous node

        temp->next = nullptr; // Set the next pointer of the node to be deleted to nullptr
        temp->back = nullptr; // Set the back pointer of the node to be deleted to nullptr
        delete temp; // Delete the current node to free memory
        return head; // Return the head of the list
    }
}

// function to delete a node with a specific value from 2D linked list
Node* deleteByValue2D(Node* head, int value) {
    Node* temp = head; // Start from the head of the list
    while (temp != nullptr) { // Traverse the list until the end
        if (temp->data == value) { // If the current node's data matches the specified value
            Node* prev = temp->back; // Get the previous node in the back direction
            Node* front = temp->next; // Get the next node in the down direction

            if (prev == NULL && front == NULL) { // If the node to be deleted is the only node in the list
                delete temp; // Delete the node
                return nullptr; // Return nullptr as the new head of the list
            }

            else if (prev == NULL) { // If the node to be deleted is the head node
                deleteHead2D(head); // Call the deleteHead2D function to delete the head node
                return head; // Return the new head of the list
            }
            else if (front == NULL) { // If the node to be deleted is the tail node
                prev->next = NULL; // Set the next pointer of the previous node to nullptr
                temp->back = nullptr; // Set the back pointer of the node to be deleted to nullptr
                delete temp; // Delete the current node to free memory
                return head; // Return the head of the list
            }

            else { // If the node to be deleted is in the middle of the list
                prev->next = front; // Link the previous node to the next node
                front->back = prev; // Link the next node back to the previous node

                temp->next = nullptr; // Set the next pointer of the node to be deleted to nullptr
                temp->back = nullptr; // Set the back pointer of the node to be deleted to nullptr
                delete temp; // Delete the current node to free memory
                return head; // Return the head of the list
            }
        }
        temp = temp->next; // Move to the next node in the down direction
    }
    return head; // Return head if no matching value was found
}


//--------------------------------------------------------------------------------------------------
// Insert a node in 2D linked list:
//-------------

// function to insert a new node at the head of the 2D linked list
Node* insertAtHead2D(Node* head, int data) {
    Node* newNode = new Node(data, head, nullptr); // Create a new node with the given data and set its next pointer to the current head
    head->back = newNode; // Set the back pointer of the current head to the new node
    return newNode; // Return the new node as the new head of the list
}

// function to insert a new node before the tail of the 2D linked list
Node* insertBeforeTail2D(Node* head, int data) {
    if (head == nullptr) { // If the list is empty, create a new node and return it as the head
        return new Node(data, nullptr, nullptr);
    }
    Node* tail = head; // Start from the head of the list
    while (tail->next != nullptr) { // Traverse to the last node in the down direction
        tail = tail->next;
    }
    Node* prev = tail->back; // Get the second last node
    Node* newNode = new Node(data, tail, nullptr); // Create a new node with the given data and set its next pointer to the current tail
    prev->next = newNode; // Set the next pointer of the second last node to the new node
    tail->back = newNode; // Set the back pointer of the current tail to the new node
    return head; // Return the head of the list
} 

// function to insert a new node at a specific position in the 2D linked list
Node* insertAtPosition2D(Node* head, int data, int position) {
    if (position == 0) { // If the position is 0, insert at the head
        return insertAtHead2D(head, data);
    }
    Node* temp = head; // Start from the head of the list
    int cnt = 0; // Initialize a counter to keep track of the current position
    while (temp != nullptr && cnt < position) { // Traverse to the node at the specified position
        cnt++;
        if (cnt == position) break; // If the current position matches the specified position, break the loop
        temp = temp->next; // Move to the next node in the down direction
    }
    if (temp == nullptr) { // If we reached the end of the list, insert before tail
        return insertBeforeTail2D(head, data);
    }
    Node* prev = temp->back; // Get the previous node in the back direction
    Node* newNode = new Node(data, temp, prev); // Create a new node with the given data and set its next pointer to the current node and back pointer to the previous node
    prev->next = newNode; // Set the next pointer of the previous node to the new node
    temp->back = newNode; // Set the back pointer of the current node to the new node
    return head; // Return the head of the list
}

// function to insert a new node with a specific value in the 2D linked list
Node* insertWithValue2D(Node* head, int data, int value) {
    Node* temp = head; // Start from the head of the list
    while (temp != nullptr) { // Traverse the list until the end
        if (temp->data == value) { // If the current node's data matches the specified value
            Node* prev = temp->back; // Get the previous node in the back direction
            Node* newNode = new Node(data, temp, prev); // Create a new node with the given data and set its next pointer to the current node and back pointer to the previous node
            prev->next = newNode; // Set the next pointer of the previous node to the new node
            temp->back = newNode; // Set the back pointer of the current node to the new node
            return head; // Return the head of the list
        }
        temp = temp->next; // Move to the next node in the down direction
    }
    return head; // Return head if no matching value was found
}

int main() {
    LinkedList2D list; // Create an instance of the LinkedList2D class
    list.insert(1); // Insert nodes into the 2D linked list
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Original 2D Linked List:" << endl;
    list.display(); // Display the original 2D linked list

    // Perform deletion operations
    list.head = deleteHead2D(list.head); // Delete the head node
    cout << "After deleting head:" << endl;
    list.display(); // Display the list after deleting head

    list.deleteTail2D(); // Delete the tail node
    cout << "After deleting tail:" << endl;
    list.display(); // Display the list after deleting tail

    list.head = deleteAtPosition2D(list.head, 1); // Delete a node at position 1
    cout << "After deleting at position 1:" << endl;
    list.display(); // Display the list after deleting at position 1

    list.head = deleteByValue2D(list.head, 3); // Delete a node with value 3
    cout << "After deleting value 3:" << endl;
    list.display(); // Display the list after deleting value 3

    return 0; // Return 0 to indicate successful execution
}

// Reverse a Doubly Linked List
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;  // Data stored in the node
    Node* next;     // Pointer to the next node in the list
    Node* back;     // Pointer to the previous node in the list

    // Constructor with both data, next and back node as parameters
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor with only data as a parameter, sets next and back to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Brute force approach to reverse a doubly linked list
// Time Complexity: O(2n), Space Complexity: O(n)\
// step 1: Traverse the doubly linked list and store the nodes in a stack
// step 2: Pop the nodes from the stack and rearrange the next and back pointers    
Node* bruteforceReverseDoublyLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // If the list is empty or has only one node, return the head as it is
    }

    stack<Node*> st; // Create a stack to store the nodes of the doubly linked list
    Node* temp = head; // Start from the head of the list
    while (temp != nullptr) {
        st.push(temp);
        temp = temp->next;
    }

    Node* temp2 = head; // Start from the head of the list again
    while (temp2 != nullptr) {
        temp2->next = st.top(); // Set the next pointer of the current node to the top node in the stack
        temp2->back = nullptr; // Set the back pointer of the current node to nullptr
        st.pop();
        temp2 = temp2->next;
    }

    return temp2; // Return the new head of the reversed list
}

// Optimized approach to reverse a doubly linked list
// Time Complexity: O(n), Space Complexity: O(1)
// step 1: Traverse the doubly linked list and swap the next and back pointers of each node
Node* optimizedReverseDoublyLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // If the list is empty or has only one node, return the head as it is
    }

    Node* current = head; // Start from the head of the list
    Node* prev = nullptr; // Initialize a previous pointer to nullptr

    while (current != nullptr) {
        prev = current->back; // Store the back pointer of the current node in prev
        current->back = current->next; // Swap the back and next pointers of the current node
        current->next = prev;
        current = current->back; // Move to the next node in the original list (which is now in back)
    }

    if (prev != nullptr) {
        head = prev->back; // Update the head to point to the new head of the reversed list
    }

    return head; // Return the new head of the reversed list
}

int main() {
    Node* head = new Node(1); // Create the head node with data 1
    head->next = new Node(2, nullptr, head); // Create the second node with data 2 and link it to the head
    head->next->next = new Node(3, nullptr, head->next); // Create the third node with data 3 and link it to the second node

    cout << "Original Doubly Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " "; // Print the data of each node in the original list
        temp = temp->next;
    }
    cout << endl;

    head = optimizedReverseDoublyLinkedList(head); // Reverse the doubly linked list using the optimized approach

    cout << "Reversed Doubly Linked List: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " "; // Print the data of each node in the reversed list
        temp = temp->next;
    }
    cout << endl;

    return 0; // Return 0 to indicate successful execution
}
// Reverse a linked list
#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Brute force approach to reverse a linked list
// step 1: Initialize stack to store the nodes of the linked list
// step 2: Traverse the linked list and push each node onto the stack
// step 3: Pop nodes from the stack and update their next pointers to reverse the list  
// Time Complexity: O(n), Space Complexity: O(n)
Node* reverseLinkedList(Node* head) {
    // If the list is empty or has only one element, return the head as it's already reversed.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Initialize a stack to store the nodes of the linked list.
    stack<Node*> st;
    Node* temp = head;

    // Traverse the linked list and push each node onto the stack.
    while (temp != NULL) {
        st.push(temp);
        temp = temp->next;
    }

    // Pop nodes from the stack and update their next pointers to reverse the list.
    Node* newHead = st.top();
    st.pop();
    temp = newHead;

    while (!st.empty()) {
        temp->next = st.top();
        st.pop();
        temp = temp->next;
    }

    // Set the next pointer of the last node to nullptr to mark the end of the reversed list.
    temp->next = nullptr;

    return newHead;
}

// Recursive approach to reverse a linked list
// step 1: If the list is empty or has only one element, return the head
// step 2: Recursively reverse the rest of the list
// step 3: Update the next pointer of the next node to point back to the current node
// step 4: Set the next pointer of the current node to nullptr to mark the end of the reversed list
// Time Complexity: O(n), Space Complexity: O(n) due to recursive call stack
Node* reverseLinkedListRecursive(Node* head) {
    // If the list is empty or has only one element, return the head as it's already reversed.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursively reverse the rest of the list.
    Node* newHead = reverseLinkedListRecursive(head->next);

    // Update the next pointer(front) of the next node to point back to the current node
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

// Optimized approach to reverse a linked list
// step 1: assign next to head->next and prev to NULL
// step 2: traverse the linked list and update the next pointer of each node to point to the previous node
// step 3: update prev to the current node and move to the next node
// Time Complexity: O(n), Space Complexity: O(1)
Node* reverseLinkedListOptimized(Node* head) {
    // If the list is empty or has only one element, return the head as it's already reversed.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = nullptr; // Initialize previous pointer to nullptr
    Node* current = head; // Initialize current pointer to head

    // Traverse the linked list and update the next pointer of each node to point to the previous node.
    while (current != nullptr) {
        Node* nextNode = current->next; // Store the next node
        current->next = prev;           // Reverse the next pointer
        prev = current;                 // Move prev to current
        current = nextNode;             // Move to the next node
    }
    // Return the new head of the reversed linked list, which is the previous pointer.
    return prev;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Reverse the linked list using the optimized approach
    head = reverseLinkedListOptimized(head);

    // Print the reversed linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
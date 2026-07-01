// Find Middle Element of Linked List
#include <bits/stdc++.h>
using namespace std;
class Node {
public:

    // Data stored in the node
    int data;  
    
     // Pointer to the next node in the list
    Node* next;     

    // Constructor with both data
    // and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as
    // a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Brute force approach to find the middle element of a linked list
// Time Complexity: O(n + n/2), Space Complexity: O(1)
// step 1: Traverse the linked list to count the number of nodes
// step 2: Traverse the linked list again to reach the middle node
Node* bruteforceFindMiddle(Node* head) {
    // If the list is empty or has only
    // one element, return the head as
    // it's the middle.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    int count = 0;

    // Count the number of nodes in the linked list.
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Calculate the position of the middle node.
    int mid = count / 2 + 1;
    temp = head;

    // Traverse to the middle node by moving
    // temp to the middle position.
    while (temp != NULL) {
        mid = mid - 1;

        // Check if the middle
        // position is reached.
        if (mid == 0){
            // break out of the loop
            // to return temp
            break;
        }
        // Move temp ahead
        temp = temp->next;
    }

    // Return the middle node.
    return temp;
}

// Optimized approach to find the middle element of a linked list
// Tortoise and Hare Algorithm
// Time Complexity: O(n), Space Complexity: O(1)
// step 1: Initialize two pointers, slow and fast, both pointing to the head of the linked list
// step 2: Move the slow pointer one step at a time and the fast pointer two steps at a time
// step 3: When the fast pointer reaches the end of the list, the slow pointer will be at the middle node
Node* optimizedFindMiddle(Node* head) {
    // If the list is empty or has only
    // one element, return the head as
    // it's the middle.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* slow = head; // Initialize slow pointer to head
    Node* fast = head; // Initialize fast pointer to head

    // Traverse the linked list until the fast pointer reaches the end.
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps
    }

    // Return the middle node, which is pointed to by the slow pointer.
    return slow;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    //head->next->next->next->next->next = new Node(6); // Adding an even number of nodes for testing

    // Find the middle element using the brute force approach
    Node* middleBruteForce = bruteforceFindMiddle(head);
    cout << "Middle element (Brute Force): " << middleBruteForce->data << endl;

    // Find the middle element using the optimized approach
    Node* middleOptimized = optimizedFindMiddle(head);
    cout << "Middle element (Optimized): " << middleOptimized->data << endl;

    return 0;
}
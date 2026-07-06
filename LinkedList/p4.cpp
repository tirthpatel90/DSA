// find starting point of loop in linked list
#include <iostream>
using namespace std;

// Bruteforce same as p3.cpp, but we can use a map to store the nodes and their indices. When we find a node that is already in the map, we can return its index as the starting point of the loop.
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// optimized approach to find the starting point of a loop in a linked list using Floyd's Cycle Detection Algorithm (Tortoise and Hare)
// step 1: Initialize two pointers, slow and fast, both pointing to the head of the linked list
// step 2: Move the slow pointer one step at a time and the fast pointer two steps at a time
// step 3: If there is a loop, the fast pointer will eventually meet the slow pointer. If the fast pointer reaches the end of the list, there is no loop.
// step 4: Once the slow and fast pointers meet, we can find the starting point of the loop by moving one pointer to the head of the linked list and keeping the other pointer at the meeting point. Then, move both pointers one step at a time until they meet again. The meeting point will be the starting point of the loop.
// Time Complexity: O(Len), Space Complexity: O(1)
Node* findLoopStart(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect if there is a loop
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Move slow pointer one step
        fast = fast->next->next;    // Move fast pointer two steps

        // If the slow and fast pointers meet, there is a loop
        if (slow == fast) {
            slow = head; // Move slow pointer to the head of the linked list
            // Step 2: Find the starting point of the loop
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Return the starting point of the loop
        }
    }

    return nullptr; // No loop found
}

int main() {
    // Create a linked list with a loop for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Create a loop

    // Find the starting point of the loop
    Node* loopStart = findLoopStart(head);
    if (loopStart != nullptr) {
        cout << "Loop starts at node with value: " << loopStart->data << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}
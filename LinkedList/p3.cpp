// Detect Loops in a Linked List
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Brute force approach to detect loops in a linked list
// step 1: Traverse the linked list and store the addresses of the nodes in a map or set
// step 2: If we encounter a node that is already in the map or set, it means there is a loop in the linked list
// Time Complexity: O(Len + loop_length), Space Complexity: O(Len)
bool hasLoop(Node* head) {
    unordered_set<Node*> nodeSet;
    Node* temp = head;

    while (temp != nullptr) {
        // If the node is already in the set, there is a loop
        if (nodeSet.find(temp) != nodeSet.end()) {
            return true;
        }
        // Add the node to the set
        nodeSet.insert(temp);
        temp = temp->next;
    }

    // If we reach here, there is no loop in the linked list
    return false;
}

// Optimized approach to detect loops in a linked list using Floyd's Cycle Detection Algorithm (Tortoise and Hare)
// step 1: Initialize two pointers, slow and fast, both pointing to the head of the linked list
// step 2: Move the slow pointer one step at a time and the fast pointer two steps at a time
// step 3: If there is a loop, the fast pointer will eventually meet the slow pointer. If the fast pointer reaches the end of the list, there is no loop.
// Time Complexity: O(Len), Space Complexity: O(1)
bool hasLoopOptimized(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Move slow pointer one step
        fast = fast->next->next;    // Move fast pointer two steps

        // If the slow and fast pointers meet, there is a loop
        if (slow == fast) {
            return true;
        }
    }

    // If we reach here, there is no loop in the linked list
    return false;
}

int main() {
    // Create a linked list with a loop for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Create a loop

    // Test the brute force approach
    if (hasLoop(head)) {
        cout << "Loop detected using brute force approach." << endl;
    } else {
        cout << "No loop detected using brute force approach." << endl;
    }

    // Test the optimized approach
    if (hasLoopOptimized(head)) {
        cout << "Loop detected using optimized approach." << endl;
    } else {
        cout << "No loop detected using optimized approach." << endl;
    }

    return 0;
}
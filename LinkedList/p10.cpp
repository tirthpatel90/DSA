// Reverse Node in K Group
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Step 1: Reverse the linked list in groups of k nodes
// Step 2: If the number of nodes is not a multiple of k, then left-out nodes in the end should remain as it is.    
// Step 3: You may not alter the values in the nodes, only nodes themselves may be changed.
// Step 4: Only constant memory is allowed.
// Step 5: The function should return the new head of the modified linked list.
// Time Complexity: O(2n)
// Space Complexity: O(1)

// Helper function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Helper function to reverse nodes in k group
Node* getKthNode(Node* head, int k) {
    k -= 1;
    while (head && k > 0) {
        k--;
        head = head->next;
    }
    return head;
}

Node* reverseKGroup(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* dummy = new Node(0);
    dummy->next = head;
    Node* groupPrev = dummy;

    while (true) {
        Node* kth = getKthNode(groupPrev->next, k);
        if (!kth) break;

        Node* groupNext = kth->next;
        kth->next = nullptr;

        Node* newGroupHead = reverseList(groupPrev->next);
        groupPrev->next = newGroupHead;

        // Move groupPrev to the end of the reversed group
        while (groupPrev->next) {
            groupPrev = groupPrev->next;
        }
        groupPrev->next = groupNext;
    }

    return dummy->next;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2; // Size of the group to reverse
    head = reverseKGroup(head, k);

    // Print the modified linked list
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
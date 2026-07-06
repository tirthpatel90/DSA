// Remove Nth Node From End of List
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Brute force approach to remove the Nth node from the end of a linked list
// Time Complexity: O(Len) + O(Len - N), Space Complexity: O(1)
// step 1: Traverse the linked list to count the number of nodes   
// step 2: Traverse the linked list again to reach the (Len - N)th node
// step 3: Remove the Nth node from the end by adjusting the next pointer of the (Len - N)th node
Node* removeNthFromEnd(Node* head, int n) {
    // If the list is empty or has only one element, return nullptr
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    int count = 0;

    // Count the number of nodes in the linked list
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    // Calculate the position of the node to remove
    int pos = count - n;

    // If the position is 0, it means we need to remove the head node
    if (pos == 0) {
        Node* newHead = head->next;
        delete head; // Free the memory of the old head
        return newHead;
    }

    temp = head;

    // Traverse to the (Len - N)th node
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }

    // Remove the Nth node from the end by adjusting the next pointer
    Node* nodeToRemove = temp->next;
    temp->next = nodeToRemove->next;
    delete nodeToRemove; // Free the memory of the removed node

    return head;
}

// Optimized approach to remove the Nth node from the end of a linked list
// take two pointers, fast and slow, and move the fast pointer n steps ahead of the slow pointer. Then move both pointers one step at a time until the fast pointer reaches the end of the list. The slow pointer will be pointing to the node just before the Nth node from the end. Adjust the next pointer of the slow pointer to remove the Nth node.
// Time Complexity: O(Len), Space Complexity: O(1)
// step 1: Initialize two pointers, slow and fast, both pointing to the head of the linked list
// step 2: Move the fast pointer n steps ahead of the slow pointer
Node* removeNthFromEndOptimized(Node* head, int n) {
    Node* slow = head;
    Node* fast = head;

    // Move the fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // If fast is nullptr, it means we need to remove the head node
    if (fast == nullptr) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Move both pointers one step at a time until the fast pointer reaches the end
    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    // Remove the Nth node from the end by adjusting the next pointer of the slow pointer
    Node* nodeToRemove = slow->next;
    slow->next = nodeToRemove->next;
    delete nodeToRemove;
    return head;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n = 2; // Remove the 2nd node from the end

    // Remove the Nth node from the end using the optimized approach
    head = removeNthFromEndOptimized(head, n);

    // Print the modified linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free the memory of the linked list
    while (head != nullptr) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }

    return 0;
}
// Rotate a Linked List
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Helper function to find Nth node
Node* findNthNode(Node* temp, int k) {
    int cnt = 1;
    while (temp != nullptr && cnt < k) {
        temp = temp->next;
        cnt++;
    }
    return temp;
}

// Function to rotate the linked list
// Step 1: Find the length of the linked list
// Step 2: If k is greater than the length, take k modulo length
// Step 3: Find the (length - k)th node and make it the new head
Node* rotateLinkedList(Node* head, int k) {
    if (head == nullptr || k == 0) return head;

    Node* tail = head;
    int length = 1;
    while (tail->next != nullptr) {
        tail = tail->next;
        length++;
    }

    if ( k % length == 0) return head;

    k = k % length;
    tail->next = head; // Connect the tail to the head to make it circular

    Node* newLastNode = findNthNode(head, length - k);
    head = newLastNode->next;
    newLastNode->next = nullptr; // Break the circular link
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    head = rotateLinkedList(head, k);

    // Print the rotated linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}

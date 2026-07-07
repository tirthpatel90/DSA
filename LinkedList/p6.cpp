// Segregate even and odd nodes of a linked list
#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Brute force approach: Create arrays for even and odd nodes, and then merge them. This approach uses extra space for the arrays.
// Time Complexity: O(n), Space Complexity: O(n)
// step 1: Traverse the linked list and store even and odd nodes in separate arrays
// step 2: Create two new linked lists from the arrays and merge them
// step 3: Return the head of the merged linked list
Node* segregateEvenOdd(Node* head) {
    if (head == nullptr) return nullptr;

    std::array<int, 1000> a; // Assuming a maximum of 1000 nodes
    int i = 0;
    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        a[i++] = temp->data;
        temp = temp->next->next;
    }
    if(temp) a[i++] = temp->data;

    temp = head->next;
    while (temp != nullptr && temp->next != nullptr) {
        a[i++] = temp->data;
        temp = temp->next->next;
    }
    if(temp) a[i++] = temp->data;

    i = 0;
    temp = head;
    while (temp != nullptr) {
        temp->data = a[i++];
        temp = temp->next;
    }
    return head;
}

// Optimized approach: Rearrange the nodes in place without using extra space. This approach maintains the relative order of even and odd nodes.
// Time Complexity: O(n), Space Complexity: O(1)
// step 1: Initialize two pointers, one for even nodes and one for odd nodes
// step 2: Traverse the linked list and rearrange the nodes such that all even nodes come before odd nodes while maintaining their relative order
Node* segregateEvenOddOptimized(Node* head) {
    if (head == nullptr) return nullptr;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even; // Store the head of even nodes

    while (even != nullptr && even->next != nullptr) {
        odd->next = odd->next->next; // Link odd nodes
        even->next = even->next->next; // Link even nodes

        odd = odd->next; // Move odd pointer
        even = even->next; // Move even pointer
    }
    odd->next = evenHead; // Link the last odd node to the first even node
    return head; // Return the head of the rearranged linked list
}

int main() {
    // Create a linked list for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Segregate even and odd nodes
    head = segregateEvenOddOptimized(head);

    // Print the rearranged linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
// Delete Middle Node in Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Brute force approach to delete a middle node in a linked list
// step 1: Find the length of the linked list
// step 2: Find the middle node by n/2
// step 3: Delete the middle node by changing the next pointer of the previous node to the next node of the middle node
// time complexity: O(n + n/2), space complexity: O(1)
Node* deleteMiddleBruteforce(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; // If the list is empty or has only one node, return nullptr
    }

    // Step 1: Find the length of the linked list
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    // Step 2: Find the middle node by n/2
    int middle = length / 2;
    temp = head;

    while (temp != nullptr) {
        middle--;
        if (middle == 0) {
            // Step 3: Delete the middle node by changing the next pointer of the previous node to the next node of the middle node
            Node* middleNode = temp->next;
            temp->next = temp->next->next; // Change the next pointer of the previous node
            delete middleNode; // Delete the middle node to free memory
            break;
        }
        temp = temp->next;
    }
    return head; // Return the head of the list
}

// Optimized approach to delete a middle node in a linked list
// step 1: Use two pointers, slow and fast, to find the middle node
// step 2: start fast pointer before the head and slow pointer at the head
// step 3: Move the fast pointer two steps and the slow pointer one step at a time until the fast pointer reaches the end of the list
// step 4: The slow pointer will be at the previous node of the middle node, delete the middle node by changing the next pointer of the previous node to the next node of the middle node
// step 5: Return the head of the list
// time complexity: O(n), space complexity: O(1)
Node* deleteMiddleOptimized(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; // If the list is empty or has only one node, return nullptr
    }

    Node* slow = head; // Initialize slow pointer at the head
    Node* fast = head; // Initialize fast pointer at the head
    fast = fast->next->next; // Move fast pointer two steps ahead

    while (fast != nullptr && fast->next != nullptr) { // Traverse the list until the fast pointer reaches the end
        slow = slow->next; // Move slow pointer one step ahead
        fast = fast->next->next; // Move fast pointer two steps ahead
    }
    Node* middleNode = slow->next; // The slow pointer is at the previous node of the middle node
    slow->next = slow->next->next; // Change the next pointer of the previous node to the next node of the middle node
    delete middleNode; // Delete the middle node to free memory
    return head; // Return the head of the list
}

int main() {
    Node* head = new Node(1, nullptr);
    head->next = new Node(2, nullptr);
    head->next->next = new Node(3, nullptr);
    head->next->next->next = new Node(4, nullptr);
    head->next->next->next->next = new Node(5, nullptr);

    cout << "Original List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = deleteMiddleBruteforce(head); // Delete middle node using brute force approach

    cout << "List after deleting middle node (Brute Force): ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Recreate the list for optimized approach
    head = new Node(1, nullptr);
    head->next = new Node(2, nullptr);
    head->next->next = new Node(3, nullptr);
    head->next->next->next = new Node(4, nullptr);
    head->next->next->next->next = new Node(5, nullptr);

    head = deleteMiddleOptimized(head); // Delete middle node using optimized approach

    cout << "List after deleting middle node (Optimized): ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}

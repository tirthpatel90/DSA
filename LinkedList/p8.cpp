// Merge Two Sorted Linked Lists
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

// Brute force approach to merge two sorted linked lists
// step 1: Create a new linked list to store the merged result
// step 2: Traverse both linked lists and compare the data of the nodes
// step 3: Add the smaller node to the array 
// step 4: sort the array and create a new linked list from the sorted array
// time complexity: O(n + m + (n + m)log(n + m)),
// space complexity: O(n + m)
Node* mergeTwoSortedListsBruteforce(Node* head1, Node* head2) {
    if (head1 == nullptr) return head2; // If the first list is empty, return the second list
    if (head2 == nullptr) return head1; // If the second list is empty, return the first list

    // Step 1: Create a new linked list to store the merged result
    Node* mergedHead = nullptr;
    Node* mergedTail = nullptr;

    // Step 2: Traverse both linked lists and compare the data of the nodes
    while (head1 != nullptr && head2 != nullptr) {
        Node* newNode = nullptr;
        if (head1->data < head2->data) {
            newNode = new Node(head1->data, nullptr);
            head1 = head1->next;
        } else {
            newNode = new Node(head2->data, nullptr);
            head2 = head2->next;
        }

        // Step 3: Add the smaller node to the merged linked list
        if (mergedHead == nullptr) {
            mergedHead = newNode;
            mergedTail = newNode;
        } else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
    }

    // Add remaining nodes from either list
    while (head1 != nullptr) {
        Node* newNode = new Node(head1->data, nullptr);
        if (mergedHead == nullptr) {
            mergedHead = newNode;
            mergedTail = newNode;
        } else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
        head1 = head1->next;
    }

    while (head2 != nullptr) {
        Node* newNode = new Node(head2->data, nullptr);
        if (mergedHead == nullptr) {
            mergedHead = newNode;
            mergedTail = newNode;
        } else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
        head2 = head2->next;
    }

    return mergedHead; // Return the head of the merged linked list
}

// Optimized approach to merge two sorted linked lists
// step 1: Use two pointers to traverse both linked lists
// step 2: use a dummy node to simplify the merging process
// step 3: Compare the data of the nodes and add the smaller node to the merged list
// step 4: Move the pointer of the list from which the node was added
// step 5: After traversing both lists, add the remaining nodes from either list to the merged list
// time complexity: O(n + m)
// space complexity: O(1)
Node* mergeTwoSortedListsOptimized(Node* head1, Node* head2) {
    Node* t1 = head1; // Pointer for the first linked list
    Node* t2 = head2; // Pointer for the second linked list
    Node* dummy = new Node(-1, nullptr); // Dummy node to simplify the merging process
    Node* temp = dummy; // Pointer to build the merged linked list

    while (t1 != nullptr && t2 != nullptr) {
        if (t1->data < t2->data) {
            temp->next = t1; // Add the smaller node to the merged list
            temp = t1; // Move the temp pointer
            t1 = t1->next; // Move the pointer of the first list
        } else {
            temp->next = t2; // Add the smaller node to the merged list
            temp = t2; // Move the temp pointer
            t2 = t2->next; // Move the pointer of the second list
        }
    }

    // Add remaining nodes from either list
    if (t1 != nullptr) {
        temp->next = t1; // Add remaining nodes from the first list
    } else {
        temp->next = t2; // Add remaining nodes from the second list
    }

    Node* mergedHead = dummy->next; // Get the head of the merged list
    delete dummy; // Delete the dummy node
    return mergedHead; // Return the head of the merged linked list
}

int main() {
    // Create two sorted linked lists for testing
    Node* head1 = new Node(1, new Node(3, new Node(5, nullptr)));
    Node* head2 = new Node(2, new Node(4, new Node(6, nullptr)));

    // Merge the two sorted linked lists using the optimized approach
    Node* mergedHead = mergeTwoSortedListsOptimized(head1, head2);

    // Print the merged linked list
    Node* temp = mergedHead;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free memory (not shown for brevity)
    return 0;
}
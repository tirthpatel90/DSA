// Sort a linked list
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;   
    }
};

// Brute force approach to sort a linked list
// step 1: Traverse the linked list and store the data in an array
// step 2: Sort the array
// step 3: Traverse the linked list again and update the data of the nodes with the sorted values from the array
// time complexity: O(2n + nlogn)
// space complexity: O(n)
Node* sortLinkedListBruteforce(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // If the list is empty or has only one node, return the head
    }

    // Step 1: Traverse the linked list and store the data in an array
    vector<int> arr;
    Node* temp = head;
    while (temp != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    // Step 2: Sort the array
    sort(arr.begin(), arr.end());

    // Step 3: Traverse the linked list again and update the data of the nodes with the sorted values from the array
    temp = head;
    for (int i = 0; i < arr.size(); i++) {
        temp->data = arr[i];
        temp = temp->next;
    }

    return head; // Return the head of the sorted linked list
}

// Helper function to find the middle node
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // Return the middle node
}

// Helper function to merge two sorted linked lists
Node* mergeTwoSortedLists(Node* head1, Node* head2) {
    if (head1 == nullptr) return head2; // If the first list is empty, return the second list
    if (head2 == nullptr) return head1; // If the second list is empty, return the first list

    Node* dummy = new Node(-1, nullptr); // Create a dummy node to simplify the merging process 
    Node* temp = dummy; // Pointer to build the merged linked list

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            temp->next = head1; // Add the smaller node to the merged list
            head1 = head1->next; // Move the pointer of the first list
        } else {
            temp->next = head2; // Add the smaller node to the merged list
            head2 = head2->next; // Move the pointer of the second list
        }
        temp = temp->next; // Move the temp pointer
    }
    // Add remaining nodes from either list
    if (head1 != nullptr) {
        temp->next = head1; // Add remaining nodes from the first list
    } else {
        temp->next = head2; // Add remaining nodes from the second list
    }
    return dummy->next; // Return the head of the merged linked list
}

// Optimized approach to sort a linked list using merge sort
// step 1: Find the middle node of the linked list using the slow and fast pointer technique
// step 2: Recursively sort the left and right halves of the linked list
// step 3: Merge the two sorted halves of the linked list
// time complexity: O(nlogn)
// space complexity: O(logn) due to recursive stack space
Node* sortLinkedListOptimized(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // If the list is empty or has only one node, return the head
    }

    Node* middle = findMiddle(head); // Find the middle node
    Node* nextToMiddle = middle->next; // Get the next node after the middle
    middle->next = nullptr; // Split the linked list into two halves

    Node* left = sortLinkedListOptimized(head); // Recursively sort the left half
    Node* right = sortLinkedListOptimized(nextToMiddle); // Recursively sort the right half

    return mergeTwoSortedLists(left, right); // Merge the two sorted halves
}

int main() {
    // Create a linked list for testing
    Node* head = new Node(5, new Node(2, new Node(8, new Node(1, new Node(9, nullptr)))));

    // Display the original list
    cout << "Original list: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Sort the list using merge sort
    head = sortLinkedListOptimized(head);

    // Display the sorted list
    cout << "Sorted list: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
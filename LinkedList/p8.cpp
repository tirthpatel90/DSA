// Sort a Linked List
#include <iostream>
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
// step 1: convert the linked list to an array
// step 2: sort the array using any sorting algorithm
// step 3: convert the sorted array back to a linked list
// time complexity: O(2n + nlogn), cause we are traversing the linked list twice and sorting the array
// space complexity: O(n) cause we are using an array to store the elements of the linked list
Node* sortLinkedListBruteforce(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // If the list is empty or has only one node, return the head
    }

    // Step 1: Convert the linked list to an array
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    int* arr = new int[length];
    temp = head;
    for (int i = 0; i < length; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    // Step 2: Sort the array using any sorting algorithm (using std::sort here)
    sort(arr, arr + length);

    // Step 3: Convert the sorted array back to a linked list
    temp = head;
    for (int i = 0; i < length; i++) {
        temp->data = arr[i];
        temp = temp->next;
    }

    delete[] arr; // Free the allocated memory for the array
    return head; // Return the head of the sorted list
}


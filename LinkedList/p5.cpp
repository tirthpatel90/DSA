// Check if given linked list is palindrome or not
#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Reverses the linked list and returns the new head of the reversed list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move to the next node
    }

    return prev; // New head of the reversed list
}


// Brute force approach: Store the elements of the linked list in a stack and then compare the elements from the stack with the elements of the linked list. If all elements match, then the linked list is a palindrome.
// Time Complexity: O(n), Space Complexity: O(n)
// step 1: Create a stack to store the elements of the linked list
// step 2: Traverse the linked list and push each element onto the stack
// step 3: Traverse the linked list again and compare each element with the top of the stack
// step 4: If all elements match, then the linked list is a palindrome

bool isPalindrome(Node* head) {
    stack<int> s;
    Node* temp = head;

    while (temp != nullptr) {
        s.push(temp->data); // Push the data onto the stack
        temp = temp->next;  // Move to the next node
    }

    temp = head; // Reset temp to the head of the linked list
    while (temp != nullptr) {
        if (temp->data != s.top()) { // Compare the data with the top of the stack
            return false; // If they don't match, it's not a palindrome
        }
        s.pop(); // Pop the element from the stack
        temp = temp->next; // Move to the next node
    }

    return true; // If all elements match, it's a palindrome
}

// Optimized approach: Reverse the second half of the linked list and compare it with the first half. If they match, then the linked list is a palindrome.
// Time Complexity: O(n), Space Complexity: O(1)
// step 1: Find the middle of the linked list using the slow and fast pointer technique
// step 2: Reverse the second half of the linked list
// step 3: Compare the first half with the reversed second half
// step 4: Restore the original linked list

bool isPalindromeOptimized(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // A linked list with 0 or 1 node is a palindrome
    }

    Node* slow = head;
    Node* fast = head;

    // Step 1: Find the middle of the linked list
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;       // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps
    }

    Node* secondHalfStart = reverseList(slow->next); // Step 2: Reverse the second half of the linked list
    Node* firstHalfStart = head;

    while (secondHalfStart != nullptr) { // Step 3: Compare the first half with the reversed second half
        if (firstHalfStart->data != secondHalfStart->data) {
            return false; // If they don't match, it's not a palindrome
        }
        firstHalfStart = firstHalfStart->next; // Move to the next node in the first half
        secondHalfStart = secondHalfStart->next; // Move to the next node in the second half
    }
    reverseList(slow->next); // Step 4: Restore the original linked list
    return true; // If all elements match, it's a palindrome
}

int main() {
    // Create a linked list for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Check if the linked list is a palindrome using the brute force approach
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome (Brute Force)." << endl;
    } else {
        cout << "The linked list is not a palindrome (Brute Force)." << endl;
    }

    // Check if the linked list is a palindrome using the optimized approach
    if (isPalindromeOptimized(head)) {
        cout << "The linked list is a palindrome (Optimized)." << endl;
    } else {
        cout << "The linked list is not a palindrome (Optimized)." << endl;
    }

    return 0;
}

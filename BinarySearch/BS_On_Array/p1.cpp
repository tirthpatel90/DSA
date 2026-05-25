// Search X in a sorted array
#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search
// Approach: Iterative binary search (better approach)
// Time Complexity: O(log N)
// Space Complexity: O(1)
// Steps:
// 1) Keep two pointers left and right for current search range.
// 2) Compute mid index.
// 3) If arr[mid] == target, return mid.
// 4) If arr[mid] < target, move left to mid + 1.
// 5) Else move right to mid - 1.
// 6) If loop ends, target does not exist, return -1.
int binarySearch(const vector<int>& arr, int target) {
    // Step 1: Initialize full search range
    int left = 0;
    int right = arr.size() - 1;

    // Step 2-5: Narrow the range until target is found or range becomes invalid
    while (left <= right) {
        // Step 2: Find middle index (overflow-safe)
        int mid = left + (right - left) / 2;

        // Step 3: Mid element is target
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            // Step 4: Target is on right side
            left = mid + 1;
        } else {
            // Step 5: Target is on left side
            right = mid - 1;
        }
    }

    // Step 6: Target not present in array
    return -1;
}

// Use recursion to perform binary search
// Approach: Recursive binary search (better approach)
// Time Complexity: O(log N)
// Space Complexity: O(log N) due to recursion stack
// Steps:
// 1) Base case: if left > right, target is not present.
// 2) Compute mid index.
// 3) If arr[mid] == target, return mid.
// 4) If arr[mid] < target, search right half recursively.
// 5) Else search left half recursively.
int binarySearchRecursive(const vector<int>& arr, int target, int left, int right) {
    // Step 1: Base case for invalid range
    if (left > right) {
        return -1;
    }

    // Step 2: Compute middle index
    int mid = left + (right - left) / 2;

    // Step 3: Target found at mid
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        // Step 4: Recur on right half
        return binarySearchRecursive(arr, target, mid + 1, right);
    } else {
        // Step 5: Recur on left half
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
}

int main() {
    // Sample sorted input array and target value
    vector<int> arr = {5, 10, 15, 20, 25, 30};
    int target = 5;

    // --- BETTER APPROACH 1: ITERATIVE BINARY SEARCH ---
    // Run this block to test iterative binary search.
    int resultIterative = binarySearch(arr, target);
    if (resultIterative != -1) {
        cout << "Element found at index (iterative): " << resultIterative << endl;
    } else {
        cout << "Element not found (iterative)." << endl;
    }

    // --- BETTER APPROACH 2: RECURSIVE BINARY SEARCH ---
    // Run this block to test recursive binary search.
    int resultRecursive = binarySearchRecursive(arr, target, 0, arr.size() - 1);
    if (resultRecursive != -1) {
        cout << "Element found at index (recursive): " << resultRecursive << endl;
    } else {
        cout << "Element not found (recursive)." << endl;
    }

    return 0;
}
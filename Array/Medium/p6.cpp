//Rearrange elements by sign
//Problem Statement: There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.
//Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(N) + O(N/2) - traverse twice (separate + merge)
// Space Complexity: O(N) - extra space for two separate arrays
// Steps:
// 1) Create two separate vectors: one for positive, one for negative numbers.
// 2) Traverse the array and separate positive numbers into one vector and negative into another.
// 3) Merge back into original array in alternating order (positive at even, negative at odd).
void rearrangeBySignBrute(int arr[], int n) {
    // 1) Create vectors to store positive and negative numbers separately
    vector<int> positive;
    vector<int> negative;

    // 2) Separate positive and negative numbers while preserving order
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positive.push_back(arr[i]); // add to positive vector
        } else {
            negative.push_back(arr[i]); // add to negative vector
        }
    }

    // 3) Merge back into original array alternating positive and negative
    int posIndex = 0, negIndex = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { // 3a) even index: place positive number
            arr[i] = positive[posIndex++];
        } else { // 3b) odd index: place negative number
            arr[i] = negative[negIndex++];
        }
    }
}


// Better Approach
// Time Complexity: O(N) - single pass through array
// Space Complexity: O(N) - extra temporary array
// Steps:
// 1) Create a temporary array to hold rearranged elements.
// 2) Use two pointers: one for even indices (positives), one for odd indices (negatives).
// 3) Traverse original array and place each element at its correct position in temp array.
// 4) Copy the rearranged temp array back to original array.
void rearrangeBySignBetter(int arr[], int n) {
    // 1) Create temporary array to hold rearranged elements
    int ans[n]; // Temporary array to hold rearranged elements
    int posIndex = 0; // pointer for next positive position (even indices)
    int negIndex = 1; // pointer for next negative position (odd indices)

    // 3) Traverse original array and place elements at correct positions
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            ans[posIndex] = arr[i]; // place positive at even index
            posIndex += 2; // 3a) move to next even index (next position for positive)
        } else {
            ans[negIndex] = arr[i]; // place negative at odd index
            negIndex += 2; // 3b) move to next odd index (next position for negative)
        }
    }

    // 4) Copy rearranged elements back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}


// Optimal Approach (In-place using two pointers)
// Time Complexity: O(N) - single pass with two pointers
// Space Complexity: O(1) - no extra space (in-place)
// Steps:
// 1) Initialize two pointers: posIndex at 0 (even), negIndex at 1 (odd).
// 2) Scan array: if element at posIndex is negative or element at negIndex is positive, it's misplaced.
// 3) When both positions are wrong (positive at odd, negative at even), swap them.
// 4) Continue until all elements are correctly placed.
void rearrangeBySignOptimal(int arr[], int n) {
    // 1) Initialize pointers: even index for positives, odd index for negatives
    int posIndex = 0; // next position for a positive number
    int negIndex = 1; // next position for a negative number

    // 2-4) Scan and swap misplaced elements
    while (posIndex < n && negIndex < n) {
        // 2a) if current positive position already has positive, move to next even position
        if (arr[posIndex] > 0) {
            posIndex += 2;
        }
        // 2b) if current negative position already has negative, move to next odd position
        else if (arr[negIndex] < 0) {
            negIndex += 2;
        }
        // 3) both positions are wrong: positive at odd, negative at even -> swap them
        else {
            swap(arr[posIndex], arr[negIndex]);
            posIndex += 2; // move to next even position
            negIndex += 2; // move to next odd position
        }
    }
}

int main() {
    // Test array: {1, 2, -3, -4, -5, 6}
    // Expected output: {1, -3, 2, -4, 6, -5} or similar alternating arrangement
    int arr[] = {1, 2, -3, -4, -5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Uncomment one of the following to test each approach:
    
    // rearrangeBySignBrute(arr, n);      // Brute: O(N) time, O(N) space, uses two separate arrays
    // rearrangeBySignBetter(arr, n);     // Better: O(N) time, O(N) space, uses one temp array
    rearrangeBySignOptimal(arr, n);    // Optimal: O(N) time, O(1) space, in-place arrangement

    // Print the rearranged array
    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
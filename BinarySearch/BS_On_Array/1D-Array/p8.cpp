// Search element in rotated sorted array (Unique elements, no duplicates)
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach: linear scan of the array.
// Time complexity: O(N)
// Space complexity: O(1)
// Steps:
// 1) Iterate through all elements from left to right.
// 2) For each element, compare it with `target`.
// 3) If equal, update the result according to this implementation's contract.
// NOTE: This brute implementation returns the *count* of occurrences (not an index).
// The binary-search implementation below returns an index; keep this in mind when
// comparing results — they use different return semantics.
int SearchElementBruteForce(const vector<int>& arr, int target) {
    int count = 0;
    // Step 1-2: Linear scan and comparison
    for (int num : arr) {
        if (num == target) {
            // Step 3: Increment count for each matching element
            ++count;
        }
    }
    // Return the total count of occurrences (or 0 if absent)
    return count;
}

// Optimal approach: Use binary search
// Time complexity: O(log N) 
// Space complexity: O(1)

int SearchElementBinarySearch(const vector<int>& arr, int target) {
    // Step 1: Initialize pointers to the full range
    int low = 0, high = arr.size() - 1;

    // Step 2: Iteratively narrow the search range
    while (low <= high) {
        // Step 2a: Compute middle index (overflow-safe)
        int mid = low + (high - low) / 2;

        // Step 2b: Check if middle element is the target
        if (arr[mid] == target) {
            return mid; // Found — return the index immediately
        }

        // Step 2c: Determine which half is sorted
        // If left half [low..mid] is sorted
        if (arr[low] <= arr[mid]) {
            // Step 2d: If target lies within the sorted left half, search there
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1; // Narrow to left half
            } else {
                // Otherwise, target must be in right half
                low = mid + 1;
            }
        } else {
            // Otherwise, right half [mid..high] is sorted
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1; // Narrow to right half
            } else {
                high = mid - 1; // Search left half
            }
        }
    }

    // Step 3: Not found — return -1 as an index sentinel
    return -1;
}

int main() {
    vector<int> arr = {3, 1, 2, 4, 5}; // Example of a rotated sorted array
    int target = 4;

    // --- RUN OPTIONS ---
    // Brute-force option (linear scan): returns the count of occurrences
    //    int count = SearchElementBruteForce(arr, target);
    //    cout << "Count of target occurrences (brute): " << count << endl;
    // Binary-search option (rotated-array search): returns the index of one matching
    // element or -1 when absent. Use this when you need the index in a rotated
    // sorted array with unique elements.

    // By default we run the binary-search index lookup here:
    int index = SearchElementBinarySearch(arr, target);
    cout << "Target index: " << index << endl;

    return 0;
}
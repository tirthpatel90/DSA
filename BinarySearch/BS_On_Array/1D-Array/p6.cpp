// First and Last occurrence of an element in a sorted array
// Given a sorted array of N integers and an integer x, find the first and last occurrence of x in the array. If x is not present, return -1 for both first and last occurrences.
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach: scan the array from left to right to find first occurrence and from right to left to find last occurrence.
// Time complexity: O(N) for each occurrence, total O(2N)
// Space complexity: O(1)
// Steps:
// 1) Initialize `first` and `last` to -1 to indicate "not found" by default.
// 2) Scan left-to-right: the first index where arr[i] == x is the first occurrence.
// 3) Scan right-to-left: the first index encountered where arr[i] == x is the last occurrence.
// 4) Break early when each occurrence is found to avoid unnecessary work.
// 5) Return the pair (first, last). If x is absent, both will be -1.
pair<int, int> findFirstAndLastOccurrenceBruteForce(const vector<int>& arr, int x) {
    int first = -1;
    int last = -1;

    // Step 2: Find first occurrence by scanning from left to right
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == x) {
            first = i; // Found first occurrence
            break; // No need to continue for first occurrence
        }
    }

    // Step 3: Find last occurrence by scanning from right to left
    for (int i = arr.size() - 1; i >= 0; --i) {
        if (arr[i] == x) {
            last = i; // Found last occurrence
            break; // No need to continue for last occurrence
        }
    }

    // Step 4: Return the pair of indices for first and last occurrences
    return {first, last};
}

// Optimal approach: Use binary search to find the first and last occurrences efficiently.
// Time complexity: O(log N) for each occurrence, total O(2 log N)
// Space complexity: O(1)
// Steps:
// 1) Binary search for the leftmost index where arr[mid] == x (first occurrence):
//    - When arr[mid] == x, record mid as a candidate and continue searching left (high = mid - 1)
//      to find an earlier occurrence.
//    - If arr[mid] < x, move right (low = mid + 1).
//    - If arr[mid] > x, move left (high = mid - 1).
// 2) Binary search for the rightmost index where arr[mid] == x (last occurrence):
//    - When arr[mid] == x, record mid as a candidate and continue searching right (low = mid + 1)
//      to find a later occurrence.
//    - If arr[mid] < x, move right (low = mid + 1).
//    - If arr[mid] > x, move left (high = mid - 1).
// 3) Each search runs in O(log N). If x is absent, recorded indices remain -1.
// 4) Return the pair (first, last).
pair<int, int> findFirstAndLastOccurrenceBinarySearch(const vector<int>& arr, int x) {
    int first = -1;
    int last = -1;

    // Step 1: Binary search for first occurrence
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            first = mid; // Potential first occurrence found
            high = mid - 1; // Continue searching in left half
        } else if (arr[mid] < x) {
            low = mid + 1; // Search in right half
        } else {
            high = mid - 1; // Search in left half
        }
    }

    // Step 2: Binary search for last occurrence
    low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            last = mid; // Potential last occurrence found
            low = mid + 1; // Continue searching in right half
        } else if (arr[mid] < x) {
            low = mid + 1; // Search in right half
        } else {
            high = mid - 1; // Search in left half
        }
    }

    // Step 3: Return the pair of indices for first and last occurrences
    return {first, last};
}

int main() {
    // Sample sorted array and target value
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5};
    int x = 4;

    // --- RUN OPTIONS ---
    // By default this main runs the *binary search* (better) approach.
    // If you want to run the brute-force variant instead, replace the call below with:
    //    auto result = findFirstAndLastOccurrenceBruteForce(arr, x);
    // Both functions return a `pair<int,int>` with (firstIndex, lastIndex) or (-1,-1) if absent.

    // Find first and last occurrences using binary search approach (O(log N) each)
    pair<int, int> result = findFirstAndLastOccurrenceBinarySearch(arr, x);

    // Print the results (indices)
    cout << "First occurrence of " << x << ": " << result.first << endl;
    cout << "Last occurrence of " << x << ": " << result.second << endl;

    return 0;
}
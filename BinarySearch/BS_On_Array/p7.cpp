// Count Occurrences in Sorted Array
// Given a sorted array of integers, find the number of occurrences of a given target value.
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach: scan the array and count occurrences of the target value.
// Time complexity: O(N)
// Space complexity: O(1)
// Steps:
// 1) Initialize a counter to 0.
// 2) Iterate through each element in the array.
// 3) If the current element equals the target, increment the counter.
// 4) After the loop, return the counter value.
int countOccurrencesBruteForce(const vector<int>& arr, int target) {
    int count = 0;
    for (int num : arr) {
        if (num == target) {
            ++count; // Increment count for each occurrence
        }
    }
    return count; // Return the total count of occurrences
}

// Optimal approach: Use binary search to find the first and last occurrences of the target value, then calculate the count.
// Time complexity: O(log N) for each occurrence, total O(2 log N)
// Space complexity: O(1)
// Steps:
// 1) Use binary search to find the leftmost (first) index where arr[i] == target.
// 2) Use binary search to find the rightmost (last) index where arr[i] == target.
// 3) If first == -1, target is absent -> return 0.
// 4) Otherwise count = last - first + 1.
int countOccurrencesBinarySearch(const vector<int>& arr, int target) {
    // Helper function to find the first occurrence of target using binary search
    auto findFirstOccurrence = [&](const vector<int>& arr, int target) -> int {
        // Step 1: initialize search range
        int low = 0, high = arr.size() - 1;
        int first = -1; // Initialize to -1 to indicate "not found"
        // Step 2: binary search loop to find leftmost occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                // Candidate for first occurrence found; move left to find earlier one
                first = mid;
                high = mid - 1; // Continue searching in the left half
            } else if (arr[mid] < target) {
                // Target lies to the right
                low = mid + 1;
            } else {
                // Target lies to the left
                high = mid - 1;
            }
        }
        // Step 3: return the leftmost index or -1 if absent
        return first;
    };

    // Helper function to find the last occurrence of target using binary search
    auto findLastOccurrence = [&](const vector<int>& arr, int target) -> int {
        // Step 1: initialize search range
        int low = 0, high = arr.size() - 1;
        int last = -1; // Initialize to -1 to indicate "not found"
        // Step 2: binary search loop to find rightmost occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                // Candidate for last occurrence found; move right to find later one
                last = mid;
                low = mid + 1; // Continue searching in the right half
            } else if (arr[mid] < target) {
                // Target lies to the right
                low = mid + 1;
            } else {
                // Target lies to the left
                high = mid - 1;
            }
        }
        // Step 3: return the rightmost index or -1 if absent
        return last;
    };

    int firstOccurrence = findFirstOccurrence(arr, target);
    if (firstOccurrence == -1) {
        return 0; // If target is not found, return count as 0
    }
    int lastOccurrence = findLastOccurrence(arr, target);
    return lastOccurrence - firstOccurrence + 1; // Calculate and return the count of occurrences
}

int main() {
    // Sample sorted array and target value
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5};
    int target = 4;

    // --- RUN OPTIONS ---
    // By default this main runs both approaches and prints their counts.
    // To focus only on the optimal approach, you can comment out the brute-force call below.

    // Count occurrences using brute force approach (O(N))
    int countBruteForce = countOccurrencesBruteForce(arr, target);
    cout << "Count of " << target << " (Brute Force): " << countBruteForce << endl;

    // Count occurrences using binary search approach (O(log N) per bound)
    int countBinarySearch = countOccurrencesBinarySearch(arr, target);
    cout << "Count of " << target << " (Binary Search): " << countBinarySearch << endl;

    return 0;
}
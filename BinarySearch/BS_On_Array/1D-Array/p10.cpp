// Minimal in rotated sorted array
#include <iostream>
#include <vector>
#include<climits>
using namespace std;

// Brute force approach: scan the array and find the minimum element.
// Time complexity: O(N)
// Space complexity: O(1)
// Steps:
// 1) Validate non-empty input.
// 2) Initialize `minElement` with first element.
// 3) Iterate through array, updating `minElement` whenever a smaller value is found.
// 4) Return `minElement` after scanning all elements.
int FindMinimumBruteForce(const vector<int>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Array cannot be empty");
    }
    int minElement = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    return minElement;
}

// Optimal approach: Use modified binary search to find the minimum element.
// Time complexity: O(log N) in average case, O(N) in worst case (when all elements are the same)
// Space complexity: O(1)
// Steps:
// 1) Maintain search range [low..high] and an `ans` to store the minimum seen so far.
// 2) If left half [low..mid] is sorted (arr[low] <= arr[mid]) then the minimum
//    must be arr[low] or in the right half — update `ans` with arr[low] and move low = mid+1.
// 3) Otherwise the right half contains the minimum — update `ans` with arr[mid] and move high = mid-1.
// 4) Continue until range exhausted; `ans` holds the minimum element.

int FindMinimumBinarySearch(const vector<int>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Array cannot be empty");
    }
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If left half is sorted, the smallest in this half is at `low`.
        // Record it as a candidate and skip to the right half.
        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]); // Candidate minimum from left sorted half
            low = mid + 1; // Move to right half to find a potentially smaller value
        } else {
            // Otherwise, the minimum must be at mid or to its left.
            ans = min(ans, arr[mid]); // Candidate minimum from mid
            high = mid - 1; // Narrow to left half
        }
    }
    // `ans` holds the minimum value encountered during the search
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    // --- RUN OPTIONS ---
    // Brute force: simple O(N) scan
    cout << "Minimum element (Brute Force): " << FindMinimumBruteForce(arr) << endl;
    // Binary search: average-case O(log N) approach; still handles duplicates
    cout << "Minimum element (Binary Search): " << FindMinimumBinarySearch(arr) << endl;

    return 0;
}
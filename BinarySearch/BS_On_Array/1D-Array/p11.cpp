// Find How Many Times Array is Rotated
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach: scan the array and find the index of the minimum element.
// Time complexity: O(N)
// Space complexity: O(1)
// Steps:
// 1) Check for empty array and handle error.
// 2) Scan array to find the smallest element's index.
// 3) Return the index of minimum element — that index equals rotation count.
int CountRotationsBruteForce(const vector<int>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Array cannot be empty");
    }
    int minIndex = 0;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    // The index of the smallest element equals the number of rotations
    return minIndex;
}   

// Optimal approach: Use modified binary search to find the index of the minimum element.
// Time complexity: O(log N) in average case, O(N) in worst case (when all elements are the same)
// Space complexity: O(1)   
int CountRotationsBinarySearch(const vector<int>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Array cannot be empty");
    }
    int low = 0, high = arr.size() - 1;
    // Use binary search variant to find the index of minimum element.
    // Invariant: the minimum lies in [low..high].
    // Steps:
    // 1) Compute mid.
    // 2) If arr[mid] > arr[high], the minimum is in (mid..high]. Move low = mid+1.
    // 3) Otherwise, the minimum is in [low..mid]. Move high = mid-1.
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // If middle element is greater than element at high,
        // the minimum is in the right half
        if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            // Minimum is in the left half including mid
            high = mid - 1;
        }
    }
    // Return low — index of minimum element (rotation count)
    return low;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    // --- RUN OPTIONS ---
    // Brute force: simple O(N) scan to find minimum index
    cout << "Count of rotations (Brute Force): " << CountRotationsBruteForce(arr) << endl;
    // Binary search: O(log N) average-case approach to find rotation count
    cout << "Count of rotations (Binary Search): " << CountRotationsBinarySearch(arr) << endl;

    return 0;
}
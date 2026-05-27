// Search element in rotated sorted array (duplicates elements allowed)
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach: scan the array and find the target value.
// Time complexity: O(N)
// Space complexity: O(1)
int SearchElementBruteForce(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return true; // Return true if target is found
        }
    }
    return false; // Return false if target is not found
}

// Optimal approach: Use modified binary search to handle duplicates
// Time complexity: O(log N) in average case, O(N) in worst case (when all elements are the same)
// Space complexity: O(1)
// Steps:
// 1) Initialize pointers to the full range of the array.
// 2) Compute mid index in each iteration.
// 3) If arr[mid] == target, return true.
// 4) If left half [low..mid] is sorted:
//    - If target lies within the sorted left half, search there.
//    - Otherwise, search in the right half.
// 5) If right half [mid..high] is sorted:
//    - If target lies within the sorted right half, search there.
//    - Otherwise, search in the left half.
// 6) If arr[low] == arr[mid] == arr[high], we cannot determine the sorted half, so shrink both ends.
int SearchElementBinarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Step 3: Check if mid element is the target
        if (arr[mid] == target) {
            return true; // Found — return true immediately
        }

        // Step 4: Determine which half is sorted
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            // All three values are equal, so we cannot decide which half is sorted.
            // Shrink both ends and keep searching.
            low++;
            high--;
        } else if (arr[low] <= arr[mid]) {
            // Left half [low..mid] is sorted
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1; // Search left half
            } else {
                low = mid + 1; // Search right half
            }
        } else {
            // Right half [mid..high] is sorted
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1; // Search right half
            } else {
                high = mid - 1; // Search left half
            }
        }
    }

    return false; // Not found — return false as a sentinel value
}

int main() {
    vector<int> arr = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1}; // Example of a rotated sorted array
    int target = 2;

    // --- RUN OPTIONS ---
    bool found = SearchElementBinarySearch(arr, target);
    cout << "Element " << target << (found ? " found." : " not found.") << endl;
    return 0;
}

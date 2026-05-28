// Find single element in sorted array
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach: scan the array and find the single element.
// Time complexity: O(N)
// Space complexity: O(1)
// Steps:
// 1) Iterate through the array indices.
// 2) For each index `i`, compare with neighbors (if present).
// 3) If `arr[i]` differs from both neighbors, it's the single element.
int FindSingleElementBruteForce(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        // Check left neighbor (if any) and right neighbor (if any)
        if ((i == 0 || arr[i] != arr[i - 1]) && (i == arr.size() - 1 || arr[i] != arr[i + 1])) {
            return arr[i]; // Found the single element
        }
    }
    throw invalid_argument("No single element found");
}

// Optimal approach: Use modified binary search to find the single element.
// Time complexity: O(log N)
// Space complexity: O(1)
// High-level steps:
// 1) Quick-check boundaries for single element.
// 2) Use binary search invariant where pairs align before the single element.
// 3) For mid, if it's different from neighbors, it's the single element.
// 4) Use parity of mid to decide which half contains the single element.

int FindSingleElementBinarySearch(const vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    if (nums.empty()) {
        throw invalid_argument("Array cannot be empty");
    }

    if (nums[low] != nums[low + 1]) {
        return nums[low];
    }

    if (nums[high] != nums[high - 1]) {
        return nums[high];
    }

    // Use binary search variant to find the single element.
    // Invariant: the single element lies in [low..high].
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // If middle element is not equal to its neighbors, it's the single element.
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }
        // Determine pairing alignment relative to mid:
        // - If mid is even and nums[mid] == nums[mid+1], pair starts at mid -> single is right.
        // - If mid is odd and nums[mid] == nums[mid-1], pair ends at mid -> single is right.
        // Otherwise single lies to the left.
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    throw invalid_argument("No single element found");
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4};
    cout << "Single element (Brute Force): " << FindSingleElementBruteForce(arr) << endl;
    cout << "Single element (Binary Search): " << FindSingleElementBinarySearch(arr) << endl;

    return 0;
}
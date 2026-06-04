// Find Peak Element in an Array
// A peak element is an element that is greater than its neighbors. Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index. The array may contain multiple peaks, in that case return the index to any one of the peaks is fine. You may imagine that nums[-1] = nums[n] = -∞.
#include <iostream>
#include <vector>
using namespace std;

// BruteForce Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// Steps:
// 1) Handle trivial array sizes (n==1).
// 2) Iterate through each index i.
// 3) For each i, check left neighbor (if exists) and right neighbor (if exists).
// 4) If nums[i] is greater than both neighbors (or neighbor boundary), it's a peak.
// 5) Return the index of the first found peak.
int findPeakElementBruteForce(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    for (int i = 0; i < n; i++) {
        // Check left and right neighbors with boundary handling
        if ((i == 0 || nums[i] > nums[i - 1]) && (i == n - 1 || nums[i] > nums[i + 1])) {
            // Found a peak element at index i
            return i;
        }
    }
    return -1; // This line will never be reached since there is always a peak element
}

// Optimal Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Steps:
// 1) Maintain search range [left..right].
// 2) Compute mid and compare nums[mid] with nums[mid+1].
// 3) If nums[mid] > nums[mid+1], a peak exists in [left..mid], so move right=mid.
// 4) Otherwise, a peak exists in [mid+1..right], so move left=mid+1.
// 5) Continue until left==right; that index is a peak.
int findPeakElementBinarySearch(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[mid + 1]) {
            // Peak is in the left half (including mid)
            right = mid;
        } else {
            // Peak is in the right half
            left = mid + 1;
        }
    }
    
    return left; // or right, since left == right at the end
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    // --- RUN OPTIONS ---
    // Brute force: simple O(n) scan that returns the first peak found
    cout << "Peak Element Index (Brute Force): " << findPeakElementBruteForce(nums) << endl;
    // Binary search: O(log n) approach that finds a peak using comparisons with mid+1
    cout << "Peak Element Index (Binary Search): " << findPeakElementBinarySearch(nums) << endl;
    return 0;
}
// Median of two sorted arrays of different sizes
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute force approach: merge the two sorted arrays and find the median.
// Time complexity: O(n + m) where n and m are the sizes of the two arrays.
// Space complexity: O(n + m) for the merged array. 
// Steps :
// 1) Make a new empty list that will hold all numbers from both arrays in sorted order.
// 2) Use two pointers: one for `nums1`, one for `nums2`. Always take the smaller current number
//    and append it to the merged list. This keeps the merged list sorted without extra work.
// 3) After one array is fully used, append the remaining numbers from the other array.
// 4) Once merged, if the total length is even, the median is the average of the two middle numbers;
//    if odd, the median is the middle number. We return that value as a double.
double findMedianSortedArraysBruteForce(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> merged(n + m);
    
    // Merge the two arrays using two-pointer technique
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        // Compare current elements from both arrays; pick the smaller one to keep order.
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++]; // take from nums1
        } else {
            merged[k++] = nums2[j++]; // take from nums2
        }
    }
    while (i < n) {
        // nums2 is exhausted; copy remaining nums1 elements.
        merged[k++] = nums1[i++];
    }
    while (j < m) {
        // nums1 is exhausted; copy remaining nums2 elements.
        merged[k++] = nums2[j++];
    }
    
    // Calculate median
    // Compute median from merged array.
    int totalLength = n + m;
    if (totalLength % 2 == 0) {
        // Even length: average of two middle values. Cast to double for fractional answer.
        return (merged[totalLength / 2 - 1] + merged[totalLength / 2]) / 2.0;
    } else {
        // Odd length: middle element is the median.
        return merged[totalLength / 2];
    }
}

// Optimal approach: Use binary search to find the correct partition of the two arrays.
// Time complexity: O(log(min(n, m))) where n and m are the sizes of the two arrays.
// Space complexity: O(1).
// Steps :
// 1) Always run the binary search on the smaller array to keep the number of steps small.
// 2) A "partition" splits each array into left and right parts. Together, the left parts
//    should contain half (or one more than half) of the total elements.
// 3) We pick a partition in `nums1` and infer the corresponding partition in `nums2` so
//    that left+right counts match. Then we only need to check 4 numbers around the partitions:
//    the biggest on the left side of each array and the smallest on the right side of each array.
// 4) If the largest left value from both arrays is <= the smallest right value from both arrays,
//    the partition is correct and we can compute the median from those boundary values.
// 5) If not, move the partition left or right in the smaller array and repeat.
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1); // Ensure nums1 is the smaller array
    }
    
    int n = nums1.size();
    int m = nums2.size();
    int low = 0, high = n;
    
    while (low <= high) {
        // Pick a partition index for nums1; partitionY is derived so left side holds half elements.
        int partitionX = low + (high - low) / 2;
        int partitionY = (n + m + 1) / 2 - partitionX; // ensures left side has the extra element when total is odd

        // If partitionX is 0 it means nothing on left side of nums1; use -inf for maxLeftX.
        // If partitionX is n it means nothing on right side of nums1; use +inf for minRightX.
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == n) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == m) ? INT_MAX : nums2[partitionY];

        // Check if we have found correct partition: every left element <= every right element.
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // Correct partition found. Now compute median depending on total length parity.
            if ((n + m) % 2 == 0) {
                // Even total length: median is average of max of lefts and min of rights.
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                // Odd total length: median is the max of left side.
                return max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            // We are too far on right in nums1; need to move left.
            high = partitionX - 1; // Move towards the left in nums1
        } else {
            // We are too far on left in nums1; need to move right.
            low = partitionX + 1; // Move towards the right in nums1
        }
    }
    
    throw invalid_argument("Input arrays are not sorted.");
}

int main() {
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4, 6};
    
    cout << "Median (Brute Force): " << findMedianSortedArraysBruteForce(nums1, nums2) << endl;
    cout << "Median (Optimal): " << findMedianSortedArrays(nums1, nums2) << endl;

    // --- RUN OPTIONS ---
    // Brute Force: merge both arrays and compute median directly (easy to understand, uses extra space).
    // Optimal: uses binary search on the smaller array for O(log(min(n,m))) time and O(1) space.

    // --- DRY RUN (easy steps) ---
    // nums1 = {1,3,5}, nums2 = {2,4,6}
    // 1) Brute-force merges to {1,2,3,4,5,6}; median = (3+4)/2 = 3.5
    // 2) Optimal: binary-search on smaller array nums1 (size 3)
    //    - low=0, high=3, partitionX=1 -> partitionY=(3+3+1)/2-1=2
    //    - maxLeftX=nums1[0]=1, minRightX=nums1[1]=3
    //    - maxLeftY=nums2[1]=4, minRightY=nums2[2]=6
    //    - Since maxLeftY(4) > minRightX(3), move partitionX right
    //    - Continue until correct partition found; result = 3.5

    return 0;
}
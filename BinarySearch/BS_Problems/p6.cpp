// Split Array Largest Sum / Painter's Partition
// Given an array which consists of non-negative integers and an integer m,
// you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
#include <iostream>
#include <vector>
#include <climits>
#include <numeric>
#include <algorithm>
using namespace std;

// Helper function to count how many partitions are needed if we limit each partition's sum to `maxSum`.
// Steps:
// 1) Use a helper idea that scans the array and counts how many partitions are needed
//    if we limit each partition to a maximum sum.
// 2) Start with one partition and a running sum of the current subarray.
// 3) If adding the next element stays within the allowed maxSum, keep extending the current partition.
// 4) Otherwise, start a new partition from that element.
// 5) The returned partition count tells us whether the chosen maxSum is feasible.
 int countPartitions(vector<int> &a, int maxSum) {
    int n = a.size(); // size of the array
    int partitions = 1; // always have at least 1 partition
    long long subarraySum = 0; // sum of the current subarray

        for (int i = 0; i < n; i++) {
            // Step: try to include the current element in the running subarray.
            // If the sum stays within maxSum, continue with the same partition.
            if (subarraySum + a[i] <= maxSum) {
                subarraySum += a[i];
            }
            else {
                // Step: current partition would exceed maxSum, so close it here
                // and begin a new partition starting from a[i].
                partitions++;
                subarraySum = a[i];
            }
        }
    return partitions;
}


// Brute force approach: try every possible answer from the largest element to the total sum.
// For each candidate answer, check if the array can be split into at most m partitions.
// Time complexity: O(n * sum of array)
// Space complexity: O(1)
// Steps:
// 1) Start from the maximum element, because the largest subarray sum cannot be smaller than that.
// 2) Go up to the total sum, because one partition containing everything is always valid.
// 3) For every candidate sum, use countPartitions to see how many partitions are needed.
// 4) Return the first candidate that needs at most m partitions.
int splitArrayBruteForce(vector<int>& a, int m) {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    for (int target = low; target <= high; target++) {
        int requiredPartitions = countPartitions(a, target);
        if (requiredPartitions <= m) {
            return target;
        }
    }

    return high;
}


// Optimal approach: Use binary search to find the minimum largest sum among m subarrays.
// Time complexity: O(n log(sum of array)) where n is the size of the input array.
// Space complexity: O(1).
// Steps:
// 1) The minimum possible largest sum is the maximum element in the array, because every partition must contain at least one element.
// 2) The maximum possible largest sum is the total sum of the array, because one partition can contain everything.
// 3) Binary search on this answer range.
// 4) For each candidate answer `mid`, call countPartitions to see how many partitions are needed.
// 5) If more than m partitions are needed, increase `mid`; otherwise try a smaller answer.
// 6) The helper `countPartitions` acts like the feasibility test for a guessed answer.
int splitArray(vector<int>& a, int m) {
    int low = *max_element(a.begin(), a.end()); // The largest single element is the minimum possible largest sum
    int high = accumulate(a.begin(), a.end(), 0); // The sum of all elements is the maximum possible largest sum

    while (low < high) {
        int mid = low + (high - low) / 2; // Midpoint of the current range
        // Check how many partitions are required if no partition is allowed to exceed `mid`.
        // If this count is greater than `m`, then `mid` is not a valid answer yet.
        int requiredPartitions = countPartitions(a, mid); // Count how many partitions are needed with max sum mid

        if (requiredPartitions > m) {
            // Too many partitions means `mid` is too small, so move the lower bound up.
            low = mid + 1; // Move the lower bound up
        } else {
            // If `mid` works, try to find an even smaller feasible largest sum.
            high = mid; // Move the upper bound down
        }
    }
    return low; // At the end of the loop, low is the minimum largest sum that allows for m partitions
}

int main() {
    // Example input: can be changed to test other cases.
    vector<int> a = {7, 2, 5, 10, 8};
    int m = 2;

    // --- RUN OPTIONS ---
    // Brute force: checks every possible largest sum until it finds the first valid one.
    cout << "Brute Force Answer: " << splitArrayBruteForce(a, m) << endl;
    // Better/optimal: binary search over the answer space.
    cout << "Minimum largest sum among " << m << " subarrays: " << splitArray(a, m) << endl;

    // --- DRY RUN ---
    // For a = {7,2,5,10,8}, m = 2:
    // 1) low = max element = 10, high = total sum = 32
    // 2) mid = 21 -> partitions needed = 2, so 21 is feasible; shrink high to 21
    // 3) mid = 15 -> partitions needed = 3, so 15 is too small; raise low to 16
    // 4) mid = 18 -> partitions needed = 2, so 18 is feasible; shrink high to 18
    // 5) mid = 17 -> partitions needed = 3, so 17 is too small; raise low to 18
    // 6) low == high == 18, so answer is 18
    // Final output should be 18 for the sample input above.

    return 0;
}
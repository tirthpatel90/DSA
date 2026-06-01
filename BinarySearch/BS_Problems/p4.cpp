// Find the Smallest Divisor Given a Threshold
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach: check each possible divisor from 1 to max size and calculate total sum of ceilings.
// Time complexity: O(N * log M) where N is number of elements and M is the maximum element size (worst case).
// Space complexity: O(1)
// Steps:
// 1) Find the maximum element size — that's the upper bound for divisor.
// 2) For each candidate divisor from 1..maxElement, compute total sum of ceilings.
// 3) For an element, contribution = ceil(element / divisor) → implemented as (element + divisor - 1)/divisor.
// 4) If total sum <= threshold, return the candidate divisor as minimum feasible.  
int smallestDivisorBruteForce(const vector<int>& nums, int threshold) {
    int maxNum = 0;
    for (int num : nums) {
        maxNum = max(maxNum, num); // Find the maximum element size
    }

    // Check each possible divisor from 1 to maxNum
    for (int divisor = 1; divisor <= maxNum; ++divisor) {
        int sum = 0;
        // Step: for each element, compute its contribution at this `divisor`.
        for (int num : nums) {
            // Use integer math to compute ceiling division: (num + divisor - 1) / divisor
            sum += (num + divisor - 1) / divisor; // Contribution of this element
            // Early exit: if sum already exceeds allowed `threshold`, no need to check remaining elements.
            if (sum > threshold) break;
        }
        // If total sum fits within `threshold`, this `divisor` is feasible; since we iterate from small to
        // large divisors, the first feasible divisor is the minimum required.
        if (sum <= threshold) {
            return divisor; // Found the minimum divisor that allows sum to be within threshold
        }
    }
    return -1; // This line should never be reached since maxNum is a valid divisor
}

// Optimal approach: Use binary search to find the minimum divisor efficiently.
// Time complexity: O(N * log M) where N is number of elements and M is the maximum element size (worst case).
// Space complexity: O(1)
// Steps:
// 1) Set search range [low, high] where low=1 and high=max element size.
// 2) While low<=high, test mid divisor. Compute total sum of ceilings at `mid`.
// 3) If sum <= threshold, mid is feasible — move left to find smaller feasible divisor.
// 4) Else mid is too small — move right to increase divisor.
int smallestDivisorBinarySearch(const vector<int>& nums, int threshold) {
    int low = 1; // Minimum possible divisor
    int high = 0; // Maximum possible divisor (max element size)
    for (int num : nums) {
        high = max(high, num);
    }

    while (low <= high) {
        int mid = low + (high - low) / 2; // Midpoint divisor to test
        int sum = 0;
        // Compute total sum for this `mid` divisor, with early exit if exceeding `threshold`.
        for (int num : nums) {
            sum += (num + mid - 1) / mid; // Contribution of this element at divisor `mid`
            if (sum > threshold) break; // No need to continue if already impossible
        }
        // If `mid` allows sum to be within `threshold`, it is a candidate; try smaller divisors.
        if (sum <= threshold) {
            high = mid - 1; // Mid is a valid divisor, try to find a smaller one
        } else {
            // Mid is too small; try larger divisors.
            low = mid + 1; // Mid is too small, try a larger divisor
        }
    }
    return low; // Low is the minimum valid divisor after binary search completes
}

int main() {
    // Example input: you can change these to run different cases.
    // `nums` : array of positive integers whose summed ceilings we control via divisor.
    // `threshold` : the maximum allowed sum after dividing and rounding up each element.
    vector<int> nums = {1,2,3,4,5};
    int threshold = 8;

    // --- RUN OPTIONS ---
    // Brute Force: tries every divisor from 1..max(nums) and returns first feasible one.
    cout << "Brute Force Result: " << smallestDivisorBruteForce(nums, threshold) << endl;
    // Binary Search: efficient approach using search on divisor space.
    cout << "Binary Search Result: " << smallestDivisorBinarySearch(nums, threshold) << endl;

    // Suggested tests:
    // 1) nums = {1,2,3,4,5}, threshold = 8 -> small array sanity check
    // 2) nums = {44,22,33,11}, threshold = 20 -> tests larger elements
    // 3) nums = {1}, threshold = 1 -> smallest edge case

    return 0;
}

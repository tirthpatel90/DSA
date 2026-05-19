//count subarray sum equals k
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: Check all possible subarrays and count those that sum to k.
// Time Complexity: O(n^2) - we check all subarrays.
// Space Complexity: O(1) - we only use a few variables for counting and summing.
// Steps:
// 1) Start from each index as the beginning of a potential subarray.
// 2) For each start index, extend the subarray by adding next elements one by one.
// 3) Maintain running sum as we extend the subarray.
// 4) If current sum equals k, increment the count.
// 5) Continue extending until we reach the end of array.
// 6) Return the total count of all subarrays that sum to k.
int subarraySumBruteForce(vector<int>& nums, int k) {
    int count = 0;
    // Step 1: Iterate through each possible start index
    for (int start = 0; start < nums.size(); start++) {
        int sum = 0;
        // Step 2-5: Extend subarray from start and check sum at each step
        for (int end = start; end < nums.size(); end++) {
            sum += nums[end]; // Step 3: Update running sum of current subarray
            // Step 4: Check if current subarray sum equals k
            if (sum == k) {
                count++; // Increment count if we found a matching subarray
            }
        }
    }
    // Step 6: Return the total count of subarrays that sum to k
    return count;
}

// Optimal Approach: Use a hash map to store the cumulative sum frequencies.
// Time Complexity: O(n) - we traverse the array once.
// Space Complexity: O(n) - in the worst case, we might store all cumulative sums in the hash map.
// Steps:
// 1) Use a map to store frequency of each cumulative sum.
// 2) Initialize map with 0 appearing once (base case for subarrays starting from index 0).
// 3) Traverse array maintaining cumulative sum.
// 4) For each position, check if (cumsum - k) exists in map.
//    If it exists, it means there are subarray(s) ending here with sum k.
// 5) Add current cumsum and its frequency to the map.
// 6) Return total count of subarrays with sum k.
int subarraySumOptimal(vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    // Step 1: Map to store frequency of each cumulative sum
    unordered_map<int, int> prefixSumCount;
    // Step 2: Base case - there's one way to have sum 0 (using no elements)
    prefixSumCount[0] = 1;

    // Step 3: Traverse array once
    for (int num : nums) {
        sum += num; // Update cumulative sum
        
        // Step 4: Check if (sum - k) exists in map
        // If (sum - k) exists, then subarray from that point to current point sums to k
        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            // Add the frequency of (sum - k) to count
            // This handles multiple subarrays with same sum
            count += prefixSumCount[sum - k];
        }
        
        // Step 5: Add/update the frequency of current cumulative sum
        prefixSumCount[sum]++;
    }

    // Step 6: Return the total count of subarrays that sum to k
    return count;
}

int main() {
    // Sample input: array of integers and target sum k
    vector<int> nums = {1, 1, 1};
    int k = 2;

    // --- BRUTE FORCE APPROACH ---
    // Uncomment the lines below to run brute force.
    // Checks all possible subarrays O(n^2) time, but O(1) space.
    // int bruteForceResult = subarraySumBruteForce(nums, k);
    // cout << "Brute Force Result: " << bruteForceResult << endl; // Expected output: 2

    // --- OPTIMAL APPROACH ---
    // Running optimal approach by default.
    // Uses prefix sum + hash map for O(n) time and O(n) space.
    int optimalResult = subarraySumOptimal(nums, k);
    cout << "Optimal Result: " << optimalResult << endl; // Expected output: 2

    return 0;
}
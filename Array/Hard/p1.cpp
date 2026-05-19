//count subarrays with given XOR k
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: Check all possible subarrays and count those that XOR to k.
// Time Complexity: O(n^2) - we check all subarrays.
// Space Complexity: O(1) - we only use a few variables for counting and XORing.
// Steps: 1. Iterate through each element as the starting point of a subarray.
//        2. For each starting point, iterate through the remaining elements to form subarrays.
//        3. Calculate the XOR of each subarray and check if it equals k.
//        4. Increment the count if the condition is met.
int countSubarraysWithXORBruteForce(vector<int>& nums, int k) {
    int count = 0;
    // Step 1: Iterate through each starting point
    for (int start = 0; start < nums.size(); start++) {
        int xorValue = 0; // Initialize XOR value for the current subarray
        // Step 2: Extend the subarray from the starting point
        for (int end = start; end < nums.size(); end++) {
            xorValue ^= nums[end]; // Update XOR value with the new element
            // Step 3: Check if current XOR equals k
            if (xorValue == k) {
                count++; // Increment count if we found a matching subarray
            }
        }
    }
    return count; // Return total count of subarrays that XOR to k
}

// Optimal Approach: Use a hash map to store the frequency of cumulative XOR values.
// Time Complexity: O(n) - we traverse the array once.
// Space Complexity: O(n) - in the worst case, we might store all cumulative XOR values in the hash map.
// Steps: 1. Use a map to store frequency of each cumulative XOR value.
//        2. Initialize map with 0 appearing once (base case for subarrays starting from index 0).
//        3. Traverse array maintaining cumulative XOR.
//        4. For each position, check if (cumulative XOR ^ k) exists in map.
//           If it exists, it means there are subarray(s) ending here with XOR k
//        5. Add current cumulative XOR and its frequency to the map.
//        6. Return total count of subarrays with XOR k.
int countSubarraysWithXOROptimal(vector<int>& nums, int k) {
    int count = 0;
    int xorValue = 0; // Initialize cumulative XOR value
    // Step 1: Map to store frequency of each cumulative XOR value
    unordered_map<int, int> prefixXORCount;
    // Step 2: Base case - there's one way to have XOR 0 (using no elements)
    prefixXORCount[0] = 1;

    // Step 3: Traverse array once
    for (int num : nums) {
        xorValue ^= num; // Update cumulative XOR with the new element
        
        // Step 4: Check if (xorValue ^ k) exists in map
        // If (xorValue ^ k) exists, then subarray from that point to current point has XOR k
        if (prefixXORCount.find(xorValue ^ k) != prefixXORCount.end()) {
            // Add the frequency of (xorValue ^ k) to count
            // This handles multiple subarrays with same XOR
            count += prefixXORCount[xorValue ^ k];
        }
        
        // Step 5: Add current cumulative XOR and its frequency to the map
        prefixXORCount[xorValue]++;
    }
    
    return count; // Return total count of subarrays that XOR to k
}

int main() {
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    
    // Using Brute Force Approach
    int bruteForceCount = countSubarraysWithXORBruteForce(nums, k);
    cout << "Count of subarrays with XOR " << k << " (Brute Force): " << bruteForceCount << endl;
    
    // Using Optimal Approach
    int optimalCount = countSubarraysWithXOROptimal(nums, k);
    cout << "Count of subarrays with XOR " << k << " (Optimal): " << optimalCount << endl;
    
    return 0;
}
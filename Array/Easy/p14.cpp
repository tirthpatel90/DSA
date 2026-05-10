// Longest Subarray with Sum K
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Brute force: using loops to find the longest subarray with sum k
//time: O(n^3), space: O(1)
int longestSubarrayBruteForce(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLength = 0;

    // Step 1: Iterate through all possible starting points of subarrays
    for (int start = 0; start < n; start++) {
        // Step 2: Iterate through all possible ending points of subarrays
        for (int end = start; end < n; end++) {
            int sum = 0;
            // Step 3: Calculate the sum of the current subarray from start to end
            for (int i = start; i <= end; i++) {
                sum += arr[i];
            }
            // Step 4: If the sum equals k, update the maximum length
            if (sum == k) {
                maxLength = max(maxLength, end - start + 1);
            }
        }
    }
    return maxLength;
}

//Better: we can use a hash map to store the cumulative sum and its index, and then check if the cumulative sum minus k exists in the hash map.
//time: O(n^2), space: O(n) for hash map
int longestSubarrayBetter(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLength = 0;
    unordered_map<int, int> sumIndexMap; // Map to store cumulative sum and its index
    int cumulativeSum = 0;

    // Step 1: Iterate through the array to calculate cumulative sums
    for (int i = 0; i < n; i++) {
        cumulativeSum += arr[i];

        // Step 2: Check if cumulative sum equals k, if yes, update maxLength
        if (cumulativeSum == k) {
            maxLength = max(maxLength, i + 1);
        }

        // Step 3: Check if (cumulativeSum - k) exists in the map
        if (sumIndexMap.find(cumulativeSum - k) != sumIndexMap.end()) {
            maxLength = max(maxLength, i - sumIndexMap[cumulativeSum - k]);
        }

        // Step 4: Store the index of the first occurrence of the cumulative sum
        if (sumIndexMap.find(cumulativeSum) == sumIndexMap.end()) {
            sumIndexMap[cumulativeSum] = i;
        }
    }
    return maxLength;
}

//Optimal: using two pointers to find the longest subarray with sum k
//time: O(n), space: O(1)

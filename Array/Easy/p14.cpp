// Longest Subarray with Sum K (Positive and Negative Numbers)
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
int longestSubarrayOptimal(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLength = 0;
    int left = 0, right = 0;
    int Sum = 0;

    // Step 1: Use two pointers to traverse the array
    while (right < n) {
        Sum += arr[right];// Add the current element to the current sum

        // Step 2: If current sum exceeds k, move the left pointer to reduce the sum
        while (Sum > k && left <= right) {
            Sum -= arr[left];// Subtract the element at the left pointer from the current sum
            left++;
        }

        // Step 3: If current sum equals k, update maxLength
        if (Sum == k) {
            maxLength = max(maxLength, right - left + 1);// Update the maximum length of the subarray
        }
        right++;
    }
    return maxLength;
}

int main() {
    vector<int> arr = {1, -1, 5, -2, 3};
    int k = 3;

    cout << "Brute Force: " << longestSubarrayBruteForce(arr, k) << endl;
    cout << "Better: " << longestSubarrayBetter(arr, k) << endl;
    cout << "Optimal: " << longestSubarrayOptimal(arr, k) << endl;

    return 0;
}

/*
For arrays that can contain negative numbers, the sliding window / two-pointer
approach is not reliable. Use prefix sum + hash map instead.

Steps:
1. Keep a running prefix sum while traversing the array.
2. If prefix sum itself becomes k, update the answer with length i + 1.
3. Store the first index where each prefix sum appears.
4. If (prefixSum - k) was seen before, the subarray after that index has sum k.
5. Update the maximum length whenever such a subarray is found.

Time complexity: O(n)
Space complexity: O(n)

int longestSubarrayNegative(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLength = 0;
    unordered_map<int, int> prefixIndex;
    int prefixSum = 0;

    for (int i = 0; i < n; i++) {
        // Step 1: add current element to the running prefix sum
        prefixSum += arr[i];

        // Step 2: if prefix sum itself is k, the subarray starts from index 0
        if (prefixSum == k) {
            maxLength = max(maxLength, i + 1);
        }

        // Step 3: if (prefixSum - k) already exists, a subarray with sum k is found
        if (prefixIndex.find(prefixSum - k) != prefixIndex.end()) {
            maxLength = max(maxLength, i - prefixIndex[prefixSum - k]);
        }

        // Step 4: store only the first occurrence of each prefix sum
        if (prefixIndex.find(prefixSum) == prefixIndex.end()) {
            prefixIndex[prefixSum] = i;
        }
    }

    return maxLength;
}

// To test it, call:
// cout << "Negative allowed: " << longestSubarrayNegative(arr, k) << endl;
*/
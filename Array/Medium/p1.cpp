// Two Sum : Check if a pair with given sum exists in Array
// Problem Statement: Given an array of integers and a target sum, determine if there are two numbers in the array that add up to the target sum. The function should return true if such a pair exists, and false otherwise.
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
//arr = {2, 7, 11, 15, 3}
//Brute force: using loops to find if a pair with given sum exists in Array
//time: O(n^2), space: O(1)
vector<int> twoSumBruteForce(vector<int>& arr, int k) {
    int n = arr.size();

    // Step 1: Iterate through all possible pairs of elements in the array
    // Dry run: i=0, j=1 -> check 2 and 7 first
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Step 2: Check if the sum of the current pair equals k (if true, return indices)
            // Dry run: 2 + 7 = 9, so return indices [0, 1]
            if (arr[i] + arr[j] == k) {
                // Pair found: return indices of the two elements
                return {i, j};
            }
        }
    }
    // No pair found (if all pairs checked and none equal k, return empty vector)
    return {};
}

//Better: using a hash map to store the value and its index, check if (k - current element) exists
//time: O(n), space: O(n) for hash map
vector<int> twoSumBetter(vector<int>& arr, int k) {
    unordered_map<int, int> valueIndex; // Map to store value and its index
    
    // Step 1: Iterate through the array
    // Dry run: start with num = 2, seen is empty
    for (int i = 0; i < arr.size(); i++) {
        int complement = k - arr[i]; // Calculate what we need to sum with current element
        // Step 2: Check if complement exists in the map (if true, pair found)
        // Dry run: for num = 7, complement = 2, and 2 is already in the map
        if (valueIndex.find(complement) != valueIndex.end()) {
            // Pair found: return indices of the complement and current element
            return {valueIndex[complement], i};
        }
        // Step 3: Add the current value and its index to the map
        // Dry run: after seeing 2, store {2 -> 0}; after seeing 7, store {7 -> 1}
        valueIndex[arr[i]] = i;
    }
    // No pair found (if all elements checked and no pair sums to k, return empty vector)
    return {};
}

//Optimal: using two pointers to find if a pair with given sum exists in Array
//time: O(n log n) due to sorting, space: O(1) if we can sort in place, otherwise O(n) for sorting
vector<int> twoSumOptimal(vector<int>& arr, int k) {
    int n = arr.size();
    vector<pair<int, int>> valueIndexPairs; // Vector to store value and its original index

    // Step 1: Create pairs of (value, index) and sort them based on value
    // Dry run: pairs become (2,0), (7,1), (11,2), (15,3), (3,4)
    for (int i = 0; i < n; i++) {
        valueIndexPairs.push_back({arr[i], i});
    }
    // If true: we have all value-index pairs ready to sort
    sort(valueIndexPairs.begin(), valueIndexPairs.end());
    // After sorting: values are in ascending order, if any pair exists they will be found
    // Dry run after sort: (2,0), (3,4), (7,1), (11,2), (15,3)

    int left = 0; // Pointer starting from the beginning
    int right = n - 1; // Pointer starting from the end

    // Step 2: Use two pointers to find if a pair sums to k
    // Dry run: left = 0 (2), right = 4 (15), currentSum = 17
    while (left < right) {
        int currentSum = valueIndexPairs[left].first + valueIndexPairs[right].first;

        // Step 3: If current sum is less than k, move left pointer to the right
        // (if true: need larger sum, so move left pointer)
        if (currentSum < k) {
            left++;
        }
        // Step 4: If current sum is greater than k, move right pointer to the left
        // (if true: need smaller sum, so move right pointer)
        else if (currentSum > k) {
            right--;
        }
        // Step 5: If current sum equals k, return the original indices of the pair
        // (if true: pair found with exact sum k)
        else {
            return {valueIndexPairs[left].second, valueIndexPairs[right].second};
        }
    }
    // No pair found (if pointers cross and no pair sums to k, return empty vector)
    return {};
}

int main() {
    vector<int> arr = {2, 7, 11, 15, 3};
    int k = 9;

    vector<int> bruteForcResult = twoSumBruteForce(arr, k);
    vector<int> betterResult = twoSumBetter(arr, k);

    // Display Brute Force result
    cout << "Brute Force: ";
    if (!bruteForcResult.empty()) {
        cout << "Indices [" << bruteForcResult[0] << ", " << bruteForcResult[1] << "]" << endl;
    } else {
        cout << "No pair found" << endl;
    }

    // Display Better result
    cout << "Better: ";
    if (!betterResult.empty()) {
        cout << "Indices [" << betterResult[0] << ", " << betterResult[1] << "]" << endl;
    } else {
        cout << "No pair found" << endl;
    }

    // Display Optimal result
    cout << "Optimal: ";
    vector<int> optimalResult = twoSumOptimal(arr, k);
    if (!optimalResult.empty()) {
        cout << "Indices [" << optimalResult[0] << ", " << optimalResult[1] << "]" << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;

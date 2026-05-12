//Find the Majority Element that occurs more than N/2 times
//Problem Statement: Given an integer array nums of size n, return the majority element of the array.
//The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Brute force: using counters for each element, time: O(n^2), space: O(1)
int majorityElementBruteForce(vector<int>& nums) {
    // Step 1: Store the size of the array
    int n = nums.size();

    // Step 2: Treat each element as a possible majority candidate
    for (int i = 0; i < n; i++) {
        // Step 3: Initialize a counter for the current candidate
        int count = 0;
        // Step 4: Count how many times the current candidate appears in the array
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        // Step 5: If count is greater than n/2, the current element is the majority element
        if (count > n / 2) {
            return nums[i];
        }
    }
    // Step 6: Return fallback value if no majority is found
    return -1;
}

//Better: using a hash map to count occurrences of each element, 
//time: O(n), space: O(n)
int majorityElementBetter(vector<int>& nums) {
    // Step 1: Create a hash map to store each element's frequency
    unordered_map<int, int> countMap;
    // Step 2: Store the size of the array
    int n = nums.size();

    // Step 3: Traverse the array and update frequency counts
    for (int num : nums) {
        countMap[num]++;
        // Step 4: If the current frequency exceeds n/2, return that number immediately
        if (countMap[num] > n / 2) {
            return num;
        }
    }
    // Step 5: Return fallback value if no majority is found
    return -1;
}

//Optimal: using Boyer-Moore Voting Algorithm, 
//time: O(n), space: O(1)
int majorityElementOptimal(vector<int>& nums) {
    // Step 1: Initialize vote counter for the current candidate
    int count = 0;
    // Step 2: Store the current candidate for majority element
    int el;

    // Step 3: Iterate through the array to choose a candidate using Boyer-Moore voting
    for (int num : nums) {
        // Step 4: If counter becomes 0, pick the current number as the new candidate
        if (count == 0) {
            el = num;
        }
        // Step 5: Increase count if current number matches candidate, otherwise decrease it
        if (num == el) {
            count++;
        } else {
            count--;
        }
    }
    // Step 6: Verify the candidate by counting its actual occurrences
    int countCandidate = 0;
    for (int num : nums) {
        if (num == el) {
            countCandidate++;
        }
    }
    // Step 7: If candidate appears more than n/2 times, return it
    if (countCandidate > nums.size() / 2) {
        return el;
    }
    // Step 8: Return fallback value if verification fails
    return -1;
}

int main() {
    // Step 1: Create a sample array that contains a majority element
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    // Step 2: Find the majority element using brute force
    int bruteForceResult = majorityElementBruteForce(nums);
    // Step 3: Find the majority element using hashing
    int betterResult = majorityElementBetter(nums);
    // Step 4: Find the majority element using Boyer-Moore voting
    int optimalResult = majorityElementOptimal(nums);

    // Step 5: Print all results to compare the approaches
    cout << "Brute Force Majority Element: " << bruteForceResult << endl;
    cout << "Better Majority Element: " << betterResult << endl;
    cout << "Optimal Majority Element: " << optimalResult << endl;

    // Step 6: End the program successfully
    return 0;
}
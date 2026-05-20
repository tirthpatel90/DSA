// Majority Element II [> n/3 times]
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: check each element and count its occurrences.
// Time Complexity: O(n^2) - for each element, we count occurrences in O(n).
// Space Complexity: O(1) - no extra space used.
// Steps:
// 1) Loop through each index i as a potential majority element candidate.
// 2) For each element at index i, count how many times it appears in the entire array.
// 3) If count is greater than n/3, it's a majority element.
// 4) To avoid duplicates in result, check if element is already in answer before adding.
// 5) Continue until all elements are checked and return the result.
vector<int> majorityElementBruteforce(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    // Step 1: Loop through each index to check if it's a potential majority element
    for (int i = 0; i < n; i++) {
        int count = 0;
        // Step 2: Count occurrences of current element in entire array
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        // Step 3: Check if count exceeds n/3 threshold
        if (count > n / 3) {
            // Step 4: To avoid duplicates in result
            if (ans.empty() || ans.back() != nums[i]) {
                ans.push_back(nums[i]);
            }
        }
    }
    // Step 5: Return all elements appearing more than n/3 times
    return ans;
}

// Better Approach: Use a hash map to count occurrences of each element.
// Time Complexity: O(n) - we traverse the array once to count occurrences.
// Space Complexity: O(n) - in the worst case, all elements are unique and stored in the map.
// Steps:
// 1) Create a hash map to store frequency of each element.
// 2) Traverse the array once and increment count for each element in the map.
// 3) After each increment, check if count exceeds n/3 threshold.
// 4) If threshold exceeded and element not already in result, add to result.
// 5) Return the list of all majority elements found.
vector<int> majorityElementBetter(vector<int>& nums) {
    vector<int> ans;
    unordered_map<int, int> countMap;
    int n = nums.size();
    
    // Step 1-2: Traverse array and count occurrences using hash map
    for (int num : nums) {
        countMap[num]++; // Increment frequency of current element
        
        // Step 3-4: Check if current count exceeds n/3 threshold
        // If threshold exceeded and not already in result, add it
        if (countMap[num] > n / 3) {
            if (ans.empty() || ans.back() != num) {
                ans.push_back(num);
            }
        }
    }
    
    // Step 5: Return all elements appearing more than n/3 times
    return ans;
}

// Optimal Approach: Boyer-Moore Voting Algorithm for n/3 majority.
// Time Complexity: O(n) - we traverse the array exactly twice.
// Space Complexity: O(1) - we only use a few variables to track candidates and counts.
// Steps:
// 1) Mathematical insight: at most 2 elements can appear more than n/3 times.
// 2) First pass - find potential candidates using voting algorithm logic.
//    Maintain two candidates (el1, el2) and their counts (cnt1, cnt2).
// 3) If current element matches candidate, increment its count.
// 4) If both counts are positive, decrement both (cancellation logic).
// 5) Second pass - validate candidates by counting actual occurrences.
// 6) Return only those candidates with count > n/3 (meeting threshold).
vector<int> majorityElementOptimal(vector<int>& nums) {
    // Size of the array
    int n = nums.size(); 

    // Counts for elements el1 and el2
    int cnt1 = 0, cnt2 = 0;
    
    // Initialize candidate elements with INT_MIN (no real element)
    int el1 = INT_MIN, el2 = INT_MIN;

    // Step 1-4: First pass - find potential candidates using Boyer Moore's algorithm
    for (int i = 0; i < n; i++) {
        
        // If cnt1 is 0 and current element is not el2, initialize el1
        if (cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            el1 = nums[i];
        }
        // If cnt2 is 0 and current element is not el1, initialize el2
        else if (cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i];
        }
        // If current element matches el1, increment its count
        else if (nums[i] == el1) {
            cnt1++;
        }
        // If current element matches el2, increment its count
        else if (nums[i] == el2) {
            cnt2++;
        }
        // If current element doesn't match either candidate, decrement both counts
        else {
            cnt1--;
            cnt2--;
        }
    }
    // Step 5: Second pass - validate candidates by counting their actual occurrences
    // Reset counts for verification
    cnt1 = 0, cnt2 = 0;
    
    for (int i = 0; i < n; i++) {
        // Count actual occurrences of el1
        if (nums[i] == el1) {
            cnt1++;
        }
        // Count actual occurrences of el2
        if (nums[i] == el2) {
            cnt2++;
        }
    }

    // Step 6: Determine minimum count required to be a majority element
    int mini = n / 3 + 1;
    
    // List to store final answers
    vector<int> result;

    // Add el1 if it appears more than n/3 times
    if (cnt1 >= mini) {
        result.push_back(el1);
    }
    // Add el2 if it appears more than n/3 times and is different from el1
    if (cnt2 >= mini && el1 != el2) {
        result.push_back(el2);
    }

    // Return the majority elements that meet the threshold
    return result;
}

int main() {
    // Sample input: array with elements appearing > n/3 times
    vector<int> nums = {3, 2, 3};
    
    // --- BRUTE FORCE APPROACH ---
    // Uncomment the lines below to run brute force approach.
    // Checks all elements O(n^2) time, but O(1) space.
    // vector<int> resultBrute = majorityElementBruteforce(nums);
    // cout << "Brute Force Result: ";
    // for (int num : resultBrute) {
    //     cout << num << " ";
    // }
    // cout << endl;

    // --- BETTER APPROACH ---
    // Uncomment the lines below to run better approach.
    // Uses hash map for O(n) time and O(n) space.
    // vector<int> resultBetter = majorityElementBetter(nums);
    // cout << "Better Result: ";
    // for (int num : resultBetter) {
    //     cout << num << " ";
    // }
    // cout << endl;

    // --- OPTIMAL APPROACH ---
    // Running optimal approach by default.
    // Uses Boyer-Moore voting for O(n) time and O(1) space.
    vector<int> result = majorityElementOptimal(nums);
    cout << "Optimal Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
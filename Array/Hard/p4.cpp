// 3 Sum : Given an integer array nums
// return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// The solution set must not contain duplicate triplets.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute Force Approach: Check all possible triplets and count their occurrences.
// Time Complexity: O(n^3) - three nested loops to check all triplets. and O(log n) for sorting the triplet before adding to result.
// Space Complexity: O(1) - no extra space used.
// Steps:
// 1) Use three nested loops to generate all possible triplets (i, j, k) where i < j < k.
// 2) For each triplet, check if their sum is zero.
// 3) If sum is zero, sort the triplet to maintain order and check if it's already in result to avoid duplicates.
// 4) If not a duplicate, add the triplet to the result list.
vector<vector<int>> threeSumBruteforce(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    
    // Step 1: Generate all possible triplets using three nested loops
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                // Step 2: Check if the sum of the triplet is zero
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    // Step 3: Sort the triplet to maintain order and check for duplicates
                    sort(triplet.begin(), triplet.end());
                    if (ans.empty() || find(ans.begin(), ans.end(), triplet) == ans.end()) {
                        ans.push_back(triplet); // Step 4: Add to result if not a duplicate
                    }
                }
            }
        }
    }
    return ans; // Return all unique triplets that sum to zero
}


// Better Approach: Use a hash map to count occurrences of each element and find pairs.
// Time Complexity: O(n^2) - two nested loops to find pairs and O(log n) for sorting the triplet before adding to result.
// Space Complexity: O(n) - in the worst case, all elements are unique and stored in the map.
// Steps:
// 1) Create a hash map to store frequency of each element.
// 2) Use two nested loops to fix the first two elements of the triplet and calculate the required third element to sum to zero.
// 3) Check if the required third element exists in the hash map and is not one of the fixed elements.
// 4) If a valid triplet is found, sort it and check for duplicates before adding to the result list.
vector<vector<int>> threeSumBetter(vector<int>& nums) {
    vector<vector<int>> ans;
    unordered_map<int, int> countMap;
    int n = nums.size();
    
    // Step 1: Count occurrences of each element using a hash map
    for (int num : nums) {
        countMap[num]++;
    }
    
    // Step 2: Use two nested loops to fix the first two elements of the triplet
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int required = -(nums[i] + nums[j]); // Calculate required third element
            
            // Step 3: Check if the required third element exists in the hash map and is not one of the fixed elements
            if (countMap.find(required) != countMap.end()) {
                // Ensure the required element is not one of the fixed elements or has enough occurrences
                if ((required == nums[i] && countMap[required] > 1) ||
                    (required == nums[j] && countMap[required] > 1) ||
                    (required != nums[i] && required != nums[j])) {
                    
                    vector<int> triplet = {nums[i], nums[j], required};
                    // Step 4: Sort the triplet and check for duplicates before adding to result
                    sort(triplet.begin(), triplet.end());
                    if (ans.empty() || find(ans.begin(), ans.end(), triplet) == ans.end()) {
                        ans.push_back(triplet); // Add to result if not a duplicate
                    }
                }
            }
        }
    }
    return ans; // Return all unique triplets that sum to zero
}


// Optimized Approach: Sort the array and use two pointers to find triplets.
// Time Complexity: O(n^2) - sorting takes O(n log n) and two nested loops with two pointers take O(n^2).
// Space Complexity: O(1) - no extra space used apart from the result list.
// Steps:
// 1) Sort the input array to facilitate two-pointer technique and duplicate handling.
// 2) Use a loop to fix the first element of the triplet and then use two pointers to find pairs that sum to the negative of the fixed element.
// 3) Move the left pointer forward and right pointer backward based on the sum compared to the target.
// 4) Skip duplicate elements to avoid duplicate triplets in the result.   
vector<vector<int>> threeSumOptimized(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    
    // Step 1: Sort the array to facilitate two-pointer technique
    sort(nums.begin(), nums.end());
    
    // Step 2: Loop to fix the first element of the triplet
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate elements for the first element
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        int left = i + 1; // Left pointer
        int right = n - 1; // Right pointer
        
        // Step 3: Use two pointers to find pairs that sum to -nums[i]
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if ( sum < 0) {
                left++; // Move left pointer forward to increase sum
            } else if (sum > 0) {
                right--; // Move right pointer backward to decrease sum
            } else {
                ans.push_back({nums[i], nums[left], nums[right]}); // Found a triplet
                left++; // Move left pointer forward
                right--; // Move right pointer backward

                // Step 4: Skip duplicate elements for the second and third elements
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
            }
        }
    }
    return ans; // Return all unique triplets that sum to zero
}

int main() {
    // Sample input: array with multiple triplets summing to zero
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    // --- BRUTE FORCE APPROACH ---
    // Uncomment the lines below to run brute force approach.
    // Checks all triplets O(n^3) time, but O(1) space.
    // vector<vector<int>> resultBrute = threeSumBruteforce(nums);
    // cout << "Brute Force Result: ";
    // for (const auto& triplet : resultBrute) {
    //     cout << "[";
    //     for (int num : triplet) {
    //         cout << num << " ";
    //     }
    //     cout << "]";
    // }
    // cout << endl;

    // --- BETTER APPROACH ---
    // Uncomment the lines below to run better approach.
    // Uses hash map for O(n^2) time and O(n) space.
    // vector<vector<int>> resultBetter = threeSumBetter(nums);
    // cout << "Better Result: ";
    // for (const auto& triplet : resultBetter) {
    //     cout << "[";
    //     for (int num : triplet) {
    //         cout << num << " ";
    //     }
    //     cout << "]";
    // }
    // cout << endl;

    // --- OPTIMAL APPROACH ---
    // Running optimal approach by default.
    // Uses sorting and two pointers for O(n^2) time and O(1) space.
    vector<vector<int>> resultOptimized = threeSumOptimized(nums);
    cout << "Optimized Result: ";
    for (const auto& triplet : resultOptimized) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]";
    }
    cout << endl;
    
    return 0;
}
// 4 sum : Given an array of integers, 
// return all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n  
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute Force Approach: Check all possible quadruplets and count their occurrences.
// Time Complexity: O(n^4) - four nested loops to check all quadruplets. and O(log n) for sorting the quadruplet before adding to result.
// Space Complexity: O(1) - no extra space used.
// Steps:
// 1) Use four nested loops to generate all possible quadruplets (i, j, k, l) where i < j < k < l.
// 2) For each quadruplet, check if their sum is equal to the target.
// 3) If sum is equal to target, sort the quadruplet to maintain order and check if it's already in result to avoid duplicates.
// 4) If not a duplicate, add the quadruplet to the result list.
vector<vector<int>> fourSumBruteforce(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    
    // Step 1: Generate all possible quadruplets using four nested loops
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            for (int k = j + 1; k < n - 1; k++) {
                for (int l = k + 1; l < n; l++) {
                    // Step 2: Check if the sum of the quadruplet is equal to target
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        vector<int> quadruplet = {nums[i], nums[j], nums[k], nums[l]};
                        // Step 3: Sort the quadruplet to maintain order and check for duplicates
                        sort(quadruplet.begin(), quadruplet.end());
                        if (ans.empty() || find(ans.begin(), ans.end(), quadruplet) == ans.end()) {
                            ans.push_back(quadruplet); // Step 4: Add to result if not a duplicate
                        }
                    }
                }
            }
        }
    }
    return ans; // Return all unique quadruplets that sum to target
}

// Better Approach: Use a hash map to count occurrences of each element and find pairs.
// Time Complexity: O(n^3) - three nested loops to find triplets and O(log n) for sorting the quadruplet before adding to result.
// Space Complexity: O(n) - in the worst case, all elements are unique and stored in the map.
// Steps:
// 1) Create a hash map to store frequency of each element.
// 2) Use three nested loops to fix the first three elements of the quadruplet and calculate the required fourth element to sum to target.
// 3) Check if the required fourth element exists in the hash map and is not one of the fixed elements.
// 4) If a valid quadruplet is found, sort it and check for duplicates before adding to the result list.
vector<vector<int>> fourSumBetter(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    unordered_map<int, int> countMap;
    int n = nums.size();
    
    // Step 1: Count occurrences of each element using a hash map
    for (int num : nums) {
        countMap[num]++;
    }
    
    // Step 2: Use three nested loops to fix the first three elements of the quadruplet
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int required = target - (nums[i] + nums[j] + nums[k]); // Calculate required fourth element
            
                // Step 3: Check if the required fourth element exists in the hash map and is not one of the fixed elements
                if (countMap.find(required) != countMap.end()) {
                    // Ensure the required element is not one of the fixed elements or has enough occurrences
                    if ((required == nums[i] && countMap[required] > 1) ||
                        (required == nums[j] && countMap[required] > 1) ||
                        (required == nums[k] && countMap[required] > 1) ||
                        (required != nums[i] && required != nums[j] && required != nums[k])) {
                        
                        vector<int> quadruplet = {nums[i], nums[j], nums[k], required};
                        // Step 4: Sort the quadruplet and check for duplicates before adding to result
                        sort(quadruplet.begin(), quadruplet.end());
                        if (ans.empty() || find(ans.begin(), ans.end(), quadruplet) == ans.end()) {
                            ans.push_back(quadruplet); // Add to result if not a duplicate
                        }
                    }
                }
            }
        }
    }
    return ans; // Return all unique quadruplets that sum to target
}

// Optimized Approach: Sort the array and use two pointers to find quadruplets.
// Time Complexity: O(n^3) — two nested loops plus two-pointer scan.
// Space Complexity: O(1) extra (excluding output).
// Steps:
// 1) Sort the array so we can skip duplicates easily.
// 2) Fix two indices i and j, then use two pointers k and l to find remaining pair.
// 3) Skip duplicate values for i, j, k, l to ensure unique quadruplets.
vector<vector<int>> fourSumOptimized(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    if (n < 4) return ans;

    // Step 1: Sort the array to enable two-pointer scanning and easy duplicate skipping
    sort(nums.begin(), nums.end());

    // Step 2: Fix first element 'i' and avoid duplicates for 'i'
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

        // Step 3: Fix second element 'j' for the current 'i' and avoid duplicates for 'j'
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicate j

            // Step 4: Initialize two pointers k (left) and l (right) to find remaining pair
            int k = j + 1;
            int l = n - 1;

            // Step 5: Scan with two pointers while k < l
            while (k < l) {
                // Step 5.1: Compute the sum of current quadruplet (use long long to avoid overflow)
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                sum += nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                // Step 5.2: If exact match, record the quadruplet and move pointers while skipping duplicates
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    // Move left pointer to look for next unique value
                    k++;
                    // Skip duplicates for 'k' to ensure unique quadruplets
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    // Move right pointer inward and skip duplicates for 'l'
                    while (k < l && nums[l] == nums[l - 1]) l--;
                }
                // Step 5.3: If current sum is smaller than target, move left pointer to increase sum
                else if (sum < target) {
                    k++;
                }
                // Step 5.4: If current sum is larger than target, move right pointer to decrease sum
                else {
                    l--;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    // Sample input and target
    // You can run any one of the three approaches below. By default the optimized
    // approach is active. To test other approaches, uncomment their calls.

    // --- BRUTE FORCE APPROACH ---
    // Very slow: O(n^4). Useful only for small arrays or correctness checks.
    // Uncomment to run brute force solution.
    // vector<vector<int>> result = fourSumBruteforce(nums, target);

    // --- BETTER APPROACH ---
    // Uses hashmap + triple loop: O(n^3) with extra space O(n).
    // Uncomment to run the better solution.
    // vector<vector<int>> result = fourSumBetter(nums, target);

    // --- OPTIMIZED APPROACH (DEFAULT) ---
    // Sort + two pointers: O(n^3) time but faster in practice due to skipping duplicates.
    vector<vector<int>> result = fourSumOptimized(nums, target);

    // Print the resulting unique quadruplets
    cout << "Unique quadruplets that sum to " << target << " are:" << endl;
    for (const auto& quad : result) {
        cout << "[";
        for (size_t i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
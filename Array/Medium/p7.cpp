// Next Permutation: Find next lexicographical permutation of the given array
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n! * n) - generate all permutations and find the next one
// Space Complexity: O(n) - space for storing permutations
// Steps:
// 1) Generate all possible permutations of the array.
// 2) Store them in sorted order (lexicographically).
// 3) Find the current permutation and return the next one.
// Note: This approach is not implemented due to exponential complexity, but the concept is:
// Generate all n! permutations, sort them, find current one, return next.

// Better Approach: Use C++ built-in next_permutation function
// Time Complexity: O(n) - single pass with optimal algorithm
// Space Complexity: O(1) - modify array in place
// Steps:
// 1) The next_permutation function handles all the logic internally.
// 2) It rearranges elements to the next lexicographically greater permutation.
// 3) Returns true if next permutation exists, false if current is the last permutation.
class BetterSolution {
public:
    // 1) Call the built-in next_permutation function
    void nextPermutationBetter(vector<int>& nums) {
        // 1a) next_permutation modifies nums in-place to the next lexicographic permutation
        next_permutation(nums.begin(), nums.end());
    }
};

// Optimal Approach: Two-pointer technique with reversal
// Time Complexity: O(n) - single pass through array
// Space Complexity: O(1) - modify array in place
// Steps:
// 1) Find the rightmost position i where nums[i] < nums[i+1] (break point).
// 2) If no such position exists, current is the last permutation -> reverse entire array.
// 3) Find the rightmost position j (to the right of i) where nums[j] > nums[i].
// 4) Swap nums[i] and nums[j].
// 5) Reverse the suffix starting from nums[i+1].
class OptimalSolution {
public:
    void nextPermutationOptimal(vector<int>& nums) {
        int n = nums.size();
        
        // 1) Find the rightmost index i where nums[i] < nums[i+1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--; // move left until we find a position where nums[i] < nums[i+1]
        }
        
        // 2) If found a valid position (i >= 0)
        if (i >= 0) {
            // 3) Find the rightmost index j where nums[j] > nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--; // move left until we find nums[j] > nums[i]
            }
            // 4) Swap nums[i] and nums[j] to get a larger permutation
            swap(nums[i], nums[j]);
        }
        // 5) Reverse the suffix from i+1 to end to get the smallest permutation greater than current
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    // Test array: {1, 3, 2}
    // Current: {1, 3, 2}, Next should be: {2, 1, 3}
    vector<int> nums = {1, 3, 2};
    
    // Uncomment one of the following approaches to test:
    
    // BetterSolution sol1;
    // sol1.nextPermutationBetter(nums);  // Better: O(n) time, O(1) space, uses built-in function
    
    OptimalSolution sol;
    sol.nextPermutationOptimal(nums); // Optimal: O(n) time, O(1) space, manual two-pointer approach
    
    // Print the next permutation
    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
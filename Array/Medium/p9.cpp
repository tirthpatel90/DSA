//longest consecutive sequence in array
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

// Brute force approach: iterate through each element and check for consecutive sequence by using linear search
// Time Complexity: O(n^2), Space Complexity: O(1)
// Steps:
// 1) For each element in the array assume it as the start of a sequence.
// 2) Use a linear search to check whether the next consecutive number exists.
// 3) Keep incrementing the current number and count while consecutive numbers are found.
// 4) Track the maximum sequence length observed across all starts and return it.
// Helper: linearSearch performs a simple linear scan to check if target exists in nums.
int linearSearch(vector<int>& nums, int target) {
    for (int num : nums) {
        if (num == target) {
            return true; // found the target
        }
    }
    return false; // target not found
}

int longestConsecutiveBruteForce(vector<int>& nums) {
    int longestStreak = 0;
    int n = nums.size();

    // 1) Try every element as the start of a potential consecutive sequence
    for (int i = 0; i < n; i++) {
        int currentNum = nums[i];
        int count = 1; // current sequence length starts at 1 (the element itself)

        // 2-3) Continue checking next consecutive numbers using linear search
        while (linearSearch(nums, currentNum + 1)) {
            currentNum++; // move to next number in sequence
            count++;      // increment length for each found consecutive number
        }

        // 4) Update global max streak if this start produced a longer sequence
        longestStreak = max(longestStreak, count);
    }
    // Return the longest consecutive sequence length found
    return longestStreak;
}

//Better approach: Sort the array and then iterate through it to find the longest consecutive sequence
//Time Complexity: O(n log n), Space Complexity: O(1)
// Steps:
// 1) Base condition: if array is empty, return 0.
// 2) Sort the array so that consecutive numbers come together.
// 3) Iterate through the array. Maintain 'lastsmallest' to verify if the next number is consecutive.
// 4) If current element is exactly 1 greater than 'lastsmallest', increment the streak.
// 5) If current element is not a duplicate, reset the streak and update 'lastsmallest'.
// 6) Keep track of the maximum streak reached so far.

int longestConsecutiveBetter(vector<int>& nums) {
    // Step 1: Base condition check
    if (nums.empty()) return 0;
    int n = nums.size();
    
    // Step 2: Sort the elements to group consecutive sequences
    sort(nums.begin(), nums.end());
    
    // Step 3: Initialize streak counters and a variable to remember the last valid number
    int longestStreak = 1;
    int currentStreak = 1;
    int lastsmallest = INT_MIN;

    // Iterate through the array to calculate streaks
    for(int i = 0; i < n - 1; i++){
        // Step 4: Current number is exactly next in sequence
        if(nums[i] - 1 == lastsmallest){
            currentStreak++;
            lastsmallest = nums[i];
        }
        // Step 5: Current number is not consecutive and not a duplicate
        else if(nums[i] != lastsmallest){ // To handle duplicates
            currentStreak = 1; // Reset for new sequence
            lastsmallest = nums[i];
        }
        // Step 6: Update the optimal longest streak
        longestStreak = max(longestStreak, currentStreak);
    }
    // Return the max streak (check at the end just in case)
    return max(longestStreak, currentStreak); 
}

//optimal approach: Use a hash set to store the elements and then check for the longest consecutive sequence
//Time Complexity: O(n), Space Complexity: O(n)
// Steps:
// 1) First handle edge cases like an empty array.
// 2) Store all array elements in a hash set to allow O(1) lookups.
// 3) Go through each element in the set.
// 4) Check if the current element is the start of a sequence (i.e. element - 1 is NOT in the set).
// 5) If it is a starting point, count all consecutive following elements (+1) present in the set.
// 6) Track and return the maximum length found for any such sequence.
int longestConsecutive(vector<int>& a) {
        int n = a.size();
        // If the array is empty
        if (n == 0) return 0; 
    
        // Initialize the longest sequence length
        int longest = 1; 
        unordered_set<int> st;
    
        // Put all the array elements into the set
        for (int i = 0; i < n; i++) {
            st.insert(a[i]);
        }
    
        /* Traverse the set to 
           find the longest sequence  */
        for (auto it : st) {
            // Check if 'it' is a starting number of a sequence
            if (st.find(it - 1) == st.end()) {
                // Initialize the count of the current sequence
                int cnt = 1; 
                // Starting element of the sequence
                int x = it; 
    
                // Find consecutive numbers in the set
                while (st.find(x + 1) != st.end()) {
                    // Move to the next element in the sequence
                    x = x + 1; 
                    // Increment the count of the sequence
                    cnt = cnt + 1; 
                }
                // Update the longest sequence length
                longest = max(longest, cnt);
            }
        }
        return longest;
}

int main() {
    // Sample input array for testing
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    // --- BRUTE FORCE APPROACH ---
    // Uncomment these lines to run the Brute Force Approach
    // int longestStreakBF = longestConsecutiveBruteForce(nums);
    // cout << "Longest Consecutive Sequence (Brute Force): " << longestStreakBF << endl;

    // --- BETTER APPROACH ---
    // Uncomment these lines to run the Better Approach
    // int longestStreakBetter = longestConsecutiveBetter(nums);
    // cout << "Longest Consecutive Sequence (Better): " << longestStreakBetter << endl;

    // --- OPTIMAL APPROACH ---
    // Running the Optimal test case by default
    int longestStreakOpt = longestConsecutive(nums);
    cout << "Longest Consecutive Sequence (Optimal): " << longestStreakOpt << endl;
    return 0;
}
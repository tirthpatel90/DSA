//leaders in an array are those elements which are greater than all the elements to their right side.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//Brute Force: Check each element against all elements to its right
//Time Complexity: O(n^2), Space Complexity: O(n)
vector<int> leadersBruteForce(vector<int>& nums) {
    vector<int> leaders;
    int n = nums.size();

    // Step 1: Iterate through each element in the array
    for (int i = 0; i < n; i++) {
        bool isLeader = true; // Assume current element is a leader

        // Step 2: Compare current element with all elements to its right
        for (int j = i + 1; j < n; j++) {
            if (nums[i] <= nums[j]) {
                isLeader = false; // Found an element to the right that is greater or equal
                break; // No need to check further
            }
        }

        // Step 3: If current element is a leader, add it to the result list
        if (isLeader) {
            leaders.push_back(nums[i]);
        }
    }
    return leaders;
}

//Optimal: Traverse from right to left, keep track of the maximum element seen so far
//Time Complexity: O(n), Space Complexity: O(n)
vector<int> leadersOptimal(vector<int>& nums) {
    vector<int> leaders;
    int n = nums.size();
    int maxFromRight = INT_MIN; // Initialize to smallest integer

    // Step 1: Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Step 2: If current element is greater than maxFromRight, it is a leader
        if (nums[i] > maxFromRight) {
            leaders.push_back(nums[i]); // Add leader to the list
            maxFromRight = nums[i]; // Update maxFromRight to current element
        }
    }
    reverse(leaders.begin(), leaders.end()); // Reverse to maintain original order
    return leaders;
}

int main() {
    vector<int> nums = {16, 17, 4, 3, 5, 2};

    // Test Brute Force Approach
    // vector<int> leadersBF = leadersBruteForce(nums);
    // cout << "Leaders (Brute Force): ";
    // for (int leader : leadersBF) {
    //     cout << leader << " ";
    // }
    // cout << endl;

    // Test Optimal Approach
    vector<int> leadersOpt = leadersOptimal(nums);
    cout << "Leaders (Optimal): ";
    for (int leader : leadersOpt) {
        cout << leader << " ";
    }
    cout << endl;

    return 0;
}
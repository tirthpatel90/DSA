// MAXIMUM Consecutive Ones
#include <bits/stdc++.h>
using namespace std;

//Optimal: we can use a single pass to count the maximum number of consecutive ones in the array.
//time: O(n), space: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        // Step 1: Initialize counter for current streak of consecutive 1s
        int cnt = 0;
        // Step 2: Initialize variable to store maximum streak found so far
        int maxi = 0;

        // Step 3: Traverse all elements in the array one by one
        for (int i = 0; i < nums.size(); i++) {
            // Step 4: If current element is 1, extend current consecutive streak
            if (nums[i] == 1) {
                cnt++;
            } else {
                // Step 5: If current element is 0, reset current streak count to 0
                cnt = 0;
            }

            // Step 6: Update maximum streak if current streak is larger
            maxi = max(maxi, cnt);
        }

        // Step 7: Return the maximum number of consecutive 1s
        return maxi;
    }
};

int main() {
    // Step 1: Create a vector of integers to represent the input array
    vector<int> nums = {1, 0, 1, 1, 0, 1};

    // Step 2: Create an instance of the Solution class
    Solution sol;

    // Step 3: Call the findMaxConsecutiveOnes function with the input array and store the result
    int result = sol.findMaxConsecutiveOnes(nums);

    // Step 4: Print the result to the console
    cout << "Maximum number of consecutive ones: " << result << endl;

    // Step 5: Return 0 to indicate successful program execution
    return 0;
}
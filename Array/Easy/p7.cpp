// Move all zeros to the end of the array
#include <bits/stdc++.h>
using namespace std;
//brute force: store non-zero elements in temp array and then copy back to original array
//time: O(n), space: O(n)

void moveZeroesBruteForce(vector<int>& nums) {
    // Step 1: Get the size of the array
    int n = nums.size();
    // Step 2: If array is empty, return early
    if (n == 0) return;

    // Step 3: Create a temporary array to store all non-zero elements
    vector<int> temp;
    // Step 4: Iterate through the original array
    for (int i = 0; i < n; i++) {
        // Step 5: Check if current element is non-zero
        if (nums[i] != 0) {
            // Step 6: Add non-zero element to temporary array
            temp.push_back(nums[i]);
        }
    }
    // Step 7: Copy all non-zero elements from temp array back to original array
    for (int i = 0; i < temp.size(); i++) {
        // Step 8: Place each non-zero element at the beginning of original array
        nums[i] = temp[i];
    }
    // Step 9: Store the count of non-zero elements
    int nonezero = temp.size();
    // Step 10: Fill the remaining positions with zeros
    for (int i = nonezero; i < n; i++) {
        // Step 11: Set each remaining position to zero
        nums[i] = 0;
    }
}

//optimal: use two pointers, one for iterating through the array and another for keeping track of the position of the next non-zero element
//time: O(n), space: O(1)
void moveZeroesOptimal(vector<int>& nums) {
    // Step 1: Initialize pointer j to -1 (will store position of first zero)
    int j = -1;
    // Step 2: Get the size of the array
    int n = nums.size();
    // Step 3: If array is empty, return early
    if (n == 0) return;
    
    // Step 4: Find the position of the first zero element
    for (int i = 0; i< n; i++) {
        // Step 5: Check if current element is zero
        if (nums[i] == 0) {
            // Step 6: Store the position of first zero in j
            int j = i;
            // Step 7: Exit loop once first zero is found
            break;
        }
    }
    // Step 8: If no zero found (j is still -1), array is already arranged, return
    if (j == -1) return;
    
    // Step 9: Iterate from the position after first zero to the end
    for (int i = j + 1; i < n; i++) {
        // Step 10: Check if current element is non-zero
        if (nums[i] != 0) {
            // Step 11: Swap the non-zero element with the zero at position j
            swap(nums[i], nums[j]);
            // Step 12: Move pointer j to the next position for future swaps
            j++;
        }
    }
}

int main() {
    // Step 1: Create a test array with zeros and non-zero elements
    vector<int> nums = {0, 1, 0, 3, 12};

    // Step 2: Call the optimal function to move all zeros to the end
    // Note: You can switch to moveZeroesBruteForce() to compare approaches
    moveZeroesOptimal(nums);

    // Step 3: Print the modified array after moving zeros
    for (int num : nums) {
        // Step 4: Output each element followed by a space
        cout << num << " ";
    }
    // Step 5: Print newline to complete the output
    cout << endl;

    // Step 6: Return 0 to indicate successful program execution
    return 0;
}
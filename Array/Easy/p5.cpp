// LEFT ROTATE AN ARRAY BY one position
#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: STORED IN A NEW ARRAY
// TIME: O(n), SPACE: O(n)
void solve(int arr[], int n) {
    int temp[n];  // Create a temporary array to store the shifted elements

    // Shift the elements to the left by one position
    for (int i = 1; i < n; i++) {
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = arr[0];  // The first element moves to the last position

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";  // Print each element of the rotated array
    }
    cout << endl;
}

// OPTIMAL: IN-PLACE ROTATION
// TIME: O(n), SPACE: O(1)
void rotateArrayByOne(vector<int>& nums) {
        // Store the first element in a temporary variable
        int temp = nums[0];
        
        // Shift elements to the left
        for (int i = 1; i < nums.size(); ++i) {
            nums[i - 1] = nums[i];
        }

        // Place the first element at the end
        nums[nums.size() - 1] = temp;
    }

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    // Change this function name to switch between brute force and optimal.
    rotateArrayByOne(nums);

    // Print the rotated array
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
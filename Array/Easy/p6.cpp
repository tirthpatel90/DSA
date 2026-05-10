//ROTATE ARRAY BY K POSITIONS
#include <bits/stdc++.h>
using namespace std;

//brute force: store first k elements in a temp array, shift the rest to the left, then copy back the temp elements to the end
//time: O(n+k), space: O(k)
void rotateBruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;

        // Normalize k if greater than n
        k = k % n;
        //it is for left rotation, for right rotation we can do k = n - (k % n);
        // Store first k elements in temporary array
        int temp[k];
        for (int i = 0; i < k; i++) {
            temp[i] = nums[i];
        }
        //it is for left rotation, for right rotation we can store last k elements in temp array
        // for (int i = 0; i < k; i++) {
        //     temp[i] = nums[n - k + i];
        // Shift remaining elements to the left by k positions
        for (int i = k; i < n; i++) {
            nums[i - k] = nums[i];
        }
        //this is for left rotation, for right rotation we can shift remaining elements to the right by k positions
        // for (int i = n - k - 1; i >= 0; i--) {
        //     nums[i + k] = nums[i];
        // Copy back the stored elements to the end
        for (int i = 0; i < k; i++) {
            nums[n - k + i] = temp[i];
        }
} 

//optimal:reverse first k elements, then reverse the rest, then reverse the whole array
//time: O(2n), space: O(1)
void rotateOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;

    k = k % n;  // Normalize k
    
    // Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);//this is for left rotation, for right rotation we can reverse last k elements
    // reverse(nums.end() - k, nums.end());

    // Reverse the remaining elements
    reverse(nums.begin() + k, nums.end());//this is for left rotation, for right rotation we can reverse first n-k elements
    // reverse(nums.begin(), nums.end() - k);

    // Reverse the entire array
    reverse(nums.begin(), nums.end());//this is for left rotation, for right rotation we can reverse the entire array as well
}
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;

    // Change this function name to switch between brute force and optimal.
    rotateOptimal(nums, k);

    // Print the rotated array
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
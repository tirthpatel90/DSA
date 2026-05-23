// Maximum Product Subarray
// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product. 
// The test cases are generated so that the answer will fit in a 32-bit integer.
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach : iterate through all possible subarrays and calculate their products, keeping track of the maximum product found.
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// steps:
// 1. Initialize a variable maxProduct to store the maximum product found, and set it to the smallest possible integer value.
// 2. Use two nested loops to generate all possible subarrays of the input array.
// 3. For each subarray, calculate the product of its elements.
// 4. If the calculated product is greater than maxProduct, update maxProduct.
// 5. After checking all subarrays, return maxProduct as the result.
int maxProductBruteForce(vector<int>& nums) {
    int maxProduct = INT_MIN; // Initialize to the smallest possible integer value
    int n = nums.size();

    // Generate all possible subarrays using two nested loops
    for (int i = 0; i < n; i++) {
        // Start a new subarray beginning at index i
        // `product` holds the product of the current subarray nums[i..j]
        int product = 1; // Initialize product for the current subarray
        for (int j = i; j < n; j++) {
            // Extend the subarray to include nums[j]
            // Multiply the running product by the new element
            product *= nums[j]; // product now equals product(nums[i] * ... * nums[j])

            // Compare with the global maximum and update if needed
            // This handles positive and negative products correctly because
            // we check the raw product value each time we extend the window.
            maxProduct = max(maxProduct, product); // Update maxProduct if the current product is greater
        }
    }
    return maxProduct; // Return the maximum product found
}

// Optimal Approach : use a single pass through the prefix products while keeping track of the maximum and minimum products at each step, since a negative number can turn a minimum product into a maximum product.
// Time Complexity: O(N)
// Space Complexity: O(1)
// steps:
// 1. Initialize three variables: maxProduct to store the maximum product found, minProduct to store the minimum product found, and result to store the final maximum product result. Set maxProduct and minProduct to the first element of the array, and result to the same value.
// 2. Iterate through the array starting from the second element.
// 3. For each element, if it is negative, swap maxProduct and minProduct because a negative number can turn a maximum product into a minimum product and vice versa.
// 4. Update maxProduct to be the maximum of the current element and the product of maxProduct and the current element. Similarly, update minProduct to be the minimum of the current element and the product of minProduct and the current element.
// 5. Update result to be the maximum of result and maxProduct.
// 6. After iterating through the array, return result as the maximum product of a contiguous subarray.
int maxProductOptimal(vector<int>& nums) {
    int maxProduct = nums[0]; // Initialize maxProduct to the first element
    int minProduct = nums[0]; // Initialize minProduct to the first element
    int result = nums[0];     // Initialize result to the first element

    // Iterate through the array starting from the second element
    for (int i = 1; i < nums.size(); i++) {
        // When current element is negative, multiplying it with the current
        // `maxProduct` will make it small (possibly become minimum), and
        // multiplying it with `minProduct` (which may be negative) can produce
        // a large positive number. To account for this, swap the roles
        // of maxProduct and minProduct before updating.
        if (nums[i] < 0) {
            swap(maxProduct, minProduct); // Swap max and min if current element is negative
        }

        // Either start a new subarray at nums[i] or extend the previous
        // subarray by multiplying with the running max/min products.
        // We compute both because the sign of nums[i] can flip which one
        // becomes the maximum.
        maxProduct = max(nums[i], maxProduct * nums[i]); // Update maxProduct
        minProduct = min(nums[i], minProduct * nums[i]); // Update minProduct

        // The result is the maximum `maxProduct` seen so far across the array
        result = max(result, maxProduct); // Update result with the maximum product found so far
    }
    return result; // Return the maximum product of a contiguous subarray
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    // --- Brute Force Run ---
    // The brute force function checks every contiguous subarray and computes
    // their products in O(n^2). It's useful as a correctness baseline for
    // small inputs or for testing the optimal implementation.
    cout << "Maximum Product Subarray (Brute Force): " << maxProductBruteForce(nums) << endl;

    // --- Optimal Run ---
    // The optimal function runs in O(n) time by maintaining both the maximum
    // and minimum products ending at the current position. A negative number
    // can swap max/min, so we handle that case explicitly. Note that this
    // implementation does not modify the input array.
    cout << "Maximum Product Subarray (Optimal): " << maxProductOptimal(nums) << endl;
    return 0;
}

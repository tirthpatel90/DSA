// Next Greater Element Problem
// Idea:
// For each element, we need the next element to its right which is greater than it.
// If no such element exists, the answer is -1.

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Brute force approach:
// Check every element to the right of the current index.
// Time Complexity: O(n^2)
// Space Complexity: O(n)
vector<int> nextGreaterBruteForce(vector<int> nums) {
    int n = nums.size();
    vector<int> result(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i]) {
                result[i] = nums[j];
                break;
            }
        }
    }

    return result;
}

// Optimized approach using a monotonic decreasing stack:
// Traverse from right to left.
// Keep a stack of indices whose values are potential next greater elements.
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> nextGreaterOptimized(vector<int> nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        // Remove smaller or equal elements from the stack.
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }

        // If a greater element exists, it is on top of the stack.
        if (!st.empty()) {
            result[i] = nums[st.top()];
        }

        // Push current index for future comparisons.
        st.push(i);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid size." << endl;
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Input array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> optimized = nextGreaterOptimized(nums);

    cout << "\nOptimized result: ";
    for (int x : optimized) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

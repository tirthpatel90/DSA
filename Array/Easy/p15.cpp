// Length of the longest subarray with zero Sum
// Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Brute force: using loops to find the longest subarray with sum 0
//time: O(n^3), space: O(1)
int longestSubarrayBruteForce(int A[], int n) {
    int maxi = 0;

    // Step 1: Iterate through all possible starting points of subarrays
    for (int i = 0; i < n; i++) {
        // Step 2: Iterate through all possible ending points of subarrays
        for (int j = i; j < n; j++) {
            int sum = 0;
            // Step 3: Calculate the sum of the current subarray from i to j
            for (int k = i; k <= j; k++) {
                sum += A[k];
            }
            // Step 4: If the sum equals 0, update the maximum length
            if (sum == 0) {
                maxi = max(maxi, j - i + 1);
            }
        }
    }
    return maxi;
}

//optimal: using hash map to store the cumulative sum and its first index, and then check if the same prefix sum appears again.
//time: O(n), space: O(n)
int longestSubarrayOptimal(int A[], int n) {
  // Step 1: map prefix sum -> first index seen
  unordered_map<int, int> mpp;
  // Step 2: store the best length so far
  int maxi = 0;
  // Step 3: keep a running prefix sum
  int sum = 0;

  // Step 4: iterate over the array
  for (int i = 0; i < n; i++) {
    // Step 5: update running sum
    sum += A[i];

    // Step 6: if sum is zero, subarray [0..i] has zero sum
    if (sum == 0) {
      // Step 7: update best length
      maxi = i + 1;
    }
    // Step 8: otherwise check if this sum was seen before
    else {
      // Step 9: when seen, zero-sum segment lies between previous index + 1 and i
      if (mpp.find(sum) != mpp.end()) {
        // Step 10: maximize length
        maxi = max(maxi, i - mpp[sum]);
      }
      // Step 11: first time seeing this sum
      else {
        // Step 12: record index
        mpp[sum] = i;
      }
    }
  }

  // return best length
  return maxi;
}  

int main() {
    vector<int> arr = {1, -1, 5, -2, 3};

  cout << "Brute Force: " << longestSubarrayBruteForce(arr.data(), arr.size()) << endl;
    cout << "Optimal: " << longestSubarrayOptimal(arr.data(), arr.size()) << endl;

    return 0;
}
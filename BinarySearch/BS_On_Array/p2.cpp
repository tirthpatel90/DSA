// Lower Bound
// Given a sorted array of N integers and an integer x, find the lower bound of x in the array. The lower bound of x is the index of the first element in the array which is not less than x. If all elements in the array are less than x, then the lower bound is N (the size of the array). 
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach to find the lower bound
// Time complexity: O(N)
// Space complexity: O(1)
// Steps:
// 1) Scan elements from left to right.
// 2) For each index, check if arr[i] is greater than or equal to x.
// 3) The first such index is the lower bound, return it immediately.
// 4) If no such index exists, return N (array size).
int lowerBoundBruteForce(const vector<int>& arr, int x) {
    // Step 1: Linear scan from beginning of the array
    for (size_t i = 0; i < arr.size(); ++i) {
        // Step 2: Check first element that is not less than x
        if (arr[i] >= x) {
            return i; // Step 3: Found lower bound index
        }
    }
    // Step 4: If all elements are less than x, lower bound is N
    return arr.size();
}

// Binary search approach to find the lower bound
// Time complexity: O(log N)
// Space complexity: O(1)
// Steps:
// 1) Initialize low and high to represent current search range.
// 2) Compute mid for each iteration.
// 3) If arr[mid] is greater than or equal to x, lower bound can be at mid or left side.
// 4) Otherwise, lower bound must lie strictly on the right side.
// 5) Continue until low and high meet.
// 6) Return low as the lower-bound index.
int lowerBoundBinarySearch(const vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;

    // Step 1-5: Shrink search range using binary-search decisions
    while (low < high) {
        // Step 2: Middle index of the current range
        int mid = low + (high - low) / 2;

        // Step 3: mid can still be the answer, so keep left side including mid
        if (arr[mid] >= x) {
            high = mid; // Move the high pointer to mid
        } else {
            // Step 4: mid is too small, so move to right side
            low = mid + 1;
        }
    }

    // Step 6: low is the lower-bound index
    return low;
}

// Using STL lower_bound function to find the lower bound
// Time complexity: O(log N)
// Space complexity: O(1)
// int lowerBoundSTL(const vector<int>& arr, int x) {
//     auto it = lower_bound(arr.begin(), arr.end(), x);
//     return distance(arr.begin(), it); // Return the index of the lower bound
// }

int main() {
    // Sample sorted array and target value
    vector<int> arr = {1, 3, 5, 7, 9};
    int x = 4;

    // --- BRUTE FORCE APPROACH ---
    // Run this to find lower bound using linear scan.
    int lowerBoundBF = lowerBoundBruteForce(arr, x);
    cout << "Lower bound (brute force): " << lowerBoundBF << endl;

    // --- BINARY SEARCH APPROACH (BETTER) ---
    // Run this to find lower bound in O(log N).
    int lowerBoundBS = lowerBoundBinarySearch(arr, x);
    cout << "Lower bound (binary search): " << lowerBoundBS << endl;

    return 0;
}
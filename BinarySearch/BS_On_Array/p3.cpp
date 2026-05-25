// Upper Bound
// Given a sorted array of N integers and an integer x, find the upper bound of x in the array. The upper bound of x is the index of the first element in the array which is greater than x. If all elements in the array are less than or equal to x, then the upper bound is N (the size of the array).
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach to find the upper bound
// Time complexity: O(N)
// Space complexity: O(1)
// Steps:
// 1) Start from index 0 and scan elements one by one.
// 2) For each element, check whether it is strictly greater than x.
// 3) The first such index is the upper bound, so return it immediately.
// 4) If no element is greater than x, return N (array size).
int upperBoundBruteForce(const vector<int>& arr, int x) {
    // Step 1: Linear scan from left to right
    for (size_t i = 0; i < arr.size(); ++i) {
        // Step 2: Check for first element strictly greater than x
        if (arr[i] > x) {
            return i; // Step 3: First valid index is the upper bound
        }
    }
    // Step 4: If not found, upper bound is N
    return arr.size();
}

// Binary search approach to find the upper bound
// Time complexity: O(log N)
// Space complexity: O(1)
// Steps:
// 1) Use two pointers low and high to represent current search range.
// 2) Compute mid in each iteration.
// 3) If arr[mid] is greater than x, upper bound may be at mid or on left side, so move high to mid.
// 4) Otherwise, upper bound must be on right side, so move low to mid + 1.
// 5) Continue until low and high meet.
// 6) Return low as computed upper-bound index.
int upperBoundBinarySearch(const vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;

    // Step 1-5: Shrink search range using binary-search decisions
    while (low < high) {
        // Step 2: Middle index of current range
        int mid = low + (high - low) / 2;

        // Step 3: mid qualifies (> x), so keep left half including mid
        if (arr[mid] > x) {
            high = mid;
        } else {
            // Step 4: mid does not qualify (<= x), so move to right half
            low = mid + 1;
        }
    }

    // Step 6: low is the resulting upper-bound index
    return low;
}

// Using STL upper_bound function to find the upper bound
// Time complexity: O(log N)
// Space complexity: O(1)
// int upperBoundSTL(const vector<int>& arr, int x) {
//     auto it = upper_bound(arr.begin(), arr.end(), x);
//     return distance(arr.begin(), it); // Return the index of the upper bound
// }

int main() {
    // Sample sorted array and query value
    vector<int> arr = {1, 3, 5, 7, 9};
    int x = 4;

    // --- BRUTE FORCE APPROACH ---
    // Run this to find upper bound using linear scan.
    int upperBoundBF = upperBoundBruteForce(arr, x);
    cout << "Upper bound (brute force): " << upperBoundBF << endl;

    // --- BINARY SEARCH APPROACH (BETTER) ---
    // Run this to find upper bound using O(log N) binary search.
    int upperBoundBS = upperBoundBinarySearch(arr, x);
    cout << "Upper bound (binary search): " << upperBoundBS << endl;

    return 0;
}
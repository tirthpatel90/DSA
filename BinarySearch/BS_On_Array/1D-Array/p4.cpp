// Search Insert Position
// You are given a sorted array arr of distinct values and a target value x.
// Return the index if the target is found. If not, return the index where it would be if it were inserted in order.
#include <iostream>
#include <vector>
using namespace std;

// Binary Search approach to find the insert position (same as lower bound)
// Time complexity: O(log N)
// Space complexity: O(1)
// Steps:
// 1) Initialize two pointers: low at start and high at end of array.
// 2) Find mid index in each iteration.
// 3) If arr[mid] >= x, answer can be at mid or left side, so move high to mid.
// 4) If arr[mid] < x, answer must be on right side, so move low to mid + 1.
// 5) Continue until low and high converge.
// 6) Return low as the insert position.
int searchInsertBinarysearch(const vector<int>& arr, int x) {
    if (arr.empty()) return 0;

    int low = 0;
    int high = arr.size() - 1;

    // Continue shrinking search space; low will become the lower-bound index
    while (low <= high) {
        // Mid index of current search range
        int mid = low + (high - low) / 2;

        // If mid value is big enough, answer can still be at mid or left side
        if (arr[mid] >= x) {
            high = mid - 1;
        } else {
            // Otherwise, answer lies strictly on the right side
            low = mid + 1;
        }
    }

    // low now points to the insert position (can be arr.size())
    return low;
}

int main() {
    // Sample sorted input array
    vector<int> arr = {1, 3, 5, 6};
    // Target value to search/insert
    int x = 7;

    // This file currently contains only the binary-search solution.
    // Run this approach to get the target index if present,
    // or the correct insert position if target is absent.
    int insertPosition = searchInsertBinarysearch(arr, x);

    // Print final answer
    cout << "Insert position: " << insertPosition << endl;

    return 0;
}
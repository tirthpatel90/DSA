// Kth Missing Positive Number
#include <iostream>
#include <vector>
using namespace std;

// Brute force approch: Check each positive integer starting from 1 and count how many are missing until we find the k-th missing.
// Time complexity: O(n) in the worst case if k is small compared to the largest number in the array.
// Space complexity: O(1)
// Steps:
// 1) Walk the array left-to-right comparing each value with current `k`.
// 2) If vec[i] <= k, it means the array contains a number that would otherwise be missing,
//    so increment `k` to shift our target missing value to the right.
// 3) When we encounter vec[i] > k, we've located the k-th missing positive: return `k`.

int findKthPositiveBruteForce(const vector<int>& vec, int k, int n) {
    for (int i = 0; i < n; i++) {
        // If current array value is <= k, it 'consumes' one missing slot,
        // so the target missing value shifts right by 1.
        if (vec[i] <= k) {
            k++;  // Move the target missing number forward
        } else {
            // vec[i] > k indicates k is missing from the array and is the answer.
            break; // Stop when we reach a number greater than k
        }
    }
    return k;  // Return the final value of k which is the missing number
}

// Optimal approach: Use binary search to find the k-th missing positive number efficiently.
// Time complexity: O(log n) where n is the size of the input array.
// Space complexity: O(1)
// Steps:
// 1) For index `mid`, missingCount = vec[mid] - (mid+1) gives how many numbers are missing before vec[mid].
// 2) If missingCount < k, the k-th missing is to the right; set low = mid+1.
// 3) Otherwise move left to find the earliest index where missingCount >= k.
// 4) After the loop, answer is `low + k`.
int findKthPositiveBinarySearch(const vector<int>& vec, int k, int n) {
    int low = 0; // Start of the array
    int high = n - 1; // End of the array

    while (low <= high) {
        int mid = low + (high - low) / 2; // Midpoint index
        // Number of missing positives before index mid:
        // e.g., if vec[mid]=5 and mid=1 (second element), missingCount = 5 - (1+1) = 3
        int missingCount = vec[mid] - (mid + 1); // Count of missing numbers up to mid

        if (missingCount < k) {
            // Not enough missing numbers yet — search right half
            low = mid + 1; // Move right if we haven't found enough missing numbers
        } else {
            // Enough (or too many) missing numbers — search left half for earliest position
            high = mid - 1; // Move left if we have found too many missing numbers
        }
    }
    return low + k; // The k-th missing number is at position low + k
}

int main() {
    vector<int> vec = {2, 3, 4, 7, 11};
    int k = 5;
    int n = vec.size();

    cout << "Brute Force: " << findKthPositiveBruteForce(vec, k, n) << endl;
    cout << "Binary Search: " << findKthPositiveBinarySearch(vec, k, n) << endl;

    return 0;
}

// --- SUGGESTED TESTS ---
// 1) vec = {2,3,4,7,11}, k = 5 -> expected 9
// 2) vec = {1,2,3,4}, k = 2 -> expected 6 (no missing before end)
// 3) vec = {2}, k = 1 -> expected 1
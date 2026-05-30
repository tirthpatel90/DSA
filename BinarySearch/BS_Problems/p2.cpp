// Find Nth Root of a Number
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach: try all possible values from 0 to x and check if their nth power equals x.
// Time complexity: O(x^(1/n)) in worst case when n is small and x is large.
// Space complexity: O(1)
// Steps:
// 1) Handle invalid inputs (even root of negative number) and trivial x==0.
// 2) Iterate candidate `i` from 1 upward and compute i^n.
// 3) If i^n == x return i; if it exceeds x break early.
// 4) If no integer root found return -1.

int nthRootBruteForce(int x, int n) {
    if (x < 0 && n % 2 == 0) {
        throw invalid_argument("Even root of a negative number is not real.");
    }
    if (x == 0) return 0; // The nth root of 0 is always 0
    for (int i = 1; i <= x; ++i) {
        // Compute i^n carefully to avoid overflow for large i and n.
        long long power = 1;
        for (int j = 0; j < n; ++j) {
            power *= i; // Multiply by i each iteration to get i^n
            // If power exceeds x we can stop early to save work.
            if (power > x) break;
        }
        // Step: compare computed power with x.
        if (power == x) {
            return i; // Found the exact integer nth root
        } else if (power > x) {
            // Overshot: further `i` will only increase power, so break.
            break; // No need to continue if power exceeds x
        }
        // Otherwise continue trying next i
    }
    return -1; // Return -1 if no integer nth root exists
}

// Optimal approach: Use binary search to find the nth root efficiently.
// Time complexity: O(log x) since we are halving the search space in each step
// Space complexity: O(1)
// Steps:
// 1) Handle invalid inputs and trivial x==0.
// 2) Maintain search window [low, high] and check mid^n each iteration.
// 3) If mid^n == x return mid; if < x move right; if > x move left.
// 4) Return -1 if not found.
int nthRootBinarySearch(int x, int n) {
    if (x < 0 && n % 2 == 0) {
        throw invalid_argument("Even root of a negative number is not real.");
    }
    if (x == 0) return 0; // The nth root of 0 is always 0

    int low = 1, high = x / n; // The nth root of x cannot exceed x/n for n > 1
    int ans = -1; // To store the last valid candidate
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Compute mid^n; use long long to reduce overflow chance.
        long long power = 1;
        for (int j = 0; j < n; ++j) {
            power *= mid; // Multiply by mid repeatedly to get mid^n
            // Early exit if power grows beyond x to avoid unnecessary work.
            if (power > x) break;
        }
        // Compare computed power with x to decide direction.
        if (power == x) {
            return mid; // Found the exact integer nth root
        } else if (power < x) {
            // mid is too small, search in right half
            low = mid + 1; // Search in the right half
        } else {
            // mid^n is too large, search left half
            high = mid - 1; // Search in the left half
        }
    }
    return ans; // Return the last valid candidate if no exact root found
}

int main() {
    int x = 8; // The number to find the nth root of
    int n = 3;  // The degree of the root

    // --- RUN OPTIONS ---
    // Brute force: simple O(x^(1/n)) scan to find nth root
    cout << "Nth root (Brute Force): " << nthRootBruteForce(x, n) << endl;

    // Binary search: efficient O(log x) approach to find nth root
    cout << "Nth root (Binary Search): " << nthRootBinarySearch(x, n) << endl;

    return 0;
}

// --- SUGGESTED TESTS ---
// 1) x = 0 -> expected 0
// 2) x = 1 -> expected 1
// 3) x = 8, n = 3 -> expected 2 (perfect cube)
// 4) x = 9, n = 2 -> expected 3 (perfect square)
// 5) x = 10, n = 2 -> expected -1 (no integer square root)
// Note: For production code with very large `x`, prefer `long long` inputs and safer overflow checks.
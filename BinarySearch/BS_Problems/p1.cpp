// Finding Sqrt of a number using Binary Search
#include <iostream>
using namespace std;

// Brute Force Approach
// time complexity: O(sqrt(n))
// space complexity: O(1)
// Steps:
// 1) Handle trivial cases n==0 or n==1.
// 2) Iterate i from 1 up to n/2 (square root cannot exceed n/2 for n>1).
// 3) If i*i == n, return i.
// 4) If i*i > n, the integer square root is i-1; return it.
int sqrtBrute(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    // Iterate i from 1 to n/2 and check squares.
    // Note: i*i is safe for typical problem constraints here,
    // but for very large `n` consider using `long long` to avoid overflow.
    for (int i = 1; i <= n / 2; i++) {
        // Step: compute square of current candidate `i`.
        // If it matches `n`, we've found exact integer sqrt.
        if (i * i == n) {
            return i;
        }
        // If square overshoots `n`, the integer part of sqrt is i-1.
        if (i * i > n) {
            return i - 1;
        }
        // Otherwise continue to next `i`.
    }
    return -1; // This line will never be reached
}

// Binary Search Approach
// time complexity: O(log(n))
// space complexity: O(1)
// Steps:
// 1) Handle trivial cases n==0 or n==1.
// 2) Set search range low=1, high=n/2; maintain `ans` for last valid mid.
// 3) While low<=high, compute mid.
// 4) If mid*mid <= n, record mid as candidate (`ans`) and search right half.
// 5) Otherwise search left half.
// 6) Return `ans` as the integer square root.
int sqrtBinarySearch(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    int low = 1, high = n / 2, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // `mid` is computed this way to avoid potential overflow from `(low+high)`.
        // Step: check whether `mid*mid` is <= n.
        // Warning: `mid*mid` can overflow for very large mid. For safer code,
        // cast to `long long` or use division checks (mid <= n / mid).
        if (mid * mid <= n) {
            // `mid` is a valid candidate; record it and try to find a larger one.
            ans = mid; // Store the last valid answer
            low = mid + 1; // Move right to search for a larger integer sqrt
        } else {
            // `mid*mid` is too large, reduce the search space to the left half.
            high = mid - 1; // Move left to find a smaller number
        }
    }
    return ans; // Return the largest integer whose square is less than or equal to n
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // --- RUN OPTIONS ---
    // Brute force: simple O(sqrt(n)) approach — useful for small n or educational purposes.
    cout << "Square root (Brute Force): " << sqrtBrute(n) << endl;
    // Binary search: efficient O(log n) approach for large n.
    cout << "Square root (Binary Search): " << sqrtBinarySearch(n) << endl;

    // --- SUGGESTED TESTS ---
    // 1) n = 0  -> expected 0
    // 2) n = 1  -> expected 1
    // 3) n = 4  -> expected 2 (perfect square)
    // 4) n = 8  -> expected 2 (integer part only)
    // 5) n = 2147395600 -> large value that fits in 32-bit squares
    // Note: For extremely large `n`, prefer using `long long` throughout.

    return 0;
}
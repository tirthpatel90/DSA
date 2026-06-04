// Kth element of two sorted arrays
#include <iostream>
#include <climits>
using namespace std;

// Brute force approach: merge the two arrays and return the k-th element from the merged list.
// In plain words:
// - We create a new array and copy elements from both input arrays into it in sorted order.
// - We stop as soon as we have placed `k` elements into the merged array and return the last one.
// Why this works: the merged array is the sorted union of both arrays, so its k-th element
// (1-based) is the answer. We allocate extra memory to keep the merged elements.
// Time complexity: O(n + m) in the worst case (we may examine every element).
// Space complexity: O(n + m) because we allocate a merged array of size n+m.
// Step-by-step plan:
// 1) Keep two indices `i` and `j` for `arr1` and `arr2` respectively.
// 2) At each step, compare `arr1[i]` and `arr2[j]` and append the smaller to `merged`.
// 3) Increase the appropriate index and the merged `count`. If `count == k`, return that value.
// 4) If one array runs out, keep taking from the other until you reach `k` or both end.
int kthElementBruteForce(int arr1[], int arr2[], int n, int m, int k) {
    int* merged = new int[n + m];
    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        // Compare current elements of both arrays and take the smaller one.
        // This preserves sorted order in `merged`.
        if (arr1[i] < arr2[j]) {
            merged[count++] = arr1[i++];
        } else {
            merged[count++] = arr2[j++];
        }
        // If we've placed k elements into `merged`, the last placed element is the answer.
        if (count == k) {
            int result = merged[count - 1];
            delete[] merged; // Free allocated memory before returning
            return result;
        }
    }
    while (i < n) {
        // If `arr2` is exhausted, copy remaining elements from `arr1` and check k.
        merged[count++] = arr1[i++];
        if (count == k) {
            int result = merged[count - 1];
            delete[] merged; // Free allocated memory before returning
            return result;
        }
    }
    while (j < m) {
        // If `arr1` is exhausted, copy remaining elements from `arr2` and check k.
        merged[count++] = arr2[j++];
        if (count == k) {
            int result = merged[count - 1];
            delete[] merged; // Free allocated memory before returning
            return result;
        }
    }
    delete[] merged; // Clean up allocated memory
    return -1; // If k is out of bounds
}

// Optimal approach (easy-language): walk through both arrays as if they were merged,
// but do not actually build the merged array. Use two pointers and count how many
// elements you've seen so far. When you reach the k-th element, return it.
// Why this helps: we avoid allocating extra memory, and we stop as soon as we find k.
// Time complexity: O(k) in the worst case, because we may advance k steps total.
// Space complexity: O(1) because we only use a few integer variables.
// Step-by-step plan:
// 1) Keep indices `i` and `j` for `arr1` and `arr2`, and `count` for how many elements we've seen.
// 2) While both arrays have elements, compare arr1[i] and arr2[j], take the smaller, increment count.
// 3) If count becomes k, return that value immediately. If one array runs out, continue with the other.
int kthElementOptimal(int arr1[], int arr2[], int n, int m, int k) {
    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        // Compare the current elements and take the smaller one as if merging.
        if (arr1[i] < arr2[j]) {
            count++;
            // If this is the k-th element we've seen, return it.
            if (count == k) return arr1[i];
            i++;
        } else {
            count++;
            if (count == k) return arr2[j];
            j++;
        }
    }
    while (i < n) {
        // If `arr2` is exhausted, continue advancing `arr1` and checking count.
        count++;
        if (count == k) return arr1[i];
        i++;
    }
    while (j < m) {
        // If `arr1` is exhausted, continue advancing `arr2` and checking count.
        count++;
        if (count == k) return arr2[j];
        j++;
    }
    return -1; // If k is out of bounds
}

// Optimal approach (advanced): Use binary search to find the k-th element without merging.
// Time complexity: O(log(min(n, m))) because we perform binary search on the smaller array.
// Space complexity: O(1) because we only use a few integer variables.
// Steps:
// 1) We want to find the k-th element in the merged array. We can think of it as finding how many elements from `arr1` and `arr2` we take to reach k.
// 2) We can use binary search on the smaller array to guess how many elements we take from it (let's say `i`), and then we take `k - i` from the other array.
// 3) We check if `arr1[i-1] <= arr2[k-i-1]` and `arr2[k-i-1] <= arr1[i-1]` to ensure we have the correct partition. If not, we adjust our guess `i` accordingly.
int kthElementBinarySearch(int arr1[], int arr2[], int n, int m, int k) {
    // Quick note: this method finds the k-th element in the merged sorted order
    // without actually merging the arrays. It binary-searches how many elements
    // to take from the smaller array (arr1) and derives the rest from arr2.

    // Ensure we binary-search on the smaller array for logarithmic cost.
    if (n > m) {
        return kthElementBinarySearch(arr2, arr1, m, n, k);
    }

    // lower bound: at least max(0, k-m) elements must come from arr1 because arr2
    // can contribute at most m elements. Example: if k > m, you must take at least k-m from arr1.
    int low = max(0, k - m);
    // upper bound: at most min(k, n) elements can come from arr1 (can't take more than n).
    int high = min(k, n);

    // Binary search for the correct split: choose i elements from arr1, j=k-i from arr2.
    while (low <= high) {
        int i = low + (high - low) / 2; // candidate count from arr1
        int j = k - i;                   // rest come from arr2

        // left and right neighbours around the partition:
        // left1 = last chosen element from arr1, right1 = first not chosen from arr1
        // left2/right2 analogously for arr2.
        int left1 = (i == 0) ? INT_MIN : arr1[i - 1];
        int right1 = (i == n) ? INT_MAX : arr1[i];
        int left2 = (j == 0) ? INT_MIN : arr2[j - 1];
        int right2 = (j == m) ? INT_MAX : arr2[j];

        // If left1 <= right2 and left2 <= right1, the partition is correct:
        // all elements in the left parts are <= all elements in the right parts.
        if (left1 <= right2 && left2 <= right1) {
            // The k-th element (1-based) is the maximum of the two left-side maxima.
            return max(left1, left2);
        }

        // If left1 > right2, we have taken too many from arr1 — move left.
        if (left1 > right2) {
            high = i - 1;
        } else {
            // Otherwise left2 > right1, we have taken too few from arr1 — move right.
            low = i + 1;
        }
    }

    return -1; // should not happen for valid k
}

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = 5;
    // --- RUN OPTIONS ---
    // You can run either the brute force or the optimal function. Both should return the same result.
    cout << "Optimal (two-pointer) result: " << kthElementOptimal(arr1, arr2, n, m, k) << endl;
    cout << "Brute force (merge) result: " << kthElementBruteForce(arr1, arr2, n, m, k) << endl;
    cout << "Binary search result: " << kthElementBinarySearch(arr1, arr2, n, m, k) << endl;

    // --- DRY RUN for k = 5 (easy explanation) ---
    // arr1: 2, 3, 6, 7, 9
    // arr2: 1, 4, 8, 10
    // We walk through both arrays in order (like merging) and count elements:
    // 1) take 1 (from arr2) -> count = 1
    // 2) take 2 (from arr1) -> count = 2
    // 3) take 3 (from arr1) -> count = 3
    // 4) take 4 (from arr2) -> count = 4
    // 5) take 6 (from arr1) -> count = 5 -> this is the 5th element, answer = 6
    // So both functions should print 6.
    return 0;
}
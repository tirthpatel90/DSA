// Merge Two Sorted Arrays Without Extra Space
#include <bits/stdc++.h>
using namespace std;

// There are no brute force or better approaches for this problem as we are required to solve it in O(1) extra space.
// We can solve it by 2 optimized approaches:

// Optimized Approach 1: Compare elements from arr1 end with arr2 start and swap if needed, then sort both arrays.
// Time Complexity: O((n+m) log(n+m)) - due to sorting both arrays after potential swaps.
// Space Complexity: O(1) - no extra space used.
// Steps:
// 1) Initialize two pointers, one at the end of arr1 and another at the start of arr2.
// 2) Compare elements at these pointers and swap if the element in arr1 is greater than the element in arr2.
// 3) Move the pointers accordingly and repeat until all elements are compared.
// 4) Finally, sort both arrays to ensure they are in the correct order.
void mergeOptimized1(long long arr1[], long long arr2[], int n, int m) {
    int i = n - 1; // Pointer for arr1
    int j = 0;     // Pointer for arr2

    // Step 1: Compare elements from arr1 end with arr2 start and swap if needed
    while (i >= 0 && j < m) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        } else {
            break; // Since arrays are sorted, no need to continue if arr1[i] <= arr2[j]
        }
    }

    // Step 2: Sort both arrays to ensure they are in the correct order
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// Optimized Approach 2: Use the Gap method (Shell Sort inspired) to compare and swap elements at a certain gap.
// Time Complexity: O((n+m) log(n+m)) - due to the nature of the gap method which reduces the number of comparisons and swaps.
// Space Complexity: O(1) - no extra space used.
// Steps:
// 1) Calculate the initial gap using the formula: gap = ceil((n + m) / 2).
// 2) Compare elements at the current gap and swap if needed.
// 3) Reduce the gap and repeat the process until the gap becomes 1.
int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

void mergeOptimized2(long long arr1[], long long arr2[], int n, int m) {
    int gap = ((n + m) / 2) + ((n + m) % 2); // Initial gap calculation using modulo to handle odd lengths

    while (gap > 0) {
        int i = 0;
        int j = gap;

        while (j < n + m) {
            if (j < n && i < n) {
                // Both pointers are within arr1
                if (arr1[i] > arr1[j]) {
                    swap(arr1[i], arr1[j]);
                }
            } else if (j >= n && i < n) {
                // i is in arr1, j is in arr2
                if (arr1[i] > arr2[j - n]) {
                    swap(arr1[i], arr2[j - n]);
                }
            } else {
                // Both pointers are in arr2
                if (arr2[i - n] > arr2[j - n]) {
                    swap(arr2[i - n], arr2[j - n]);
                }
            }
            i++;
            j++;
        }
        gap = nextGap(gap); // Reduce the gap; stop after processing gap = 1
    }
}

int main() {
    long long arr1[] = {1, 5, 9, 10, 15, 20};
    long long arr2[] = {2, 3, 8, 13};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    // You can test either of the optimized approaches by uncommenting the respective function call.

    // --- OPTIMIZED APPROACH 1 ---
    // mergeOptimized1(arr1, arr2, n, m);

    // --- OPTIMIZED APPROACH 2 ---
    mergeOptimized2(arr1, arr2, n, m);

    cout << "Merged arr1: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\nMerged arr2: ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
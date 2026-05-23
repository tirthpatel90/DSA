// Count Inversions in an array
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach : iterate through all pairs of elements and count the number of inversions.
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// steps:
// 1. Initialize a variable count to store the number of inversions.
// 2. Run two nested loops to compare each pair of elements.
// 3. If arr[i] > arr[j] and i < j, increment the count.
// 4. Return the count. 
int countInversionsBruteForce(vector<int>& arr) {
    int count = 0;
    int n = arr.size();
    // Outer loop picks the first element of the pair (i)
    for (int i = 0; i < n; i++) {
        // Inner loop picks the second element of the pair (j) such that j > i
        for (int j = i + 1; j < n; j++) {
            // If a pair (i, j) forms an inversion (arr[i] > arr[j])
            // increment the inversion count
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

// Optimal Approach : Use Merge Sort to count inversions while sorting the array.
// Time Complexity: O(N log N) 
// Space Complexity: O(N) due to the temporary arrays used in merge sort.
// steps:
// 1. Implement a modified merge sort algorithm that counts inversions during the merge step.
// 2. During the merge step, if an element from the right subarray is smaller than an element from the left subarray
//    then all remaining elements in the left subarray will also be greater than the current element from the right subarray, contributing to the inversion count.
// 3. Return the total count of inversions after the merge sort is complete.
// 4. The merge sort will sort the array in place while counting the inversions.
// 5. The final count of inversions will be returned at the end of the merge sort process.
int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    // Create temporary vectors for left and right subarrays
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    // i -> index for leftArr, j -> index for rightArr, k -> merged array index
    int i = 0, j = 0, k = left, count = 0;

    // Merge the two sorted halves while counting cross inversions
    while (i < leftArr.size() && j < rightArr.size()) {
        // If left element is smaller or equal, it does not form an inversion
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            // If rightArr[j] < leftArr[i], then all remaining elements
            // in leftArr starting from i are greater than rightArr[j]
            // which contributes (leftArr.size() - i) inversions
            arr[k++] = rightArr[j++];
            count += (leftArr.size() - i); // Count inversions
        }
    }

    // Copy any remaining elements from leftArr (if any)
    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }

    // Copy any remaining elements from rightArr (if any)
    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }

    // Return number of inversions found during this merge
    return count;
}
int mergeSortAndCount(vector<int>& arr, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Recursively count inversions in left half
        count += mergeSortAndCount(arr, left, mid);
        // Recursively count inversions in right half
        count += mergeSortAndCount(arr, mid + 1, right);
        // Count inversions while merging the two halves
        count += mergeAndCount(arr, left, mid, right);
    }
    return count;
}
int countInversionsOptimal(vector<int>& arr) {
    // Wrapper that calls the modified merge sort over the full array
    // Note: this will sort the array as a side-effect while counting inversions
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {1, 20, 6, 4, 5};
    
    // Example input array

    // --- Brute Force Run ---
    // The brute force function iterates over all pairs (i, j) with i < j
    // and counts inversions directly. Use this to validate correctness
    // for small arrays (Time: O(N^2)).
    int inversionsBruteForce = countInversionsBruteForce(arr);
    cout << "Number of inversions (Brute Force): " << inversionsBruteForce << endl;

    // --- Optimal Run (Merge Sort) ---
    // The optimal function uses a modified merge sort to count inversions
    // while sorting the array. This runs in O(N log N) time and is
    // preferred for larger inputs. Note that the array will be modified
    // (sorted) as a side-effect of this call.
    int inversionsOptimal = countInversionsOptimal(arr);
    cout << "Number of inversions (Optimal): " << inversionsOptimal << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Quick Sort implementation (partition scheme)


class Solution {
public:
    // Function to perform quicksort
    void quickSort(vector<int>& arr, int low, int high) {
        // Base case: if low is not less than high
        if (low < high) {
            // Partition the current subarray and get the final pivot position
            int pivotIndex = partition(arr, low, high);

            // Recursively sort elements before pivot
            quickSort(arr, low, pivotIndex - 1);

            // Recursively sort elements after pivot
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    // Function to partition the array
    int partition(vector<int>& arr, int low, int high) {
        // Choose the last element as pivot
        int pivot = arr[high];

        // 'i' is the index of the last element known to be <= pivot.
        // We start it at low-1 because we haven't placed any such elements yet.
        int i = low - 1;

        // Traverse the subarray from 'low' to 'high-1' and compare each element with pivot
        for (int j = low; j < high; j++) {
            // If current element is <= pivot, it should go to the left partition
            if (arr[j] <= pivot) {
                // Move the boundary for smaller elements forward
                // and swap current element into the left partition
                i++;
                swap(arr[i], arr[j]);
            }
        }

        // After the loop, all elements <= pivot are before index i.
        // Place pivot right after them so pivot is in its final sorted spot.
        swap(arr[i + 1], arr[high]);

        // Return the pivot index (now correctly positioned)
        return i + 1;
    }
};

int main() {
    // Sample array
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    // Create solution object
    Solution sol;

    // Apply quicksort to the whole array: indices 0..n-1
    sol.quickSort(arr, 0, arr.size() - 1);

    // Print sorted array (space separated)
    for (int num : arr)
        cout << num << " ";
    
    return 0;
}
//avg time complexity: O(n log n) on average, O(n^2) in worst case (when the smallest or largest element is always chosen as pivot)
//best time complexity: O(n log n) when the pivot divides the array into two equal halves consistently.
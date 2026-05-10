#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to merge two sorted halves of the array into one sorted array
    // low: starting index of left half
    // mid: ending index of left half
    // high: ending index of right half
    void merge(vector<int>& arr, int low, int mid, int high) {
        // Create a temporary vector to store the merged sorted elements
        vector<int> temp;
        
        // Initialize two pointers: left pointer for left half, right pointer for right half
        int left = low;      // Points to the start of left half
        int right = mid + 1; // Points to the start of right half

        // Compare elements from both halves and add the smaller one to temp array
        // Continue until one of the halves is exhausted
        while (left <= mid && right <= high) {
            // If left element is smaller or equal, add it to temp and move left pointer forward
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            // If right element is smaller, add it to temp and move right pointer forward
            else
                temp.push_back(arr[right++]);
        }

        // Copy all remaining elements from left half (if any are left)
        // This loop executes if right half was exhausted first
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy all remaining elements from right half (if any are left)
        // This loop executes if left half was exhausted first
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy all sorted elements from temp array back to the original array
        // Update the original array with the merged sorted elements
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low]; // temp[i - low] because temp starts from index 0
    }

    // Recursive function that divides the array and sorts it using merge sort
    // low: starting index of the array/subarray
    // high: ending index of the array/subarray
    void mergeSort(vector<int>& arr, int low, int high) {
        // Base case: if low >= high, array has 0 or 1 element, so it's already sorted
        if (low >= high)
            return;

        // Find the middle index to divide the array into two halves
        int mid = (low + high) / 2;

        // Recursively sort the left half (from low to mid)
        mergeSort(arr, low, mid);

        // Recursively sort the right half (from mid+1 to high)
        mergeSort(arr, mid + 1, high);

        // Merge the two sorted halves into one sorted array
        merge(arr, low, mid, high);
    }
};

int main() {
    // Create an unsorted array with 5 elements
    vector<int> arr = {5, 2, 8, 4, 1};
    
    // Create an instance of Solution class
    Solution sol;
    
    // Call mergeSort function: pass array, starting index (0), and ending index (size-1)
    sol.mergeSort(arr, 0, arr.size() - 1);
    
    // Print the sorted array on a single line with spaces
    for (int x : arr)
        cout << x << " ";
    
    // Print a new line at the end
    cout << endl;
    
    // Return 0 to indicate successful program execution
    return 0;
}
//avg & worst Time Complexity: O(n log n) because we divide the array into halves log n times and merge takes O(n) time.
//best Time Complexity: O(n log n) because merge sort always divides the array and merges it, regardless of the initial order.
//Space Complexity: O(n) because we use a temporary array to store the merged elements.
//sort array of 0s, 1s and 2s without using extra space
#include <iostream>
#include <vector>
using namespace std;

//brute force gonna be O(n log n) due to sorting, space O(n) for storing pairs
// any sorting algorithm can be used, here we will use built-in sort which is typically O(n log n)

//Better: using three counters for 0s, 1s and 2s
//time: O(2n), space: O(1) for counters
void sortZeroOneTwoBetter(vector<int>& arr, int n) {
    // Step 1: Initialize counters for 0s, 1s and 2s
    int count0 = 0, count1 = 0, count2 = 0;

    // Step 2: Traverse the array once and count occurrences of each value
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
        else if (arr[i] == 2) count2++;
    }

    // Step 3: Overwrite the original array using the counts
    // Step 3a: Fill count0 zeros
    int index = 0;
    for (int i = 0; i < count0; i++) arr[index++] = 0;
    // Step 3b: Fill count1 ones
    for (int i = count0; i < count0 + count1; i++) arr[index++] = 1;
    // Step 3c: Fill count2 twos
    for (int i = count0 + count1; i < n ; i++) arr[index++] = 2;
}

//Optimal: using Dutch National Flag algorithm (three pointers)
//time: O(n), space: O(1)
void sortZeroOneTwoOptimal(vector<int>& arr, int n) {
    // Step 1: Initialize three pointers: low (next position for 0),
    // mid (current element under consideration), high (next position for 2)
    int low = 0, mid = 0, high = n - 1;

    // Step 2: Process elements until mid passes high
    while (mid <= high) {
        // Step 3: If current element is 0, swap it to the low region
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            // Step 3a: Expand low region and move mid forward
            low++;
            mid++;
        }
        // Step 4: If current element is 1, it is already in correct region
        else if (arr[mid] == 1) {
            // Step 4a: Simply move mid forward
            mid++;
        }
        // Step 5: If current element is 2, swap it to the high region
        else {
            swap(arr[mid], arr[high]);
            // Step 5a: Shrink high region; do NOT move mid here because swapped-in element needs evaluation
            high--;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 1, 2, 1, 0};
    int n = arr.size();

    // Using Better approach
    sortZeroOneTwoBetter(arr, n);
    cout << "Sorted using Better approach: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Resetting the array for Optimal approach
    arr = {2, 0, 1, 2, 1, 0};

    // Using Optimal approach
    sortZeroOneTwoOptimal(arr, n);
    cout << "Sorted using Optimal approach: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
// //Find the Largest element in an array

//OPTIMIZED APPROACH (TC: O(n) and SC: O(1))
#include <bits/stdc++.h>
using namespace std;

// Function to find the largest element in the array
int findLargestElement(int arr[], int n) {
    int max = arr[0];  // Initialize max with the first element in the array

    // Iterate through the array to find the maximum element
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {  // If the current element is greater than max, update max
            max = arr[i];
        }
    }

    return max;  // Return the largest element found
}

int main() {
    // Array 1
    int arr1[] = {2, 5, 1, 3, 0};
    int n = 5;  // Size of the array
    int max = findLargestElement(arr1, n);  // Call the function to find the largest element
    cout << "The largest element in the array is: " << max << endl;  // Output the result

    // Array 2
    int arr2[] = {8, 10, 5, 7, 9};
    n = 5;  // Size of the array
    max = findLargestElement(arr2, n);  // Call the function to find the largest element
    cout << "The largest element in the array is: " << max << endl;  // Output the result

    return 0;
}

//BRUTE FORCE APPROACH (TC: O(n log n) and SC: O(1))
// #include<bits/stdc++.h>
// using namespace std;

// // Function to sort the array and return the largest element
// int sortArr(vector<int>& arr) {
//     // Sort the array in ascending order
//     sort(arr.begin(), arr.end());
    
//     // Return the last element (largest element) after sorting
//     return arr[arr.size() - 1];
// }

// int main() {
//     // Initialize arrays
//     vector<int> arr1 = {2, 5, 1, 3, 0};
//     vector<int> arr2 = {8, 10, 5, 7, 9};
   
//     // Find and output the largest element in both arrays
//     cout << "The Largest element in the array is: " << sortArr(arr1) << endl;
//     cout << "The Largest element in the array is: " << sortArr(arr2);
   
//     return 0;
// }
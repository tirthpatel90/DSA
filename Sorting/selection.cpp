/*
in selection sort we repeatedly select the smallest element from unsorted part
and put it at the beginning of the unsorted part.
The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
Example: arr[] = {64, 25, 12, 22, 11}
After first pass: arr[] = {11, 25, 12, 22, 64}
After second pass: arr[] = {11, 12, 25, 22, 64}
*/
#include<iostream>
using namespace std;
 void selectionSort(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++) // Traverse through unsorted elements
    {
        // Find the minimum element in unsorted array
        int minIndex = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        //swap(arr[i], arr[minIndex]);
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
//in bubble pushes the largest element to the end of the array in each iteration by comparing adjacent elements and swapping them if they are in the wrong order.
#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) // Traverse through all elements
    {
        // Compare adjacent elements and swap if they are in the wrong order
        //logic 1
        // for (int j = 0; j < n - i - 1; j++) // Last i elements are already in place
        // {
        //     if (arr[j] > arr[j + 1]) {
        //         // Swap arr[j] and arr[j+1]
        //         //swap(arr[j], arr[j + 1]);
        //         int temp = arr[j];
        //         arr[j] = arr[j + 1];
        //         arr[j + 1] = temp;
        //     }
        // }
        //logic 2
        for(int i=n-1; i>=1; i--)// Traverse through all elements
        {
            for(int j=0; j<=i-1; j++)// Last i elements are already in place 
            {
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
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
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
/*
avg & worst Time Complexity: O(n^2) 
best Time Complexity: O(n) when the array is already sorted.
Space Complexity: O(1)
*/  
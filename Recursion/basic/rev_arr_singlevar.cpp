#include<iostream>
using namespace std;
// This function reverses the array in place using recursion using a single variable to keep track of the current index.
void reverseArray(int arr[], int n, int i) {
    if (i >= n / 2) {
        return; // Base case: when the index reaches the middle of the array
    }
    swap(arr[i], arr[n - i - 1]); // Swap the current element with its corresponding element from the end
    reverseArray(arr, n, i + 1); // Recursive call with the next index
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    reverseArray(arr, n, 0); // Call the reverse function starting from index 0
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print the reversed array
    }
    cout << endl;
}
// Time complexity is O(n) and space complexity is O(n) due to recursive call stack.
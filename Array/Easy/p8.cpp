//linear search
#include <bits/stdc++.h>
using namespace std;

int linearsearch(int n, int num, vector<int> &arr) {
    // Step 1: Iterate through each element of the array starting from index 0
    for (int i = 0; i < n; i++) {
        // Step 2: Check if the current element matches the number to search
        if (arr[i] == num) {
            // Step 3: If match found, return the current index immediately
            return i; // Return the index of the found element
        }
    }
    // Step 4: If loop completes without finding the element, return -1 to indicate not found
    return -1; // Return -1 if the element is not found
}
int main() {
    // Step 1: Declare variables to store array size and number to search
    int n, num;
    // Step 2: Prompt user to enter the size of the array
    cout << "Enter the size of the array: ";
    // Step 3: Read the array size from user input
    cin >> n;
    // Step 4: Create a vector of integers with size n
    vector<int> arr(n);
    // Step 5: Prompt user to enter the array elements
    cout << "Enter the elements of the array: ";
    // Step 6: Loop to read n elements from the user
    for (int i = 0; i < n; i++) {
        // Step 7: Read each element and store in the array
        cin >> arr[i];
    }
    // Step 8: Prompt user to enter the number to search
    cout << "Enter the number to search: ";
    // Step 9: Read the number to search from user input
    cin >> num;

    // Step 10: Call the linear search function with array size, search number, and array
    int result = linearsearch(n, num, arr);
    // Step 11: Check if the element was found (result is not -1)
    if (result != -1) {
        // Step 12: If found, display the index where the element was located
        cout << "Element found at index: " << result << endl;
    } else {
        // Step 13: If not found, display a message indicating element not found
        cout << "Element not found in the array." << endl;
    }

    // Step 14: Return 0 to indicate successful program execution
    return 0;
}
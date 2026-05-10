//intersection of two sorted arrays
#include <iostream>
#include <vector>
using namespace std;

// brute force: traverse both arrays and add common elements to result vector and for each common element, skip duplicates in both arrays
// time: O(n*m), space: O(m) for result vector

vector<int> intersectionBruteForce(vector<int>& A, vector<int>& B, int m, int n) {
    // Step 1: Create a result vector to store common elements
    vector<int> result;
    // Step 2: Create a visited array to track which elements in B have already been matched
    int vis[m] = {0}; // All elements initially marked as not visited
    // Step 3: Iterate through all elements in array A
    for (int i = 0; i < m; i++) {
        // Step 4: For each element in A, traverse array B to find matches
        for (int j = 0; j < n; j++) {
            // Step 5: Check if current elements match AND element in B hasn't been visited before
            if (A[i] == B[j] && vis[j] == 0) {
                // Step 6: Add the common element to result vector
                result.push_back(A[i]);
                // Step 7: Mark this element in B as visited to avoid duplicates
                vis[j] = 1;
                // Step 8: Break inner loop to move to next element in A
                break;
            }
            // Step 9: Since arrays are sorted, if B[j] exceeds A[i], no point checking further
            if (B[j] > A[i]) {
                // Step 10: Break to stop searching in B and move to next element in A
                break;
            }
        }
    }
    // Step 11: Return vector containing all intersection elements
    return result;
}

// optimal using two pointers
// time: O(n+m), space: O(1) for result vector

vector<int> intersectionOptimal(vector<int>& A, vector<int>& B, int m, int n) {
    // Step 1: Create a result vector to store common elements
    vector<int> result;
    // Step 2: Initialize two pointers, one for each array
    int i = 0, j = 0;
    // Step 3: Continue comparing while both pointers are within array bounds
    while (i < n && j < m) {
        // Step 4: If element in A is smaller, move pointer i forward
        if (A[i] < B[j]) {
            i++;
        }
        // Step 5: If element in B is smaller, move pointer j forward
        else if (B[j] < A[i]) {
            j++;
        }
        // Step 6: If both elements are equal, we found a common element
        else {
            // Step 7: Add the common element to result
            result.push_back(A[i]);
            // Step 8: Move both pointers forward to continue searching
            i++;
            j++;
        }
    }
    // Step 9: Return vector containing all intersection elements
    return result;
}

int main() {
    // Step 1: Create first sorted array
    vector<int> arr1 = {1, 2, 4, 5, 6};
    // Step 2: Create second sorted array
    vector<int> arr2 = {2, 3, 5, 7};

    // Step 3: Call the optimal function to find intersection of both arrays
    // Note: You can switch to intersectionBruteForce() to compare approaches
    vector<int> result = intersectionOptimal(arr1, arr2, arr1.size(), arr2.size());

    // Step 4: Print the header message
    cout << "Intersection of the two arrays is: ";
    // Step 5: Iterate through all elements in result vector
    for (int num : result) {
        // Step 6: Output each element followed by a space
        cout << num << " ";
    }

    // Step 7: Return 0 to indicate successful program execution
    return 0;
}
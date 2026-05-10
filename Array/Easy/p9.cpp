// UNION of TWO ARRAYS
#include <bits/stdc++.h>
using namespace std;

//brute force: use a set to store unique elements from both arrays
//time: O(n*log(n)+m*log(m)) + O(n+m), space: O(n+m) + O(n+m) for set and result vector
set<int> unionBruteForce(vector<int>& arr1, vector<int>& arr2) {
    // Step 1: Create a set to store unique elements (sets automatically handle duplicates)
    set<int> result;
    // Step 2: Iterate through all elements in first array
    for (int num : arr1) {
        // Step 3: Insert each element from arr1 into the set
        result.insert(num);
    }
    // Step 4: Iterate through all elements in second array
    for (int num : arr2) {
        // Step 5: Insert each element from arr2 into the set (duplicates are automatically ignored)
        result.insert(num);
    }
    // Step 6: Return set containing all unique elements from both arrays
    return result;
}

//optimal: array is already sorted, we can use two pointers to traverse both arrays and add unique elements to the result set
//time: O(n+m), space: O(n+m)

vector<int> unionOptimal(vector<int>& a, vector<int>& b) {
    // Step 1: Create a result vector to store union elements
    vector<int> result;
    // Step 2: Initialize two pointers at the start of both arrays
    int i = 0, j = 0;
    // Step 3: Compare elements from both arrays until one array is exhausted
    while (i < a.size() && j < b.size()) {
        // Step 4: If element in a is smaller than element in b
        if (a[i] < b[j]) {
            // Step 5: Check if result is empty OR last element is different from current element (to avoid duplicates)
            if (result.empty() || result.back() != a[i]) {
                // Step 6: Add the element from a to result
                result.push_back(a[i]);
            }
            // Step 7: Move pointer i forward in array a
            i++;
        } 
        // Step 8: If element in b is smaller or equal to element in a
        else {
            // Step 9: Check if result is empty OR last element is different from current element (to avoid duplicates)
            if (result.empty() || result.back() != b[j]) {
                // Step 10: Add the element from b to result
                result.push_back(b[j]);
            }
            // Step 11: Move pointer j forward in array b
            j++;
        } 
    }
    // Step 12: Add remaining elements from array a (if any elements left)
    while (i < a.size()) {
        // Step 13: Check if result is empty OR last element is different from current element
        if (result.empty() || result.back() != a[i]) {
            // Step 14: Add the remaining element from a to result
            result.push_back(a[i]);
        }
        // Step 15: Move pointer i forward
        i++;
    }
    // Step 16: Add remaining elements from array b (if any elements left)
    while (j < b.size()) {
        // Step 17: Check if result is empty OR last element is different from current element
        if (result.empty() || result.back() != b[j]) {
            // Step 18: Add the remaining element from b to result
            result.push_back(b[j]);
        }
        // Step 19: Move pointer j forward
        j++;
    }
    // Step 20: Return vector containing all unique elements from both arrays
    return result;
}

int main() {
    // Step 1: Create first sorted array with some elements
    vector<int> arr1 = {1, 2, 3, 4};
    // Step 2: Create second sorted array with some overlapping elements
    vector<int> arr2 = {3, 4, 5, 6};

    // Step 3: Call the optimal function to find union of both arrays
    // Note: You can switch to unionBruteForce() to compare approaches
    vector<int> result = unionOptimal(arr1, arr2);

    // Step 4: Print the header message
    cout << "Union of the two arrays is: ";
    // Step 5: Iterate through all elements in result vector
    for (int num : result) {
        // Step 6: Output each element followed by a space
        cout << num << " ";
    }
    // Step 7: Print newline for formatting
    cout << endl;

    // Step 8: Return 0 to indicate successful program execution
    return 0;
}
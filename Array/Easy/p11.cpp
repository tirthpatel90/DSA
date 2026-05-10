//missing value in array
#include <bits/stdc++.h>
using namespace std;

//Brute force: by linearly searching for each number from 1 to n in the array, we can find the missing number.
//time: O(n^2), space: O(1)
int missingNumBruteForce(vector<int>& arr) {
    // Step 1: Iterate from 0 to the size of the array (n), covering all possible numbers
    for (int i = 0; i <= arr.size(); i++) {
        // Step 2: Initialize a flag to track whether the current number is found in the array
        bool found = false;
        // Step 3: Search for the current number (i) in the entire array
        for (int num : arr) {
            // Step 4: Check if the current element matches the number we're searching for
            if (num == i) {
                // Step 5: If found, set the flag to true and break out of inner loop
                found = true;
                break;
            }
        }
        // Step 6: After searching the entire array, check if the number was not found
        if (!found) {
            // Step 7: If not found, this is the missing number, so return it
            return i; // Return the missing number
        }
    }
}

//Better: we can use a hash set to store the elements of the array and then check for the missing number from 0 to n.
//time: O(n), space: O(n)
int missingNumBetter(vector<int> &arr) {
    // Step 1: Calculate the total count of numbers from 1 to n (arr.size() + 1)
    int n = arr.size() + 1;

    // Step 2: Create a hash array of size n+1 initialized with zeros
    vector<int> hash(n + 1, 0);

    // Step 3: Iterate through all elements in the input array
    // Step 4: Store frequencies of each element in the hash array
    for (int i = 0; i < n - 1; i++) {
        // Step 5: Increment the count at the index corresponding to each array element
        hash[arr[i]]++;
    }

    // Step 6: Iterate from 1 to n to find the missing number
    for (int i = 1; i <= n; i++) {
        // Step 7: Check if the frequency of number i is zero (meaning it's missing)
        if (hash[i] == 0) {
            // Step 8: Return the missing number when found
            return i;
        }
    }
    // Step 9: Return -1 if no missing number is found (shouldn't happen in valid input)
    return -1;
}

//Optimal: we can use the formula for the sum of first n natural numbers to find the missing number.
//time: O(n), space: O(1)

int missingNumOptimal(vector<int> &arr) {
    // Step 1: Calculate the total count of numbers (array size + 1 for the missing number)
    int n = arr.size() + 1; // Since one number is missing, the total count should be n+1
    // Step 2: Calculate the sum of first n natural numbers using the formula n*(n+1)/2
    int totalSum = n * (n + 1) / 2; // Sum of first n natural numbers
    // Step 3: Calculate the sum of all elements present in the array
    int arrSum = accumulate(arr.begin(), arr.end(), 0); // Sum of elements in the array
    // Step 4: Subtract the array sum from the total sum to get the missing number
    return totalSum - arrSum; // The difference will give the missing number
}

int main() {
    // Step 1: Create a test array with a missing number
    vector<int> arr = {1, 2, 4, 5}; // Example array with missing number 3
    // Step 2: Call the brute force function and print the result
    cout << "Missing number (Brute Force): " << missingNumBruteForce(arr) << endl;
    // Step 3: Call the better function and print the result
    cout << "Missing number (Better): " << missingNumBetter(arr) << endl;
    // Step 4: Call the optimal function and print the result
    cout << "Missing number (Optimal): " << missingNumOptimal(arr) << endl;
    // Step 5: Return 0 to indicate successful program execution
    return 0;
}
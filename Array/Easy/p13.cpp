// Find number that appears once in an array where every other number appears twice
#include <bits/stdc++.h>
using namespace std;

//Brute force: using counting element than compare with other elements to find the unique element
//time: O(n^2), space: O(1)
int getSingleElementBruteforce(vector<int>& arr) {
        // Step 1: Store the size of the array
        int n = arr.size();

        // Step 2: Iterate through each element and treat it as candidate unique value
        for (int i = 0; i < n; i++) {
            // Step 3: Pick current element as number to check
            int num = arr[i]; // current element to check
            // Step 4: Initialize count for current number
            int cnt = 0;

            // Step 5: Count how many times current number appears in entire array
            for (int j = 0; j < n; j++) {
                if (arr[j] == num)
                    cnt++;
            }

            // Step 6: If current number appears exactly once, return it
            if (cnt == 1) return num;
        }

        // Step 7: Fallback return (for invalid input cases)
        return -1;
}

//Better: we can use a hash to count the frequency of each element and then find the element that appears once.
//time: O(n), space: O(input range) for hash map
int getSingleElementBetter(vector<int>& arr) {
        // Step 1: Store the size of the array
        int n = arr.size();

        // Step 2: Find the maximum value in the array to size the hash array
        int maxi = arr[0];
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
        }

        // Step 3: Create hash array and initialize all frequencies to 0
        vector<int> hash(maxi + 1, 0);

        // Step 4: Count frequency of each value in the input array
        for (int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }

        // Step 5: Traverse array again and return first value with frequency 1
        for (int i = 0; i < n; i++) {
            if (hash[arr[i]] == 1)
                return arr[i];
        }

        // Step 6: Fallback return (for invalid input cases)
        return -1; // fallback, shouldn't occur in valid input
}

//Optimal: we can use the XOR operator to find the unique element in a single pass.
//time: O(n), space: O(1)
int getSingleElementOptimal(vector<int>& arr) {
    // Step 1: Store the size of the array
        int n = arr.size();
    // Step 2: Initialize XOR accumulator with 0
        int ans = 0;

    // Step 3: XOR all elements, duplicate pairs cancel out
        for (int i = 0; i < n; i++) {
            ans = ans ^ arr[i]; // XOR will cancel out pairs and leave the unique element
        }

    // Step 4: Remaining value is the element that appears once
        return ans; // Return the unique element
}

int main() {
    // Step 1: Create a vector of integers to represent the input array
    vector<int> arr = {2, 3, 5, 4, 5, 3, 4};

    // Step 2: Call the optimal function to find the unique element and store the result
    int result = getSingleElementOptimal(arr);

    // Step 3: Print the result to the console
    cout << "The element that appears only once is: " << result << endl;

    // Step 4: Return 0 to indicate successful program execution
    return 0;
}
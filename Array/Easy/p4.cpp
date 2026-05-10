// REMOVE DUPLICATE ELEMENTS FROM A SORTED ARRAY

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: Using a set to store unique elements
// TIME: O(n log n) due to set insertion, SPACE: O(n) for the set
int removeDuplicatesBruteForce(vector<int>& nums) {
    // Step 1: Create a set to store unique elements from the array
    set<int> st;

    // Step 2: Iterate through all elements in the input array
    for (int i = 0; i < (int)nums.size(); i++) {
        // Step 3: Insert each element into the set (duplicates are automatically ignored)
        st.insert(nums[i]);
    }

    // Step 4: Initialize an index variable to track position in the original array
    int index = 0;
    // Step 5: Iterate through all elements in the set (which are in sorted order)
    for (auto it : st) {
        // Step 6: Place the unique element at the current index in the original array
        nums[index] = it;
        // Step 7: Increment the index to move to the next position
        index++;
    }

    // Step 8: Return the count of unique elements (size of the set)
    return (int)st.size();
}

// OPTIMAL: Two-pointer technique
// TIME: O(n), SPACE: O(1)
int removeDuplicatesOptimal(vector<int>& nums) {
    // Step 1: Check if the array is empty and return 0 if true
    if (nums.empty()) {
        return 0;
    }

    // Step 2: Initialize pointer i at the start of the array (index 0)
    int i = 0;
    // Step 3: Initialize pointer j to traverse the array starting from index 1
    for (int j = 1; j < (int)nums.size(); j++) {
        // Step 4: Check if the current element (j) is different from the element at position i
        if (nums[j] != nums[i]) {
            // Step 5: If different, place the new unique element at position i+1
            nums[i + 1] = nums[j];
            // Step 6: Move pointer i forward to the next available position
            i++;
        }
    }

    // Step 7: Return the count of unique elements (i+1, since i points to the last unique element)
    return i + 1;
}

int main() {
    // Step 1: Create a sorted array with duplicate elements
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};

    // Step 2: Call the optimal function to remove duplicates
    // Note: You can switch to removeDuplicatesBruteForce() to compare approaches
    int length = removeDuplicatesOptimal(nums);

    // Step 3: Print the count of unique elements
    cout << length << '\n';
    // Step 4: Iterate through the array up to the count of unique elements
    for (int i = 0; i < length; i++) {
        // Step 5: Print each unique element followed by a space
        cout << nums[i] << ' ';
    }
    // Step 6: Print a newline for formatting
    cout << '\n';

    // Step 7: Return 0 to indicate successful program execution
    return 0;
}
// Find the Repeating and Missing Number
// There are 4 approaches to solve this problem:
// 1) Brute Force Approach: iterate through the array and check each element's count
// 2) Better Approach: Use a hash map to count occurrences of each element and find the repeating and missing numbers.
// 3) Optimal Approach: Use the properties of sum and sum of squares to find the repeating and missing numbers in O(n) time and O(1) space.
// 4) Optimal Approach 2: Use the XOR operation to find the repeating and missing numbers in O(n) time and O(1) space.

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: iterate through the array and check each element's count.
// Steps:
// 1) Iterate through the array and for each number from 1 to n, count its occurrences in the array.
// 2) If a number occurs twice, it is the repeating number. If a number does not occur, it is the missing number.

// Time Complexity: O(n^2) - two nested loops to check each element's count.
// Space Complexity: O(1) - no extra space used.
vector<int> findRepeatingAndMissing(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(2); // result[0] = repeating, result[1] = missing

    // Step 1: Iterate through the array and check each element's count
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                count++;
            }
        }
        // Step 2: If count is 2, we found the repeating number
        if (count == 2) {
            result[0] = i; // repeating number
        }
        // Step 3: If count is 0, we found the missing number
        else if (count == 0) {
            result[1] = i; // missing number
        }
    }
    return result; // Return the repeating and missing numbers
}

// Better Approach: Use a hash map to count occurrences of each element and find the repeating and missing numbers.
// Steps:
// 1) Create a hash map to store frequency of each element.
// 2) Iterate through the numbers from 1 to n and check their counts in the hash map.
// 3) If a number occurs twice, it is the repeating number. If a number does not occur, it is the missing number.

// Time Complexity: O(2n) - single pass to count occurrences and find repeating and missing numbers.
// Space Complexity: O(n) - in the worst case, all elements are unique and stored
// in the map.
vector<int> findRepeatingAndMissingBetter(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(2); // result[0] = repeating, result[1] = missing
    unordered_map<int, int> countMap;

    // Step 1: Count occurrences of each element using a hash map
    for (int num : arr) {
        countMap[num]++;
    }

    // Step 2: Iterate through the numbers from 1 to n and check their counts
    for (int i = 1; i <= n; i++) {
        if (countMap[i] == 2) {
            result[0] = i; // repeating number
        } else if (countMap[i] == 0) {
            result[1] = i; // missing number
        }
    }
    return result; // Return the repeating and missing numbers
}

// Optimal Approach: Use the properties of sum and sum of squares to find the repeating and missing numbers in O(n) time and O(1) space.
// steps:
// 1) Calculate the sum and sum of squares of the elements in the array.
// 2) Calculate the expected sum and sum of squares for numbers from 1 to n.
// 3) Calculate the differences between expected and actual sums.
// 4) Use the differences to find the repeating and missing numbers.
// 5) The missing number can be found using the formula: missing = (sumDifference + squareSumDifference / sumDifference) / 2
// 6) The repeating number can be found using the formula: repeating = missing - sumDifference
// Note: Use long long to avoid integer overflow when calculating sums and squares.

// Time Complexity: O(n) - single pass to calculate sums and find repeating and missing numbers.
// Space Complexity: O(1) - no extra space used.  
vector<int> findRepeatingAndMissingOptimal(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(2); // result[0] = repeating, result[1] = missing

    long long sum = 0; // To store the sum of elements in the array
    long long sumOfSquares = 0; // To store the sum of squares of elements in the array

    // Step 1: Calculate the sum and sum of squares of the elements in the array
    for (int num : arr) {
        sum += num;
        sumOfSquares += (long long)num * num;
    }

    // Step 2: Calculate the expected sum and sum of squares for numbers from 1 to n
    long long expectedSum = (long long)n * (n + 1) / 2; // Sum of first n natural numbers
    long long expectedSumOfSquares = (long long)n * (n + 1) * (2 * n + 1) / 6; // Sum of squares of first n natural numbers

    // Step 3: Calculate the differences between expected and actual sums
    long long sumDifference = expectedSum - sum; // missing - repeating
    long long squareSumDifference = expectedSumOfSquares - sumOfSquares; // missing^2 - repeating^2

    // Step 4: Use the differences to find the repeating and missing numbers
    result[1] = (sumDifference + squareSumDifference / sumDifference) / 2; // missing number
    result[0] = result[1] - sumDifference; // repeating number

    return result; // Return the repeating and missing numbers
}

// Optimal Approach 2: Use the XOR operation to find the repeating and missing numbers in O(n) time and O(1) space.
// Steps:
// 1) XOR all the elements in the array and numbers from 1 to n.    
// 2) The result will be XOR of missing and repeating numbers (missing ^ repeating).
// 3) Find a set bit in the XOR result to divide the numbers into two groups.
// 4) XOR the two groups separately to find the missing and repeating numbers. 
// 5) The missing number can be found by checking which of the two results from the groups is present in the array. The one that is present is the repeating number, and the other is the missing number.
// 6) Use long long to avoid integer overflow when calculating XOR.
// 7) The XOR operation is used because it has the property that a ^ a = 0 and a ^ 0 = a, which helps in canceling out the numbers and finding the missing and repeating numbers efficiently.
// Note: The XOR approach is particularly efficient because it allows us to find the missing and repeating numbers in a single pass through the array, without needing extra space for counting occurrences or calculating sums.
// Time Complexity: O(n) - single pass to calculate XOR and find repeating and missing numbers.
// Space Complexity: O(1) - no extra space used.

vector<int> findRepeatingAndMissingXOR(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(2); // result[0] = repeating, result[1] = missing

    long long xorResult = 0; // To store the XOR of all elements and numbers from 1 to n

    // Step 1: XOR all the elements in the array and numbers from 1 to n
    for (int num : arr) {
        xorResult ^= num;
    }
    for (int i = 1; i <= n; i++) {
        xorResult ^= i;
    }

    // Step 2: Find a set bit in the XOR result to divide the numbers into two groups
    int setBit = xorResult & -xorResult; // Get the rightmost set bit

    long long group1 = 0; // To store XOR of first group
    long long group2 = 0; // To store XOR of second group

    // Step 3: Divide the numbers into two groups based on the set bit and XOR separately
    for (int num : arr) {
        if (num & setBit) {
            group1 ^= num; // Group with the set bit
        } else {
            group2 ^= num; // Group without the set bit
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i & setBit) {
            group1 ^= i; // Group with the set bit
        } else {
            group2 ^= i; // Group without the set bit
        }
    }

    // Step 4: Determine which of the two results is the missing number and which is the repeating number
    bool isGroup1Repeating = false;
    for (int num : arr) {
        if (num == group1) {
            isGroup1Repeating = true;
            break;
        }
    }

    if (isGroup1Repeating) {
        result[0] = group1; // repeating number
        result[1] = group2; // missing number
    } else {
        result[0] = group2; // repeating number
        result[1] = group1; // missing number
    }

    return result; // Return the repeating and missing numbers
}

int main() {
    // for Brute Force Approach
    // vector<int> arr = {3, 1, 2, 5, 3};
    // vector<int> result = findRepeatingAndMissing(arr);

    // for Better Approach    // vector<int> arr = {3, 1, 2, 5, 3};
    // vector<int> result = findRepeatingAndMissingBetter(arr);

    // for Optimal Approach    // vector<int> arr = {3, 1, 2, 5, 3};
    // vector<int> result = findRepeatingAndMissingOptimal(arr);

    vector<int> arr = {3, 1, 2, 5, 3};
    vector<int> result = findRepeatingAndMissingXOR(arr);
    cout << "Repeating Number: " << result[0] << ", Missing Number: " << result[1] << endl;
    return 0;
}
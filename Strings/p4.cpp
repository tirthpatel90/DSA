// Longest Common Prefix
// example: ["flower","flow","flight"] -> "fl"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Brute force approach :
// check every possible prefix of the first string and see if it is a prefix of all other strings.
// Time complexity: O(n*m) where n is the number of strings and m is the length of the longest string (worst case).
// Space complexity: O(m) for storing the longest common prefix.

string longestCommonPrefixBruteForce(const vector<string>& strs) {
    if (strs.empty()) return ""; // Edge case: no strings

    string prefix = strs[0]; // Start with the first string as the initial prefix

    // Step 1: Check each string against the current prefix
    for (size_t i = 1; i < strs.size(); ++i) {
        const string& currentString = strs[i];
        size_t j = 0;

        // Step 2: Compare characters of the current string with the prefix
        while (j < prefix.size() && j < currentString.size() && prefix[j] == currentString[j]) {
            ++j; // Move to the next character
        }

        // Step 3: Update the prefix to the common part found so far
        prefix = prefix.substr(0, j); // Keep only the common part

        // If at any point the prefix becomes empty, we can stop early
        if (prefix.empty()) {
            break;
        }
    }
    return prefix; // Return the longest common prefix found
}

// Optimal approach :
// Sort the array of strings and compare only the first and last strings.   
// Time complexity: O(n log n) for sorting + O(m) for comparing the first and last strings, where n is the number of strings and m is the length of the longest string.
// Space complexity: O(1) if we sort in place, otherwise O(n) for the sorted array.

string longestCommonPrefixOptimal(vector<string>& strs) {
    if (strs.empty()) return ""; // Edge case: no strings

    sort(strs.begin(), strs.end()); // Step 1: Sort the strings

    string first = strs[0]; // First string after sorting
    string last = strs[strs.size() - 1]; // Last string after sorting

    string answer = ""; // To store the longest common prefix
    // Step 2: Compare characters of the first and last strings
    for (size_t i = 0; i < first.size() && i < last.size(); ++i) {
        if (first[i] == last[i]) {
            answer += first[i]; // If characters match, add to the answer
        } else {
            break; // Stop at the first mismatch
        }
    }
    return answer; // Return the longest common prefix found
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix (Brute Force): " << longestCommonPrefixBruteForce(strs) << endl;
    cout << "Longest Common Prefix (Optimal): " << longestCommonPrefixOptimal(strs) << endl;
    return 0;
}
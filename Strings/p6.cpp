// Check if two strings are anagram of each other
// Example: "listen" and "silent" are anagrams because they contain the same characters in a different order.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Brute force approach :
// - Idea: Sort both strings and compare them. If they are the same after sorting, they are anagrams.
// Time complexity: O(n log n) for sorting both strings.
// Space complexity: O(n) for storing the sorted strings.
bool areAnagramsBruteForce(string s1, string s2) {
    if (s1.size() != s2.size()) return false; // If lengths differ, they cannot be anagrams

    sort(s1.begin(), s1.end()); // Sort the first string
    sort(s2.begin(), s2.end()); // Sort the second string

    return s1 == s2; // Compare the sorted strings
}

// Optimal approach :
// - Idea: Count the frequency of each character in both strings and compare the counts.
// Time complexity: O(n) for counting characters in both strings.
// Space complexity: O(1) if we assume a fixed character set (like ASCII), otherwise O(n) for the frequency maps.
bool areAnagramsOptimal(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false; // If lengths differ, they cannot be anagrams

    int count[26] = {0}; // Assuming only lowercase letters
    for (size_t i = 0; i < s1.size(); ++i) {
        count[s1[i] - 'a']++; // Increment count for character in s1
        count[s2[i] - 'a']--; // Decrement count for character in s2
    }

    for (int i = 0; i < 26; ++i) {
        if (count[i] != 0) return false; // If any count is not zero, strings are not anagrams
    }

    return true; // All counts are zero, strings are anagrams
}

int main() {
    string s1 = "listen";
    string s2 = "silent";

    // Test the brute force approach
    if (areAnagramsBruteForce(s1, s2)) {
        cout << "Brute Force: The strings are anagrams." << endl;
    } else {
        cout << "Brute Force: The strings are NOT anagrams." << endl;
    }

    // Test the optimal approach
    if (areAnagramsOptimal(s1, s2)) {
        cout << "Optimal: The strings are anagrams." << endl;
    } else {
        cout << "Optimal: The strings are NOT anagrams." << endl;
    }

    return 0;
}
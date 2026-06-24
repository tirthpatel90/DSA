// Longest Palindrome substring
#include <bits/stdc++.h>
using namespace std;

// time complexity: O(n^2), where n is the length of the string s. This is because we are expanding around each character in the string, and in the worst case, we may have to check all characters for each center.
// space complexity: O(1), as we are using a constant amount of extra space for variables and the lambda function. The space used for the input string is not counted towards the space complexity.
// step 1: Initialize two variables, start and maxLen, to keep track of the starting index and length of the longest palindrome found so far.
// step 2: Define a lambda function expandAroundCenter that takes two indices, left and right, and expands around them to find the length of the palindrome centered at those indices.
// step 3: Iterate through each character in the string and treat it as a center of palindrome. For each character, check both odd and even length palindromes by calling expandAroundCenter with appropriate indices.
// step 4: Update maxLen and start if a longer palindrome is found.
// step 5: After processing all characters, return the longest palindrome substring found using the start index and maxLen.

string longestPalindrome(string s) {
    if (s.empty()) return "";
    int start = 0, maxLen = 1; 
    int n = s.length();
    
    // Function to expand around center
    auto expandAroundCenter = [&](int left, int right) {
        // Expand the window as long as the characters at left and right are the same and within bounds
        while (left >= 0 && right < n && s[left] == s[right]) { 
            left--; // Move left pointer to the left
            right++; // Expand the window as long as the characters at left and right are the same and within bounds
        }
        return right - left - 1; // Return the length of the palindrome found
    };
    // Iterate through each character in the string and treat it as a center of palindrome
    for (int i = 0; i < n; i++) {
        int odd = expandAroundCenter(i, i);     // Odd length palindromes
        int even = expandAroundCenter(i, i + 1); // Even length palindromes
        int len = max(odd, even); // Get the maximum length of palindrome found
        if (len > maxLen) { // If the current palindrome is longer than the previously found maximum
            maxLen = len; // Update max length of palindrome found
            start = i - (len - 1) / 2; // Update start index for odd length palindromes
        }
    }
    
    return s.substr(start, maxLen); // Return the longest palindrome substring found    
}

int main() {
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    return 0;
}
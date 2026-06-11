// Largest Odd Number in a String.
// Given a string num that represents a large integer, return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
#include <iostream>
#include <string>
using namespace std;

// Brute force approach :
// - Idea: try every possible substring of the number string and keep the largest one
//   that ends with an odd digit.
// - Why checking the last digit is enough: a number is odd only if its last digit is odd.
// - To compare two numeric strings of the same type, lexicographical comparison works here
//   because we are looking for the largest-valued substring among candidates.
// Time complexity: O(n^3) in the worst case because we generate many substrings and compare them.
// Space complexity: O(n) for storing the best odd substring found so far.
// Step-by-step plan:
// 1) Generate every non-empty substring using two loops.
// 2) For each substring, check whether its last character is one of 1,3,5,7,9.
// 3) If it is odd, compare it with the current best answer.
// 4) Keep the larger one as the new answer.
string largestOddNumberBruteForce(const string& num) {
    string largestOdd = ""; // To store the largest odd substring found

    // Step 1: Generate all non-empty substrings.
    // `i` is the starting index and `j` is the ending boundary (one past the last char).
    for (size_t i = 0; i < num.size(); ++i) {
        for (size_t j = i + 1; j <= num.size(); ++j) {
            string substring = num.substr(i, j - i); // Get substring from index i to j-1
            
            // Step 2: Check if the last character of the substring is an odd digit.
            // If the last digit is odd, the whole substring represents an odd number.
            char lastChar = substring.back();
            if (lastChar == '1' || lastChar == '3' || lastChar == '5' || lastChar == '7' || lastChar == '9') {
                // Step 3: Compare with the largest odd found so far.
                // Since we want the largest-valued substring, keep the larger string.
                if (substring > largestOdd) { // Lexicographical comparison works for numeric strings
                    largestOdd = substring; // Update largest odd substring
                }
            }
        }
    }
    return largestOdd; // Return the largest odd substring found, or "" if none exists
}

// Optimal approach :
// - Idea: scan from the end of the string because the last digit decides whether a number is odd.
// - The first odd digit we meet from the right gives the farthest ending position of an odd number.
// - The largest odd substring is then the prefix from the beginning up to that odd digit.
// Time complexity: O(n) because we scan once from right to left.
// Space complexity: O(n) in the worst case because we may return almost the whole string.
// Step-by-step plan:
// 1) Start from the last character and move left.
// 2) Stop at the first odd digit we find.
// 3) Remove any leading zeroes before that position so the returned number looks clean.
// 4) Return the substring from the first non-zero digit to the odd digit.
// Note: If no odd digit exists, the answer should be an empty string.

string largeOddNum(string& s) {
    int ind = -1;

    // Step 1: Find the last odd digit in the string.
    // We move from right to left so the first odd digit found becomes the last odd digit overall.
    int i;
    for (i = s.length() - 1; i >= 0; i--) {
        if ((s[i] - '0') % 2 == 1) {
            ind = i;
            break;
        }
    }

    // Step 2: Skip leading zeroes from the start of the string.
    // Example: if the answer portion is "000135", we want to return "135" instead of "000135".
    i = 0;
    while (i <= ind && s[i] == '0') i++;

    // Step 3: Return the substring from the first non-zero digit to the last odd digit.
    // If there was no odd digit, ind stays -1 and this returns an empty string.
    return s.substr(i, ind - i + 1);
}

int main() {
    string s = "23532"; // Sample input string representing a large integer
    // --- RUN OPTIONS ---
    // Brute force: checks every substring, useful for understanding but slower.
    cout << "Brute Force Answer: " << largestOddNumberBruteForce(s) << endl;
    // Better / optimal: scan from the end and return the largest odd substring directly.
    cout << "Optimal Answer: " << largeOddNum(s) << endl;

    // --- SUGGESTED TESTS / DRY RUNS (easy language) ---
    // 1) s = "52" -> odd digit does not exist at the end, result = "5"
    // 2) s = "4206" -> no odd digit at all, result = ""
    // 3) s = "35427" -> last digit is already odd, result = "35427"
    // 4) s = "0001350" -> last odd digit is '5', and leading zeroes are removed, result = "135"
    // Dry run for s = "23532":
    // - Start from the end: 2 (even), then 3 (odd) -> stop here.
    // - This means the largest odd substring must end at index of that 3.
    // - The substring from the start up to that index is "2353".
    // - Since there are no leading zeroes, final answer is "2353".
    return 0;
}
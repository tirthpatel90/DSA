// Check if one string is rotation of another
// example: "abcde" and "deabc" are rotations of each other.
#include <iostream>
#include <string>
using namespace std;

// Brute force approach :
// - Idea: Generate all rotations of the first string and check if any of them matches the second string.
// Time complexity: O(n^2) because we generate n rotations and each rotation takes O(n) to compare with the second string.
// Space complexity: O(n) for storing each rotation.
bool areRotationsBruteForce(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false; // If lengths differ, they cannot be rotations

    string rotation = s1; // Start with the original string as the first rotation
    for (size_t i = 0; i < s1.size(); ++i) {
        if (rotation == s2) {
            return true; // Found a rotation that matches s2
        }
        // Generate the next rotation by moving the first character to the end
        rotation = rotation.substr(1) + rotation[0];
    }
    return false; // No rotation matched s2
}

// Optimal approach :
// - Idea: Concatenate the first string with itself. If the second string is a substring of this concatenated string, then they are rotations of each other.
// Time complexity: O(n) for concatenation and substring search.
// Space complexity: O(n) for storing the concatenated string.
bool areRotationsOptimal(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false; // If lengths differ, they cannot be rotations

    string concatenated = s1 + s1; // Concatenate s1 with itself
    return concatenated.find(s2) != string::npos; // Check if s2 is a substring of the concatenated string
// for return rotations count{
//     int count = 0;
//     size_t pos = concatenated.find(s2);
//     while (pos != string::npos) {
//         count++; 
//     }
//     return count;
// }
}

int main() {
    string s1 = "abcde";
    string s2 = "deabc";

    // Test the brute force approach
    if (areRotationsBruteForce(s1, s2)) {
        cout << "Brute Force: The strings are rotations of each other." << endl;
    } else {
        cout << "Brute Force: The strings are NOT rotations of each other." << endl;
    }

    // Test the optimal approach
    if (areRotationsOptimal(s1, s2)) {
        cout << "Optimal: The strings are rotations of each other." << endl;
    } else {
        cout << "Optimal: The strings are NOT rotations of each other." << endl;
    }

    return 0;
}  
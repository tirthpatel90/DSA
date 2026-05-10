// Given two strings s and goal, return true if and only if s can become goal
// after some number of left shifts.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        // If lengths are different, rotation is impossible.
        if (s.length() != goal.length())
            return false;

        // All rotations of s are present as substrings in (s + s).
        // Example: s = "abcde"
        // s + s = "abcdeabcde" -> contains "cdeab", "deabc", etc.
        return (s + s).find(goal) != string::npos;
    }
};

int main() {
    string s, goal;
    cout << "Enter the first string: ";
    cin >> s;
    cout << "Enter the second string: ";
    cin >> goal;

    Solution obj;
    if (obj.rotateString(s, goal)) {
        cout << "The strings are rotations of each other." << endl;
    } else {
        cout << "The strings are not rotations of each other." << endl;
    }

    return 0;
}

/*
Time Complexity:
O(n) average, where n is the length of the string.
Reason: Building (s + s) takes O(n), and find(goal) is O(n) average.

Space Complexity:
O(n) extra space for the concatenated string (s + s).
*/
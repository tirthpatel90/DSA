// Roman Numeral to Integer
// Given a roman numeral, convert it to an integer.
#include <iostream>
#include <unordered_map>
using namespace std;
// time complexity: O(1), as the number of roman numeral characters is limited and does not depend on the input size.
// space complexity: O(1), as we are using a constant amount of extra space for the unordered map.
// step 1: Create an unordered map to store the integer values of the roman numeral characters.
// step 2: Initialize a variable result to 0, which will store the final integer value.
// step 3: Iterate through each character in the input string s.
// step 4: For each character, check if the next character has a greater value. If it does, subtract the current character's value from the result; otherwise, add it to the result.
int romanToInt(string s) {
    // Create an unordered map to store the integer values of the roman numeral characters
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int result = 0; // Initialize result to store the final integer value
    for (int i = 0; i < s.length(); i++) {
        // Check if the current character is less than the next character to determine if we should add or subtract its value
        if (i < s.length() - 1 && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]]; // Subtract the value of the current character from the result
        } else {
            result += roman[s[i]]; // Add the value of the current character to the result
        }
    }
    return result; // Return the final integer value after processing all characters
}

int main() {
    string s = "MCMXCIV";
    cout << "Integer value: " << romanToInt(s) << endl;
    return 0; 
}
//Maximum Nesting Depth of Parenthesis
#include <iostream>
#include <algorithm>
using namespace std;


// time complexity: O(n), where n is the length of the string s.
// space complexity: O(1), as we are using a constant amount of extra space.
// step 1: Initialize two variables, currentDepth and maxDepth, to 0. These will keep track of the current depth of nested parentheses and the maximum depth encountered so far, respectively.
// step 2: Iterate through each character in the string s.
// step 3: If the character is '(', increment currentDepth and update maxDepth if currentDepth exceeds it.
// step 4: If the character is ')', decrement currentDepth.
// step 5: After processing all characters, return maxDepth as the result.
int maxNestingDepth(string s) {
    int currentDepth = 0;
    int maxDepth = 0;
    for (char c : s) {
        if (c == '(') {
            currentDepth++;
            maxDepth = max(maxDepth, currentDepth);
        } else if (c == ')') {
            currentDepth--;
        }
    }
    return maxDepth;
}

int main() {
    string s = "(1+(2*3)+((8)/4))+1";
    cout << "Maximum nesting depth: " << maxNestingDepth(s) << endl;
    return 0;
}
// Remove Outermost Parentheses
// example: "(()())(())" -> "()()()"
// Explanation:
// - The string `s` is composed of several primitive parentheses strings concatenated.
// - Each primitive is a balanced parentheses string that cannot be split into two non-empty
//   balanced strings. For each primitive, we must remove its outermost pair of parentheses.
// - We walk through the string and keep a counter `openCount` that tracks how many
//   '(' we have seen that are not yet closed. When we see the first '(' of a primitive,
//   `openCount` is 0; we do NOT add that '(' to the result because it is the outermost.
// - Similarly, when we see the matching ')' that closes the primitive (bringing openCount
//   back to 0), we do NOT add that ')' either. All other parentheses are inside primitives
//   and should be included in the output.
// Complexity: O(n) time and O(n) extra space for the result string, where n = s.length().
#include <iostream>
#include <string>
using namespace std;
string removeOuterParentheses(string s) {
    string result;
    int openCount = 0; // Tracks how many '(' are currently open (depth)

    // Walk through each character and decide whether to include it in result.
    // We only skip the very first '(' of a primitive (when openCount==0) and
    // the matching final ')' that brings openCount back to 0. All other parens
    // are interior to primitives and should be kept.
    for (char c : s) {
        if (c == '(') {
            // If openCount > 0, we are already inside a primitive and this '('
            // is not the outermost, so include it in the output.
            if (openCount > 0) {
                result += c; // interior '('
            }
            // Every '(' increases the nesting depth.
            openCount++;
        } else { // c == ')'
            // We are about to close a parentheses. Decrease depth first because
            // the outermost ')' corresponds to depth going from 1->0 and should
            // not be included in the output.
            openCount--;
            // If after decrement we are still inside a primitive (openCount>0),
            // this ')' is not the outermost closing, so include it.
            if (openCount > 0) {
                result += c; // interior ')'
            }
        }
    }

    return result;
}

int main() {
    string s = "(()())(())";
    // --- RUN OPTIONS ---
    // Example: the provided input demonstrates two primitives: "(()())" and "(())".
    // After removing outermost parentheses from each primitive we get: "()()()".
    cout << removeOuterParentheses(s) << endl; // Output: "()()()"

    // --- SUGGESTED TESTS / DRY RUNS (easy language) ---
    // 1) s = "()" -> single primitive with nothing interior -> result = "" (empty)
    // 2) s = "(())" -> primitive with one interior pair -> result = "()"
    // 3) s = "(()())(())" -> two primitives -> result = "()()()"
    // 4) s = "((()))" -> nested three deep -> result = "(())"
    // Dry run for s = "(()())(())":
    // - Start openCount=0
    // - Read '(' -> openCount 0->1 (outermost '(' of first primitive) -> skip
    // - Read '(' -> openCount 1->2 -> include '('
    // - Read ')' -> openCount 2->1 -> include ')'
    // - Read '(' -> openCount 1->2 -> include '('
    // - Read ')' -> openCount 2->1 -> include ')'
    // - Read ')' -> openCount 1->0 (closing outermost) -> skip
    // - Repeat for second primitive '(())' which yields '()' -> final result "()()()"

    return 0;
}
// Reverse Words in a String
// Problem idea :
// - We are given a sentence and want to reverse the order of the words.
// - The words themselves should keep their own letters in normal order.
// - Example: "Hello World" becomes "World Hello".
// Why this works: if we reverse the whole string first, the words appear in the
// opposite order, but each word is also reversed letter-by-letter. Then we reverse
// each word again to restore its letters. This gives the correct final answer.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    int n = s.size();
    string ans = "";

    // Step 1: reverse the full string.
    // After this, the last word becomes the first part of the string,
    // but its letters are also reversed, so we will fix that later.
    reverse(s.begin(), s.end());

    // Step 2: scan the reversed string and collect one word at a time.
    // Each loop iteration tries to read a full word until a space is found.
    for (int i = 0; i < n; i++) {
        string word = "";

        // Build the current word character by character until we hit a space.
        while (i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }

        // Step 3: reverse the current word back to normal order.
        // This restores the letters of the word while keeping the word order reversed.
        reverse(word.begin(), word.end());

        // Step 4: append the word to the answer only if it is not empty.
        // Empty words may appear because the original string can contain multiple spaces.
        if (word.length() > 0) {
            ans += " " + word;
        }
    }

    // ans starts with a leading space because we always add " " before each word.
    // Remove that first space before returning the final result.
    return ans.substr(1);
}

int main() {
    string s = "Hello World";
    // --- RUN OPTIONS ---
    // Example: the provided input demonstrates a simple case with two words.
    // The function should reverse the order of the words and keep each word readable.
    // Expected output for this sample: "World Hello".
    cout << reverseWords(s) << endl; // Output: "World Hello"

    // --- SUGGESTED TESTS / DRY RUNS  ---
    // 1) s = "Hello" -> only one word, so reversing word order changes nothing -> result = "Hello"
    // 2) s = "Hello World" -> two words swap places -> result = "World Hello"
    // 3) s = "  Hello   World  " -> extra spaces should not create extra words in the answer.
    //    Expected cleaned result: "World Hello"
    // 4) s = "" -> empty string -> result should be empty
    // Dry run for s = "Hello World":
    // - Original string: "Hello World"
    // - Step 1 reverse full string -> "dlroW olleH"
    // - Step 2 read first word from reversed string -> "dlroW"
    // - Step 3 reverse this word -> "World"
    // - Step 4 read second word -> "olleH"
    // - Step 5 reverse this word -> "Hello"
    // - Step 6 combine in the order found -> "World Hello"
    // - Final answer returned by the function -> "World Hello"

    // If you want to test more cases, replace `s` with any sentence and run again.
}
#include<iostream>
using namespace std;

string s; // Global string to store the input string
int n; // Global variable to store the length of the string

int fun(int i)
{
    if (i >= n / 2) {
        return 1; // Base case: when the index reaches the middle of the string
    }
    if (s[i] != s[n - i - 1]) {
        return 0; // If characters at the current index and its corresponding index from the end are not equal, it's not a palindrome
    }
    return fun(i + 1); // Recursive call with the next index
}
int main()
{
    cout << "Enter a string: ";
    cin >> s; // Read the input string
    n = s.length(); // Get the length of the string
    if (fun(0) == 0) {
        cout << "The string is not a palindrome." << endl; // If the function returns 0, it's not a palindrome
    } else {
        cout << "The string is a palindrome." << endl; // If the function returns 1, it's a palindrome
    }
}
// Time complexity is O(n) and space complexity is O(n) due to recursive call stack.
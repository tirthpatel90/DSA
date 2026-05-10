#include<iostream>
using namespace std;
// function to print numbers from n to 1 using recursion
void fun(int n) {
    if (n == 0) {
        return; // Base case: if n is 0, stop recursion
    }
    cout << n << " "; // Print the current number
    fun(n - 1); // Recursive call with decremented n
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    fun(n); // Start recursion with the entered number
    return 0;
}
//time complexity is O(n) and space complexity is O(n) due to recursive call stack.
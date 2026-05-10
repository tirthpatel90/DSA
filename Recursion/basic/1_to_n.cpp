#include<iostream>
using namespace std;
void fun(int i, int n) {
    if (i > n) {
        return; // Base case: if i exceeds n, stop recursion
    }
    cout << i << " "; // Print the current number
    fun(i + 1, n); // Recursive call with incremented i
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    fun(1, n); // Start recursion with i = 1
}
//time complexity is O(n) and space complexity is O(n) due to recursive call stack.
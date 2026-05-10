#include<iostream>
using namespace std;
void fun(int i, int n) {
    if (i < 1) {
        return; // Base case: if i is less than 1, stop recursion
    }
    fun(i - 1, n); // Recursive call with decremented i
    cout << i << " "; // Print the current number after the recursive call
}
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    fun(n, n); // Start recursion with i = 1
}
//time complexity is O(n) and space complexity is O(n) due to recursive call stack.
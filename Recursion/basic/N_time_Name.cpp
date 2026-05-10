#include<iostream>
using namespace std;
// function to print name n times using recursion
void fun(int i, int n) {
    if (i > n) {
        return; // Base case: if i exceeds n, stop recursion
    }
    cout << " JOHN " << endl; // Print the name
    fun(i + 1, n); // Recursive call with incremented i
}
int main()
{
    int n;
    cout << "enter how many times you want to print your name: ";
    cin >> n;
    fun(1, n); // Start recursion with i = 1
}
//time complexity is O(n) and space complexity is O(n) due to recursive call stack.
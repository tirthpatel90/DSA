#include<iostream>
using namespace std;
int fib(int n){
    if (n <= 1) {
        return n; // Base case: the Fibonacci of 0 is 0 and the Fibonacci of 1 is 1
    }
    int lastDigit = fib(n - 1); // Recursive call to get the (n-1)th Fibonacci number
    int secondLastDigit = fib(n - 2); // Recursive call to get the (n-2)th Fibonacci number
    return lastDigit + secondLastDigit;
}
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl; // Call the Fibonacci function and print the result
}
// Time complexity is O(2^n) and space complexity is O(n) due to recursive call stack.  
#include<bits/stdc++.h>
using namespace std;
//functional method
int fact(int n){
    if(n == 0){
        return 1; // Base case: the factorial of 0 is 1
    }
    return n * fact(n - 1); // Recursive call with n decremented by 1
}
//tail recursive method or parameterized method
int fun(int i, int fact){
    if(i == 0){
        return fact; // Base case: when i reaches 0, return the accumulated factorial
    }
    return fun(i - 1, fact * i); // Recursive call with i decremented by 1 and current i multiplied to fact parameterized as fact
}
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The factorial of " << n << " is: " << fact(n) << endl; // Call the factorial function and print the result
    cout << "The factorial of " << n << " using tail recursion is: " << fun(n, 1) << endl; // Call the tail recursive function and print the result
}
//time complexity is O(n) and space complexity is O(n) due to recursive call stack.
#include<iostream>
using namespace std;
int sum(int n){
    if(n == 0){
        return 0; // Base case: the sum of numbers from 1 to 0 is 0
    }
    return n + sum(n - 1); // Recursive call with n decremented by 1
}
int fun(int i, int sum){
    if(i == 0){
        return sum; // Base case: when i reaches 0, return the accumulated sum
    }
    return fun(i - 1, sum + i); // Recursive call with i decremented by 1 and current i added to sum parameterized as sum
}
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The sum of numbers from 1 to " << n << " is: " << sum(n) << endl; // Call the sum function and print the result
    cout << "The sum of numbers from 1 to " << n << " using tail recursion is: " << fun(n, 0) << endl; // Call the tail recursive function and print the result
}
//time complexity is O(n) and space complexity is O(n) due to recursive call stack.
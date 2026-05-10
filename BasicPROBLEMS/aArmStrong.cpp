#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, sum = 0, x;
    cout << "Enter a number: ";
    cin >> n;
    x = n;
    
    // Count the number of digits
    int digit_count = 0, temp = n;
    while (temp > 0) {
        digit_count++;
        temp /= 10;
    }
    
    // Calculate Armstrong number sum
    while (x > 0) {
        int digit = x % 10;
        sum += pow(digit, digit_count);
        x /= 10;
    }
    if (sum == n) {
        cout << n << " is an Armstrong number." << endl;
    } else {
        cout << n << " is not an Armstrong number." << endl;
    }
    return 0;
}
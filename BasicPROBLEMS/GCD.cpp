#include<bits/stdc++.h>
using namespace std;
// find gcd of two numbers using Euclidean algorithm
// time complexity is O(log(min(a, b))) and space complexity is O(1)
int gcd ( int a, int b )
{
    if ( b == 0 )
    {
        return a; // Base case: if b is 0, gcd is a
    }
    return gcd(b, a % b); // Recursive call with b and the remainder of a divided by b
}
int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
}
#include<bits/stdc++.h>
using namespace std;

int rev( int n )
{
    int revnum = 0;
    while ( n > 0 )
    {
        int lastdigit = n % 10;
        revnum = revnum * 10 + lastdigit;
        n = n / 10;
    }
    return revnum;
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Reverse of " << n << " is: " << rev(n) << endl;
    return 0;
}
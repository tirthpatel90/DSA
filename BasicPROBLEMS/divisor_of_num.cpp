#include<bits/stdc++.h>
using namespace std;
 // Function to find and print all divisors of a number
 // time complexity is O(n) and space complexity is O(1)
void div ( int n )
{
    for( int i = 1; i <= n; i++ )
    {
        if ( n % i == 0 )
        {
            cout << i << " ";
        }
    }
}

// time complexity is O(sqrt(n)) and space complexity is O(1)
void divEfficient ( int n )
{
    vector<int> divisors;
    for( int i = 1; i <= sqrt(n); i++ )
    {
        if ( n % i == 0 )
        {
            divisors.push_back(i);
            if ( n / i != i ) // To avoid printing the square root twice
            {
                divisors.push_back(n / i);
            }
        }
    }
    // To print divisors in sorted order, we can store them in a vector and sort it

    sort(divisors.begin(), divisors.end());
    for ( auto it : divisors )
    {
        cout << it << " ";
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Divisors of " << n << " are: ";
    div(n);
    cout << endl;
    // Efficient approach to find divisors for less time complexity
    cout << "Efficient approach: ";
    divEfficient(n);
    cout << endl;
}
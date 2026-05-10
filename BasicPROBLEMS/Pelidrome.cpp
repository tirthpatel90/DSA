#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0) return false;

        long long rev = 0, num = x;
        while (num){
            rev = rev* 10 + num % 10;
            num /= 10;
        }
        return rev == x;
    }
};
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Solution sol;
    if (sol.isPalindrome(n)) {
        cout << n << " is a palindrome." << endl;
    } else {
        cout << n << " is not a palindrome." << endl;
    }
    return 0;
}
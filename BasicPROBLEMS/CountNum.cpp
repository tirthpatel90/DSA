#include<bits/stdc++.h>
using namespace std;

int countNum(int n){
    int count = 0;
    while(n > 0){
        count = count + 1;
        n = n / 10;
    }
    return count;
}
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of digits in " << n << " is: " << countNum(n) << endl;
    return 0;
}
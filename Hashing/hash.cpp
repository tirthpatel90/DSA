#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    int hash[13] = {0};
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 && arr[i] < 13) {
            hash[arr[i]] += 1;
        }
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    while (q--) {
        int number;
        cout << "Enter query value: ";
        cin >> number;
        // fetching:
        if (number >= 0 && number < 13) {
            cout << "Frequency of " << number << " = " << hash[number] << endl;
        } else {
            cout << "Value " << number << " is outside the supported range 0 to 12" << endl;
        }
    }
    return 0;
}

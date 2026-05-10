#include<iostream>
using namespace std;

int fun(int arr[], int i, int r){
    if(i >=r) return i;
    swap(arr[i], arr[r]);
    return fun(arr, i+1, r-1);
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    fun(arr, 0, n-1);
    cout << "Reversed array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
} 
// Time complexity is O(n) and space complexity is O(n) due to recursive call stack.
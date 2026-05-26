// Floor and Ceil of a number in a sorted array
// Given a sorted array and a target value, find the floor and ceil of the target in the array.
// Floor: Largest element in the array less than or equal to target.
// Ceil: Smallest element in the array greater than or equal to target.
#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int>& arr, int target) {
    // NOTE: This function assumes the caller provides a non-empty sorted array.
    // If `arr` is empty, `arr.size() - 1` will underflow at the unsigned level
    // before being converted to `int` which leads to undefined/incorrect behavior.
    // To keep this file's logic unchanged, do NOT modify the calls here — instead
    // ensure you check `arr.empty()` before calling `findFloor` in production code.
    // Return semantics: returns the floor value (not index). If no floor exists
    // (all elements > target), this implementation returns -1.
    int low = 0, high = arr.size() - 1;
    int floor = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            floor = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return floor;
}

int findCeil(vector<int>& arr, int target) {
    // NOTE: This function assumes the caller provides a non-empty sorted array.
    // If `arr` is empty, behavior is undefined due to computing `arr.size() - 1`.
    // Return semantics: returns the ceil value (not index). If no ceil exists
    // (all elements < target), this implementation returns -1.
    int low = 0, high = arr.size() - 1;
    int ceil = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ceil = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ceil;
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 10};
    int target = 5;

    // Sample run:
    // - `arr` must be sorted in non-decreasing order for these functions to work.
    // - If you expect empty-array inputs, check `if (arr.empty())` before calling.
    // - The functions return the value of floor/ceil or -1 when no such value exists.
    // Examples of edge cases to try by changing `arr` / `target` below:
    // 1) target smaller than all elements -> floor = -1, ceil = first element
    // 2) target greater than all elements -> floor = last element, ceil = -1
    // 3) single-element arrays -> behavior follows same return semantics

    int floor = findFloor(arr, target);
    int ceil = findCeil(arr, target);

    cout << "Floor of " << target << " is: " << floor << endl;
    cout << "Ceil of " << target << " is: " << ceil << endl;

    return 0;
}
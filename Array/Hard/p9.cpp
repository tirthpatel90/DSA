// Count Reverse Pairs in an Array
// Given an array of integers, count the number of reverse pairs in the array. A reverse pair is a pair of indices (i, j) such that i < j and arr[i] > arr[j].  
#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach : iterate through all pairs of elements and count the number of reverse pairs.
// Time Complexity: O(N^2) 
// Space Complexity: O(1)
// steps:
// 1. Initialize a variable count to store the number of reverse pairs.
// 2. Run two nested loops to compare each pair of elements.
// 3. If arr[i] > arr[j] and i < j, increment the count.
// 4. Return the count.
int countPairs(vector<int>&a, int n) {

    // Count the number of reverse pairs using brute force.
    // We consider every pair (i, j) with i < j and check the condition
    // a[i] > 2 * a[j]. This is O(n^2) and is useful for small n or
    // for validating the optimal algorithm.
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // For each i, scan all j > i
        for (int j = i + 1; j < n; j++) {
            // If the pair satisfies the reverse-pair condition, increment
            // the counter. Note: the code uses integer arithmetic as-is.
            if (a[i] > 2 * a[j]) cnt++;
        }
    }
    return cnt; // Total number of reverse pairs found by brute force
}

int teamBrute(vector <int> & skill, int n) {
    return countPairs(skill, n);
}

// Optimal Approach : Use Merge Sort to count reverse pairs while sorting the array.
// Time Complexity: O(N log N)  
// Space Complexity: O(N) due to the temporary arrays used in merge sort.
// steps:
// 1. Implement a modified merge sort algorithm that counts reverse pairs during the merge step.
// 2. During the merge step, if an element from the right subarray is smaller than an element from the left subarray
//    then all remaining elements in the left subarray will also be greater than the current element from the right subarray, contributing to the reverse pair count.
// 3. Return the total count of reverse pairs after the merge sort is complete. 
// 4. The merge sort will sort the array in place while counting the reverse pairs.
// 5. The final count of reverse pairs will be returned at the end of the merge sort process.

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    // Merge two sorted halves [low..mid] and [mid+1..high] into temp.
    // We repeatedly pick the smaller head element from either half.
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // If left half still has elements, append them
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If right half still has elements, append them
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged, sorted content back into the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    // Count cross reverse-pairs where left index is in [low..mid]
    // and right index is in [mid+1..high]. Both halves are assumed
    // to be sorted already, which allows this counting to run in O(n)
    // by advancing a single pointer `right` monotonically.
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        // Move `right` forward while the condition arr[i] > 2*arr[right] holds
        // For each i, the number of valid j in the right half is
        // (right - (mid + 1)) after the loop finishes for that i.
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt; // Number of cross-pairs between the two halves
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    // Recursively count in left and right halves
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half

    // Count pairs where left element belongs to left half and right element
    // belongs to right half (cross pairs) using the two-pointer method
    cnt += countPairs(arr, low, mid, high); // count cross-pairs

    // Merge the two sorted halves back into arr
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int team(vector <int> & skill, int n)
{
    // Wrapper for the optimal merge-sort based solution.
    // This will return the total number of reverse pairs in `skill` and
    // will sort `skill` as a side-effect.
    return mergeSort(skill, 0, n - 1);
}

int main() {
    vector<int> arr = {1, 20, 6, 4, 5};
    
    // Example input array

    // --- Brute Force Run ---
    // Brute force run: uses the O(n^2) function to count reverse pairs.
    // This does not mutate `arr` and is useful for validating the
    // optimal implementation on small inputs.
    int bruteForceCount = countPairs(arr, arr.size());
    cout << "Number of reverse pairs (Brute Force): " << bruteForceCount << endl;

    // --- Optimal Approach Run ---
    // The optimal merge-sort based run counts in O(n log n). Because it
    // sorts the array as it goes, we reset `arr` to the original input
    // before invoking it to ensure a fair comparison with the brute force run.
    arr = {1, 20, 6, 4, 5}; // Resetting the array to original unsorted state
    int optimalCount = team(arr, arr.size());
    cout << "Number of reverse pairs (Optimal): " << optimalCount << endl;

    return 0;
}
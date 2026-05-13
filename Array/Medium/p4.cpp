// Kadane's Algorithm : maximum subarray sum in an array
#include <bits/stdc++.h>
using namespace std;

//brute force approach
//time complexity : O(n^3) space complexity : O(1)
int maxSubArraySumBrute(int arr[], int n)
{
    // 1) Start with smallest possible max
    int max_sum = INT_MIN;
    // 2) Try every subarray from i to j
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // 3) Sum elements from i to j
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += arr[k];
            // 4) Keep the largest sum seen
            max_sum = max(max_sum, sum);
        }
    }
    // 5) Return answer
    return max_sum;
}

//Better approach
//time complexity : O(n^2) space complexity : O(1)
int maxSubArraySumBetter(int arr[], int n)
{
    // 1) Start with smallest possible max
    int max_sum = INT_MIN;
    // 2) For each start index, grow the subarray and keep a running sum
    for (int i = 0; i < n; i++)
    {
        int sum = 0; // running sum for subarray starting at i
        for (int j = i; j < n; j++)
        {
            sum += arr[j]; // add next element
            // update max if this subarray is bigger
            max_sum = max(max_sum, sum);
        }
    }
    // 3) Return answer
    return max_sum;
}

//Optimal approach : Kadane's Algorithm
//time complexity : O(n) space complexity : O(1)
int maxSubArraySumOptimal(int arr[], int n)
{
    // Kadane's algorithm (simple):
    // Keep a running sum; reset to 0 if it goes negative; track the best sum.
    int max_sum = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];         // add current
        max_sum = max(max_sum, sum); // update best
        if (sum < 0) sum = 0;  // bad prefix, start fresh
    }
    return max_sum;
}

// If you also want to get/print the actual subarray that gives the maximum sum,
// uncomment the helper functions below. They are provided as comments so they
// don't affect compilation; remove the surrounding comment markers to use.
/*
// Returns pair<startIndex, endIndex> of max-sum subarray (inclusive)
pair<int,int> maxSubArrayIndices(int arr[], int n) {
    int max_sum = INT_MIN, sum = 0;
    int start = 0, s = 0, end = -1;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > max_sum) {
            max_sum = sum;
            start = s;
            end = i;
        }
        if (sum < 0) {
            sum = 0;
            s = i + 1;
        }
    }
    return {start, end};
}

// Print the elements of the maximum-sum subarray
void printMaxSubarray(int arr[], int n) {
    auto p = maxSubArrayIndices(arr, n);
    if (p.second >= p.first) {
        cout << "Max subarray elements: ";
        for (int i = p.first; i <= p.second; i++) cout << arr[i] << " ";
        cout << endl;
    } else {
        cout << "No valid subarray found" << endl;
    }
}
*/

/*
// Helper: find & print max subarray (uncomment to use)
long long maxSubArrayAndPrint(vector<int>& nums) {
    if (nums.empty()) {
        cout << "Array is empty" << endl;
        return 0;
    }

    // maximum sum
    long long maxi = LLONG_MIN;

    // current sum of subarray
    long long sum = 0;

    // starting index of current subarray
    int start = 0;

    // indices of the maximum sum subarray
    int ansStart = -1, ansEnd = -1;

    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        // update starting index if sum is reset
        if (sum == 0) start = i;

        // add current element to the sum
        sum += nums[i];

        // Update maxi and subarray indices if current sum is greater
        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        // Reset sum to 0 if it becomes negative
        if (sum < 0) sum = 0;
    }

    // Printing the subarray
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;

    // Return the maximum subarray sum found
    return maxi;
}
*/

int main()
{
    // Example: find maximum contiguous subarray sum
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum contiguous sum is " << maxSubArraySumOptimal(arr, n);
    return 0;
}
// Stock Buy & Sell
#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// time complexity : O(n^2) space complexity : O(1)
// Steps:
// 1) Initialize `max_sum` to the smallest integer to ensure any profit replaces it.
// 2) Consider every possible buy day `i`.
// 3) For each buy day `i`, consider every possible sell day `j` (j > i).
// 4) Compute profit as `arr[j] - arr[i]` (sell price - buy price).
// 5) Update `max_sum` with the largest profit seen.
// 6) Return `max_sum` after checking all pairs.
int maxSubArraySumBrute(int arr[], int n){
    int max_sum = INT_MIN; // 1) smallest possible initial value
    // 2) try each day as buy day
    for (int i = 0; i < n; i++){
        // 3) for each buy day, try each later day as sell day
        for (int j = i+1; j < n; j++){
            // 4) profit if bought at day i and sold at day j
            int sum = arr[j] - arr[i];
            // 5) keep the maximum profit found
            max_sum = max(max_sum, sum);
        }
    }
    // 6) return the best profit found (could be negative if prices always fall)
    return max_sum;
}

// Optimal approach (single pass)
// time complexity : O(n) space complexity : O(1)
// Steps:
// 1) Track the minimum price seen so far (`min_price`) as if that's the best day to buy.
// 2) For each day from left to right, compute the profit if we sold on that day
//    using the lowest buy price seen so far: `profit = arr[i] - min_price`.
// 3) Update the answer `max_profit` with the largest profit observed.
// 4) Update `min_price` with the current day's price if it's lower.
// 5) After processing all days, `max_profit` holds the maximum achievable profit.
int maxSubArraySumOptimal(int arr[], int n){
    // 1) start with first day's price as the best buy seen so far
    int min_price = arr[0];
    // initialize max profit to 0 (no transaction yields 0 profit)
    int max_profit = 0;
    // 2) iterate days starting from day 1 (index 1)
    for (int i = 1; i < n; i++){
        // 2a) compute potential profit if sold today
        int profit = arr[i] - min_price;     // potential profit if sold today
        // 3) update best profit if this is better
        max_profit = max(max_profit, profit);
        // 4) update min_price for future days (best buy opportunity so far)
        min_price = min(min_price, arr[i]); // update min price
    }
    // 5) return the maximum profit found
    return max_profit;
}

int main()
{
    // Example input: daily stock prices
    int arr[] = {7, 1, 5, 3, 6, 4};
    // Compute number of days
    int n = sizeof(arr) / sizeof(arr[0]);
    // Call optimal function and print result
    cout << "Maximum profit is " << maxSubArraySumOptimal(arr, n);
    return 0;
}
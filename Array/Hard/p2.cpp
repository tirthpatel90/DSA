// Merge Overlaping Intervals
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: Sort intervals and merge overlapping ones.
// Time Complexity: O(n log n) + O(n) - due to sorting and single pass.
// Space Complexity: O(n) - in the worst case, all intervals are non-overlapping and we store them all.
// Steps:
// 1) Sort intervals by start time so overlapping intervals come close together.
// 2) Iterate through sorted intervals and pick one as start of potential merged interval.
// 3) For each interval, check forward to find all overlapping intervals.
// 4) Merge all overlapping intervals by updating end to maximum end value.
// 5) Add the merged interval to result and skip all intervals that were merged.
// 6) Continue from the next non-overlapping interval.
vector<vector<int>> mergeIntervalsBruteforce(vector<vector<int>>& intervals) {

        // Step 1: Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        // Result array to store merged intervals
        vector<vector<int>> ans;

        // Loop through each interval
        int n = intervals.size();
        // Step 2: Start outer loop to process intervals
        for (int i = 0; i < n; ) {

            // Step 2: Initialize the start of current merged interval
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Step 3-4: Merge with all overlapping intervals
            int j = i + 1;
            while (j < n && intervals[j][0] <= end) {
                // Step 4: Update end to the maximum of current end and overlapping interval's end
                end = max(end, intervals[j][1]);
                j++; // Check next interval for overlap
            }

            // Step 5: Add the merged interval to result
            ans.push_back({start, end});

            // Step 6: Move to the next non-overlapping interval
            i = j;
        }

        return ans;
}

// Optimal Approach: Sort intervals and merge in a single pass.
// Time Complexity: O(n log n) - due to sorting.
// Space Complexity: O(n) - in the worst case, all intervals are non-overlapping and we store them all.
// Steps:
// 1) Sort intervals by start time to process them in order.
// 2) Initialize result with first interval (or handle empty case).
// 3) For each subsequent interval, check if it overlaps with last interval in result.
// 4) If no overlap, add current interval directly to result (start of new potential merge).
// 5) If overlap exists, merge by updating end of last interval to maximum of both ends.
// 6) Continue until all intervals are processed.
vector<vector<int>> mergeIntervalsOptimal(vector<vector<int>>& intervals) {

        // Step 1: Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        // Result array to store merged intervals
        vector<vector<int>> ans;

        // Step 2-6: Loop through each interval
        for (const auto& interval : intervals) {
            // Step 3-4: Check if current interval overlaps with last interval in result
            // If ans is empty OR current interval does not overlap with last interval in ans
            if (ans.empty() || ans.back()[1] < interval[0]) {
                // No overlap: add current interval to result
                ans.push_back(interval);
            } else {
                // Step 5: Overlapping intervals, merge by updating the end of last interval
                // Update end to maximum to capture the extended range
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
}

int main() {
    // Sample input: overlapping intervals
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
    // --- BRUTE FORCE APPROACH ---
    // Uncomment the lines below to run brute force approach.
    // Uses nested loop to find and merge all overlapping intervals.
    // vector<vector<int>> mergedBruteForce = mergeIntervalsBruteforce(intervals);
    // cout << "Merged Intervals (Brute Force):" << endl;
    // for (const auto& interval : mergedBruteForce) {
    //     cout << "[" << interval[0] << ", " << interval[1] << "] ";
    // }
    // cout << endl;

    // --- OPTIMAL APPROACH ---
    // Running optimal approach by default.
    // Uses single pass with result tracking for efficient merging.
    vector<vector<int>> mergedOptimal = mergeIntervalsOptimal(intervals);
    cout << "Merged Intervals (Optimal):" << endl;
    for (const auto& interval : mergedOptimal) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
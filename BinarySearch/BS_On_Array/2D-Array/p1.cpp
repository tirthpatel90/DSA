// Find the row with maximum number of 1's
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute force approach :
// - Idea: For each row, simply count how many 1's it contains by scanning every column.
// - Keep track of the largest count found so far and which row had that count.
// Why this is easy to understand: we check every element once and compare counts.
// Time complexity: O(m * n) where m = number of rows, n = number of columns.
// Space complexity: O(1) — only a few variables used for counting and tracking the index.
// Detailed steps (plain language):
// 1) Start with maxCount = 0 and maxRowIndex = -1 (meaning "none found yet").
// 2) For each row i:
//    a) Set a counter `count = 0`.
//    b) For each column j in row i, if matrix[i][j] == 1 increment `count`.
//    c) After scanning the row, if `count` is greater than `maxCount`, update `maxCount` and `maxRowIndex = i`.
// 3) After all rows, `maxRowIndex` is the zero-based index of the row with the most 1's (or -1 if none).
int rowWithMaxOnesBruteForce(const vector<vector<int>>& matrix) {
    int maxCount = 0;
    int maxRowIndex = -1;

    for (size_t i = 0; i < matrix.size(); ++i) {
        int count = 0;
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            // Read each element in the row and increment the running count when we see a 1.
            if (matrix[i][j] == 1) {
                count++;
            }
        }
        // After counting this row, compare with the global maximum and update if needed.
        if (count > maxCount) {
            maxCount = count;
            maxRowIndex = i;
        }
    }
    return maxRowIndex;
}

// Better approach:
// - Key observation: in each row, all 1's (if any) appear to the right side because rows are sorted (0..0,1..1).
// - If you start at the top-right element, you can decide to move left when you see a 1 (to count more 1's
//   in that same row), or move down when you see a 0 (because moving left cannot reveal a 1 above).
// - This guarantees at most one left move per column and one down move per row, for O(m+n) total steps.
// Time complexity: O(m + n). Space: O(1).
// Plain steps:
// 1) Start at (row = 0, col = n-1) — top-right corner.
// 2) While row < m and col >= 0:
//    a) If matrix[row][col] == 1: we found a 1 in this row — move left (col--) to look for more 1's in same row and
//       update the best row index (because moving left increases the count of 1's for this row).
//    b) Else (matrix[row][col] == 0): this column cannot contain a 1 for this row or any row above, so move down
//       to the next row (row++).
// 3) When the loop ends, the recorded row index is the one with maximum 1's.
int rowWithMaxOnesOptimal(const vector<vector<int>>& matrix) {
    int maxCount = 0;
    int maxRowIndex = -1;
    int j = matrix[0].size() - 1; // Start from the top-right corner

    for (size_t i = 0; i < matrix.size(); ++i) {
        // Move left as long as we see 1's in the current row. Each left move increases
        // the number of 1's for this row (because columns to the right are 1).
        while (j >= 0 && matrix[i][j] == 1) {
            j--; // Move left to try to find an earlier 1 in the same row
            // Number of 1's in this row equals (total columns) - (first 1 index)
            int count = matrix[0].size() - j - 1; // Count of 1's in the current row
            if (count > maxCount) {
                maxCount = count;
                maxRowIndex = i;
            }
        }
        // If matrix[i][j] == 0, we will move to the next row in the for-loop; no extra action needed here.
        // Important: `j` only moves left across the whole algorithm, never resets — that is why complexity is O(m+n).
    }
    return maxRowIndex;
}

// Binary search approach :
// - Since each row is sorted (0's followed by 1's), the first position where 1 appears tells us how many 1's are in that row.
// - We can use `lower_bound` to find the first 1 quickly in O(log n) per row.
// Time complexity: O(m * log n). Space: O(1).
// Plain steps:
// 1) For each row i, call lower_bound(row.begin(), row.end(), 1) to find the first index where value >= 1.
// 2) The count of 1's in that row equals (number of columns - index returned by lower_bound).
// 3) Compare with the running maximum and update the best row index if needed.
int rowWithMaxOnesBinarySearch(const vector<vector<int>>& matrix) {
    int maxCount = 0;
    int maxRowIndex = -1;

    for (size_t i = 0; i < matrix.size(); ++i) {
        // Use binary search (lower_bound) to locate the first 1 in this row.
        auto it = lower_bound(matrix[i].begin(), matrix[i].end(), 1);
        // distance(it, end) gives how many elements from `it` to the end — i.e., number of 1's.
        int count = distance(it, matrix[i].end()); // Count of 1's is total columns - index of first 1
        if (count > maxCount) {
            maxCount = count;
            maxRowIndex = i;
        }
        // Note: when the row contains no 1's, lower_bound returns end(), and distance is 0.
        // When the row is all 1's, lower_bound returns begin(), and distance is full column count.
    }
    return maxRowIndex;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1}
    };

    // --- RUN OPTIONS ---
    // Brute Force: simple and easy to understand; good for small matrices or learning.
    cout << "Row with maximum number of 1's (Brute Force): " << rowWithMaxOnesBruteForce(matrix) << endl;
    // Better (top-right walk): fast and uses O(m+n) time — good when rows are sorted.
    cout << "Row with maximum number of 1's (Top-right walk): " << rowWithMaxOnesOptimal(matrix) << endl;
    // Binary Search per-row: uses binary search on each row; O(m log n) time.
    cout << "Row with maximum number of 1's (Binary Search per row): " << rowWithMaxOnesBinarySearch(matrix) << endl;

    // --- DRY RUN (step-by-step) for the Top-right walk on the sample matrix ---
    // matrix:
    // row0: 0 0 0 1
    // row1: 0 1 1 1
    // row2: 0 0 1 1
    // row3: 1 1 1 1
    // Start at top-right (row=0, col=3): value = 1 -> move left (col=2), count for row0 becomes 1.
    // Still row0 col=2 value=0 -> stop moving left for row0, move to row1.
    // row1 col=2 value=1 -> move left (col=1), count for row1 increases to 2, move left (col=0) value=0 -> stop.
    // Continue similarly — final best row found is row3 which has 4 ones.

    return 0;
}
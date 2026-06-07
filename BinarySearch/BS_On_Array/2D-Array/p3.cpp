// Search a 2D Matrix II (clear explanation)
// Problem idea in plain language:
// - The matrix has rows and columns sorted in increasing order.
// - If you look at the top-right element, everything to its left is smaller (in same row)
//   and everything below it is larger (in same column). That gives a strong ordering
//   property we can exploit.
// Key observation (why the method works):
// - From top-right, if current > target, then the current column cannot contain target
//   because everything below is even larger; so we can safely move left (remove a column).
// - From top-right, if current < target, then the current row cannot contain target
//   in earlier columns because everything left is smaller, but elements below may be larger,
//   so we move down (remove a row).
// This eliminates either a full row or a full column each step, so at most m+n steps.
// Time complexity: O(m + n) where m = rows, n = columns. Space complexity: O(1).
// Note: brute-force and per-row binary-search approaches are similar to p2.cpp; this file focuses
// on the top-right walking method which is simple and efficient.
#include <iostream>
#include <vector>
using namespace std;
bool searchMatrixOptimal(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false; // Handle empty matrix case
    }
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    // Start at the top-right corner: first row, last column.
    // Why top-right? It gives a clear decision: move left to decrease value, move down to increase value.
    int row = 0; // Start from the top row
    int col = m - 1; // Start from the rightmost column
    
    while (row < n && col >= 0) {
        // Read the current element at (row, col).
        int cur = matrix[row][col];
        // If equal, we found the target.
        if (cur == target) {
            return true; // Target found
        }
        // If current element is larger than target, then everything in this column below
        // (same col, larger row index) is also >= cur, hence >= target; so we can discard
        // this column by moving left.
        else if (cur > target) {
            col--; // Move left to find smaller values
        }
        // If current element is smaller than target, then everything to the left in this row
        // is even smaller, so the target can't be left of current; move down to get larger values.
        else {
            row++; // Move down to find larger values
        }
    }
    
    return false; // Target not found after traversing the matrix
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 22;
    
    // --- RUN OPTIONS ---
    // This file provides the top-right walking method which is fast and simple.
    bool found = searchMatrixOptimal(matrix, target);
    if (found) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    // --- DRY RUN (step-by-step) for target = 22 ---
    // matrix:
    // [1,  4,  7, 11, 15]
    // [2,  5,  8, 12, 19]
    // [3,  6,  9, 16, 22]
    // [10,13, 14,17, 24]
    // [18,21, 23,26, 30]
    // Start at top-right: (0,4) = 15. 15 < 22 -> move down to row 1.
    // (1,4) = 19. 19 < 22 -> move down to row 2.
    // (2,4) = 22. 22 == 22 -> found. The search took 3 checks and returned true.
    
    return 0;
}
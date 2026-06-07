// Find Peak Element in a 2D Matrix
// - Idea: A peak element is an element that is greater than its neighbors.
//   We can use a modified binary search approach to find a peak element efficiently.

#include <iostream>
#include <vector>
using namespace std;

// Brute force approach (clear explanation):
// - Idea: For each element, compare it with its immediate neighbors (up, down, left, right).
// - If the element is greater than all of its valid neighbors, it is a peak.
// - This is the simplest approach and easy to reason about: we literally check every cell.
// Time complexity: O(m * n) because we may check all elements; Space complexity: O(1).
bool isPeak(const vector<vector<int>>& matrix, int i, int j) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Check the four neighbors (up, down, left, right)
    if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
        return false; // Not a peak, neighbor above is greater
    }
    if (i < m - 1 && matrix[i][j] < matrix[i + 1][j]) {
        return false; // Not a peak, neighbor below is greater
    }
    if (j > 0 && matrix[i][j] < matrix[i][j - 1]) {
        return false; // Not a peak, neighbor to the left is greater
    }
    if (j < n - 1 && matrix[i][j] < matrix[i][j + 1]) {
        return false; // Not a peak, neighbor to the right is greater
    }
    
    return true; // This element is a peak
}

// Optimal approach (modified binary search) — easy explanation:
// - Idea in plain language: instead of checking every cell, pick a column (middle column),
//   find the maximum element in that column, and use its left/right neighbor to decide which
//   half of columns to keep searching. Repeat this until you find a peak. This is similar to
//   binary search but on columns, using the column-max as a guide.
// - Why it works: the maximum in the middle column is a local guide — if it is greater than
//   both side neighbors, it must be a peak (because it's the largest in its column and larger
//   than left/right). Otherwise, a larger neighbor points the direction where a peak must exist.
// Time complexity: O(n * log m) or O(m * log n) depending on orientation; Space complexity: O(1).
pair<int, int> findPeakElement(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    int left = 0, right = m - 1;

    // Binary search over columns
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Step: find the row with the maximum value in column `mid`.
        // This gives a strong candidate because the maximum in a column cannot be dominated by
        // values in the same column; comparing it with left/right neighbors tells where a peak lies.
        int maxRow = 0;
        for (int i = 0; i < n; ++i) {
            if (matrix[i][mid] > matrix[maxRow][mid]) {
                maxRow = i;
            }
        }

        // Current candidate value at (maxRow, mid)
        int curr = matrix[maxRow][mid];

        // Check if left neighbor in the same row is larger than this candidate
        bool leftBigger = (mid - 1 >= 0 && matrix[maxRow][mid - 1] > curr);
        // Check if right neighbor in the same row is larger than this candidate
        bool rightBigger = (mid + 1 < m && matrix[maxRow][mid + 1] > curr);

        // If neither left nor right neighbor is bigger, this candidate is a peak:
        // it's the largest in its column and not smaller than its row neighbors.
        if (!leftBigger && !rightBigger) {
            return {maxRow, mid};
        }

        // Otherwise move the binary search window toward the side that has a bigger neighbor.
        // If left neighbor is bigger, a peak must exist in columns to the left; otherwise to the right.
        if (leftBigger) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return {-1, -1}; // No peak found (should not happen in a valid input)
}

int main() {
    vector<vector<int>> matrix = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };
    
    pair<int, int> peak = findPeakElement(matrix);
    if (peak.first != -1) {
        cout << "Peak element found at position (" << peak.first << ", " << peak.second << ") with value " << matrix[peak.first][peak.second] << "." << endl;
    } else {
        cout << "No peak element found in the matrix." << endl;
    }

    // --- DRY RUN (step-by-step) for the sample matrix ---
    // matrix:
    // [10, 20, 15]
    // [21, 30, 14]
    // [7,  16, 32]
    // 1) left=0, right=2 -> mid=1 (middle column)
    // 2) column 1 values: [20,30,16] -> maxRow = 1 (value 30)
    // 3) neighbors in row 1: left=21, right=14 -> neither left nor right > 30, so (1,1) is a peak
    // The algorithm finds peak at (1,1) with value 30 in a single iteration.

    return 0;
}
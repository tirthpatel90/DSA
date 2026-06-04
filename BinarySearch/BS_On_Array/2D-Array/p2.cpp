// Search in a sorted 2D matrix (matrix is sorted row-wise and column-wise)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute force approach :
// - Idea: Check every element in the matrix until we find the target.
// - When to use: small matrices or when you want the easiest, most obvious solution.
// Time complexity: O(m * n) because we may examine all elements.
// Space complexity: O(1) — only a few variables.
// Plain-step plan:
// 1) Loop over every row and inside that loop over every column.
// 2) Compare matrix[i][j] with `target` and return true immediately if they match.
// 3) If no match after the full scan, return false.
bool searchMatrixBruteForce(const vector<vector<int>>& matrix, int target) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == target) {
                return true; // Target found
            }
        }
    }
    return false; // Target not found after full traversal
}


// Better approach (per-row binary search) — clear explanation:
// - Idea: Each row is sorted. For each row, first check if `target` is between the row's first and last elements.
//   If it is, use binary search on that single row. This avoids searching rows that cannot contain the target.
// Time complexity: O(m * log n) — binary search on at most m rows.
// Space complexity: O(1).
// Plain-step plan:
// 1) For every row, if row is non-empty and target is between row.front() and row.back(), do binary_search on it.
// 2) If found in any row, return true; if not found in any candidate row, return false.
bool searchMatrixBinarySearch(const vector<vector<int>>& matrix, int target) {
    for (const auto& row : matrix) {
        // Step 1: Check if target can be in this row
        if (!row.empty() && target >= row.front() && target <= row.back()) {
            // Step 2: Perform binary search on this row
            if (binary_search(row.begin(), row.end(), target)) {
                return true; // Target found in this row
            }
        }
    }
    return false; // Target not found in any row
}

// Optimal approach (flattened binary search) — clear explanation:
// - Idea: If the entire matrix is row-major sorted (each row's first element > previous row's last element),
//   we can treat the matrix like a single sorted array and do one binary search over m*n elements.
// - This is faster than searching each row separately because it costs O(log(m*n)).
// - If the matrix is not globally row-major-sorted, we fall back to the per-row binary-search approach above.
// Time complexity: O(log(m*n)) when the flattening precondition holds; otherwise O(m log n) fallback.
// Space complexity: O(1).
// Plain-step plan:
// 1) Verify the precondition for flattening: for every row i>0, matrix[i][0] should be > matrix[i-1][last].
// 2) If precondition fails, do the per-row binary search fallback.
// 3) Otherwise, perform normal binary search on indices [0, m*n - 1]. For any mid index compute:
//    row = mid / n, col = mid % n, and compare matrix[row][col] with target.
// 4) Move low/high accordingly until found or exhausted.
bool searchMatrixOptimal(vector<vector<int>>& matrix, int target) {
        // Flattened binary search requires the matrix to be globally
        // row-major sorted: each row's first element must be greater
        // than the previous row's last element. If that precondition
        // doesn't hold, fall back to per-row binary searches.
        if (matrix.empty() || matrix[0].empty()) return false;

        int n = matrix.size();
        int m = matrix[0].size();

        bool rowMajorSorted = true;
        for (int i = 1; i < n; ++i) {
            if (matrix[i][0] < matrix[i-1][m-1]) { rowMajorSorted = false; break; }
        }

        if (!rowMajorSorted) {
            // Fallback: matrix is not globally flattened, so search each candidate row.
            for (const auto& row : matrix) {
                if (!row.empty() && target >= row.front() && target <= row.back()) {
                    if (binary_search(row.begin(), row.end(), target)) return true;
                }
            }
            return false;
        }

        int low = 0, high = n * m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m; // integer division gives the row index
            int col = mid % m; // remainder gives the column index
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target = 5;

    cout << "Brute Force: " << (searchMatrixBruteForce(matrix, target) ? "Found" : "Not Found") << endl;
    cout << "Binary Search: " << (searchMatrixBinarySearch(matrix, target) ? "Found" : "Not Found") << endl;
    cout << "Optimal Binary Search: " << (searchMatrixOptimal(matrix, target) ? "Found" : "Not Found") << endl;

    return 0;
}
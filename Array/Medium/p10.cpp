// Set Matrix Zeroes
// Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.

#include <iostream>
#include <vector>

using namespace std;

//Brute force approach: find each element which is in row and column of 0 and marks them as -1. Then change all -1 to 0.
//Time complexity: O(m*n*(m+n)) where m and n are number of rows and columns respectively. nearly O(n^3)
//Space complexity: O(m*n) for storing the modified matrix.
// Steps:
// 1) Traverse every cell of the matrix.
// 2) When a 0 is found, mark its full row and full column as -1 (only non-zero cells).
// 3) Use -1 as a temporary marker so original zeroes remain identifiable during traversal.
// 4) After full traversal, convert all -1 markers to 0.
void setZeroesBruteForce(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Step 1: Visit each element to detect original zeroes
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                // Step 2: Mark the complete row of this zero
                for (int k = 0; k < n; k++) {
                    if (matrix[i][k] != 0) {
                        matrix[i][k] = -1;
                    }
                }
                // Step 2: Mark the complete column of this zero
                for (int k = 0; k < m; k++) {
                    if (matrix[k][j] != 0) {
                        matrix[k][j] = -1;
                    }
                }
            }
        }
    }

    // Step 4: Final pass to convert temporary markers into real zeroes
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}

// Better approach : mark row and column to 1 if there is 0 in that row and column. Then change all marked row and column to 0.
//Time complexity: O(m*n) where m and n are number of rows and columns respectively 
//Space complexity: O(m+n) for storing the marked rows and columns.
// Steps:
// 1) Create two helper arrays to remember which rows and columns must become zero.
// 2) Scan matrix once and mark row[i], col[j] when matrix[i][j] is zero.
// 3) Scan matrix again and set matrix[i][j] to zero if row[i] or col[j] is marked.
void setZeroesBetter(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // Step 1: row[] and col[] store zero flags for rows and columns
    vector<bool> row(m, false);
    vector<bool> col(n, false);

    // Step 2: Identify all rows/columns that contain at least one zero
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    // Step 3: Apply zero to every cell whose row or column was marked
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

// Optimal approach: use first row and first column as markers to indicate which rows and columns should be set to zero.
//Time complexity: O(m*n) where m and n are number of rows and columns respectively
//Space complexity: O(1) as we are using the input matrix itself for marking.
// Steps:
// 1) Check separately whether first row or first column originally contains any zero.
// 2) For remaining cells, when matrix[i][j] is zero, mark matrix[i][0] and matrix[0][j] as zero.
// 3) Use these markers to set inner matrix cells to zero.
// 4) Finally zero-out first row/column if they were originally flagged.
void setZeroesOptimal(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // Flags for original zero presence in first row and first column
    bool firstRowZero = false;
    bool firstColZero = false;

    // Step 1: Check first row
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // Step 1: Check first column
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    // Step 2: Mark rows/columns using first column and first row
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Step 3: Fill inner cells based on row/column markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 4: Apply first-row flag
    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 4: Apply first-column flag
    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    // Sample matrix input
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    // Run any one approach at a time:
    // 1) Brute Force:
    // setZeroesBruteForce(matrix);

    // 2) Better:
    // setZeroesBetter(matrix);

    // 3) Optimal (currently active):
    setZeroesOptimal(matrix);

    // Print resulting matrix after transformation
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
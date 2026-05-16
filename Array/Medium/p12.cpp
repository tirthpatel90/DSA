// Spiral Matrix
#include <iostream>
#include <vector>
using namespace std;

// Only one optimal approach: Use four pointers to traverse the matrix in spiral order.
// Time Complexity: O(m*n) - visit each cell exactly once
// Space Complexity: O(1) - excluding the output vector
// This function takes a 2D matrix and returns a vector containing the elements of the matrix in spiral order.
// Steps:
// 1) Initialize four pointers: top, bottom, left, right to mark boundaries.
// 2) Traverse right along the top row, then shrink top boundary.
// 3) Traverse down along the right column, then shrink right boundary.
// 4) Traverse left along the bottom row (if remaining), then shrink bottom boundary.
// 5) Traverse up along the left column (if remaining), then shrink left boundary.
// 6) Repeat until all boundaries converge.
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    // Step 1: Base condition - if matrix is empty, return empty result
    if (matrix.empty()) return result;

    // Step 1: Initialize four pointers for matrix boundaries
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    // Continue spiral traversal while boundaries haven't crossed
    while (top <= bottom && left <= right) {
        // Step 2: Traverse from left to right along the top row
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++; // Shrink top boundary after processing top row

        // Step 3: Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--; // Shrink right boundary after processing right column

        // Step 4: Traverse from right to left along the bottom row (if it still exists)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--; // Shrink bottom boundary after processing bottom row
        }

        // Step 5: Traverse from bottom to top along the left column (if it still exists)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++; // Shrink left boundary after processing left column
        }
    }

    // Step 6: Return the result containing all elements in spiral order
    return result;
}

int main() {
    // Sample matrix input
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // --- OPTIMAL APPROACH: Four Pointers ---
    // This is the only efficient approach for spiral traversal.
    // Traverse boundaries in order: top→right, right→down, bottom→left, left→up
    vector<int> spiral = spiralOrder(matrix);
    
    // Print the spiral traversal result
    cout << "Spiral Order: ";
    for (int num : spiral) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
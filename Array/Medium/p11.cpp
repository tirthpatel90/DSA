// Rotate Matrix by 90 degrees

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Brute force approach: create a new matrix and fill it by rotating the original matrix.
// Time Complexity: O(n^2), Space Complexity: O(n^2)
// Steps:
// 1) Create a new matrix of the same size as the original.
// 2) For each element in the original matrix, place it in the rotated position in the new matrix.
// 3) Replace the original matrix with the new matrix.
void rotateBruteForce(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n)); // Step 1: Create a new matrix

    // Step 2: Fill the new matrix with rotated values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - 1 - i] = matrix[i][j]; // Place element in rotated position
        }
    }

    // Step 3: Replace original matrix with the rotated one
    matrix = rotated;
}

// Optimal approach: Rotate the matrix in place by first transposing it and then reversing each row.
// Time Complexity: O(n^2), Space Complexity: O(1)
// Steps:
// 1) Transpose the matrix by swapping elements across the diagonal.
// 2) Reverse each row to achieve the final rotated state.
void rotateOptimal(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    // Rotate the matrix using the brute force approach
    // rotateBruteForce(matrix); // Uncomment to use the brute force approach  
    //for (const auto& row : matrix) {
    //    for (int val : row) {
    //        cout << val << " ";
    //    }
    //    cout << endl;
    // }
    // Rotate the matrix using the optimal approach
    rotateOptimal(matrix); // Rotate the matrix

    cout << "Rotated Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
// Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1
// Compute how much water it can trap after raining.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Brute force approach:
// For each element, find the maximum height to its left and right. using prefix and suffix max arrays.
// The water trapped at that index is min(max_left, max_right) - height[i]
// leftmax is prefix max array and rightmax is suffix max array.
// Time Complexity: O(3n) cause we traverse 3 arrays of size n. prefix max, suffix max and result array.
// Space Complexity: O(3n) cause we use 3 arrays of size n. prefix max, suffix max and result array.
int trapBruteForce(vector<int> height) {
    int n = height.size(); 
    if (n == 0) return 0;// Edge case: If the array is empty, no water can be trapped.

    vector<int> leftMax(n), rightMax(n); // Arrays to store the maximum height to the left and right of each index.
    leftMax[0] = height[0]; // Initialize the first element of leftMax with the first height.
    for (int i = 1; i < n; i++) { // Fill the leftMax array with the maximum height to the left of each index.
        leftMax[i] = max(leftMax[i - 1], height[i]); // Update leftMax[i] to be the maximum of the previous leftMax and the current height.
    }

    rightMax[n - 1] = height[n - 1]; // Initialize the last element of rightMax with the last height.
    for (int i = n - 2; i >= 0; i--) { // Fill the rightMax array with the maximum height to the right of each index.
        rightMax[i] = max(rightMax[i + 1], height[i]); // Update rightMax[i] to be the maximum of the next rightMax and the current height.
    }

    int waterTrapped = 0; 
    for (int i = 0; i < n; i++) { // Calculate the water trapped at each index.
        waterTrapped += min(leftMax[i], rightMax[i]) - height[i]; // The water trapped at index i is the minimum of the maximum heights to its left and right minus its own height.
    }

    return waterTrapped; // Return the total water trapped.
}

// Optimal approach using two pointers:
int trapOptimal(vector<int> height) { // Initialize two pointers and variables to keep track of the maximum heights from both ends.
    int n = height.size();
    if (n == 0) return 0;

    int left = 0, right = n - 1; // Pointers to traverse the array from both ends.
    int leftMax = 0, rightMax = 0; // Variables to keep track of the maximum heights encountered from the left and right sides.
    int waterTrapped = 0; // Variable to accumulate the total water trapped.

    while (left < right) { // Continue until the two pointers meet.
        if (height[left] < height[right]) { // If the height at the left pointer is less than the height at the right pointer, process the left side.
            if (height[left] >= leftMax) { // Update leftMax if the current height is greater than or equal to leftMax.
                leftMax = height[left]; 
            } else { // If the current height is less than leftMax, water can be trapped at this index. 
                waterTrapped += leftMax - height[left];
            }
            left++;
        } else { // If the height at the right pointer is less than or equal to the height at the left pointer, process the right side.
            if (height[right] >= rightMax) { // Update rightMax if the current height is greater than or equal to rightMax.
                rightMax = height[right];
            } else { // If the current height is less than rightMax, water can be trapped at this index.
                waterTrapped += rightMax - height[right];
            }
            right--;
        }
    }

    return waterTrapped;
}

int main() {
    int n;
    cout << "Enter size of array: "; // Prompt the user to enter the size of the elevation map.
    cin >> n;
    vector<int> height(n); // Create a vector to store the heights of the elevation map.
    cout << "Enter the heights: "; // Prompt the user to enter the heights of the elevation map.
    for (int i = 0; i < n; i++) { // Read the heights from the user and store them in the height vector.
        cin >> height[i];
    }

    int result = trapOptimal(height); // You can also call trapBruteForce(height) to test the brute force approach.
    cout << "Total water trapped: " << result << endl;

    return 0;
}
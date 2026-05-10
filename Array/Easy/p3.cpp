#include <iostream>
#include <vector>
using namespace std;

// ============================================
// UNDERSTANDING ARRAY IS SORTED AND FOR EVEN CHECKING ROTATION 
// ============================================
//
// A sorted array rotated looks like:
//
// Original sorted:  [1, 2, 3, 4, 5]
//
// Rotate 0 times:   [1, 2, 3, 4, 5]  ← no break
// Rotate 1 time:    [5, 1, 2, 3, 4]  ← break at index 0 (5>1)
// Rotate 2 times:   [4, 5, 1, 2, 3]  ← break at index 1 (5>1)
// Rotate 3 times:   [3, 4, 5, 1, 2]  ← break at index 2 (5>1)
// Rotate 4 times:   [2, 3, 4, 5, 1]  ← break at index 3 (5>1)
//
// KEY INSIGHT: There's EXACTLY ONE point where a[i] > a[i+1]
//              (except when no rotation, then NO break points)
//
// Invalid arrays have MULTIPLE break points:
// [2, 1, 3, 4] → breaks at index 0 (2>1) AND index 2 (3<4 not a break)
//              → This can NEVER be a rotation of sorted array!

bool check(vector<int>& nums) {
    int n = nums.size();
    int breakCount = 0;
    
    // Step 1: Count where array order "breaks" (a[i] > a[i+1])
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            breakCount++;
        }
    }
    
    // Step 2: Analyze break count
    // breakCount = 0: Already sorted, no rotation → TRUE
    // breakCount = 1: One rotation occurred
    // breakCount > 1: Multiple breaks = impossible for rotated sorted → FALSE
    
    if (breakCount > 1) {
        return false;
    }
    if (breakCount == 0) {
        return true;
    }
    
    // Step 3: If exactly 1 break, verify the "wrap around"
    // For a valid rotation, last element must be <= first element
    // This is because the smaller numbers wrap back to the beginning
    //
    // Example: [3, 4, 5, 1, 2]
    //          ↑ first         ↑ last
    //          We need: last (2) <= first (3) ✓
    //
    // Invalid: [3, 4, 5, 6, 1]
    //          ↑ first         ↑ last
    //          Check: last (1) <= first (3) ✓ 
    //          But wait, this should actually be VALID!
    //          [3,4,5,6,1] is rotation of [1,3,4,5,6]? 
    //          NO! Original was [1,2,3,4,5] not [1,3,4,5,6]
    //
    // So the condition works because we're already checking
    // all previous elements follow sorted pattern
    
    return nums[n - 1] <= nums[0];
}

int main() {
    cout << "========== ROTATION DETECTION ==========" << endl << endl;
    
    // TEST 1: Typical rotated array
    cout << "Test 1: [3, 4, 5, 1, 2]" << endl;
    cout << "        3 < 4? YES (no break)" << endl;
    cout << "        4 < 5? YES (no break)" << endl;
    cout << "        5 > 1? YES (BREAK! breakCount=1)" << endl;
    cout << "        1 < 2? YES (no break)" << endl;
    cout << "        Check: last(2) <= first(3)? YES → TRUE" << endl;
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Result: " << (check(nums1) ? "true" : "false") << endl << endl;
    
    // TEST 2: Invalid - has 2 breaks
    cout << "Test 2: [2, 1, 3, 4]" << endl;
    cout << "        2 > 1? YES (BREAK! breakCount=1)" << endl;
    cout << "        1 < 3? YES (no break)" << endl;
    cout << "        3 < 4? YES (no break)" << endl;
    cout << "        If only 1 break, last(4) <= first(2)? NO → FALSE" << endl;
    vector<int> nums2 = {2, 1, 3, 4};
    cout << "Result: " << (check(nums2) ? "true" : "false") << endl << endl;
    
    // TEST 3: Already sorted
    cout << "Test 3: [1, 2, 3, 4, 5]" << endl;
    cout << "        1 < 2 < 3 < 4 < 5" << endl;
    cout << "        breakCount = 0 (no breaks) → TRUE" << endl;
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Result: " << (check(nums3) ? "true" : "false") << endl << endl;
    
    // TEST 4: Simple rotation
    cout << "Test 4: [2, 1]" << endl;
    cout << "        2 > 1? YES (BREAK! breakCount=1)" << endl;
    cout << "        last(1) <= first(2)? YES → TRUE" << endl;
    vector<int> nums4 = {2, 1};
    cout << "Result: " << (check(nums4) ? "true" : "false") << endl << endl;
    
    // TEST 5: With duplicates (valid rotation)
    cout << "Test 5: [3, 4, 5, 6, 1, 2]" << endl;
    cout << "        breakCount = 1 at 6>1" << endl;
    cout << "        last(2) <= first(3)? YES → TRUE" << endl;
    vector<int> nums5 = {3, 4, 5, 6, 1, 2};
    cout << "Result: " << (check(nums5) ? "true" : "false") << endl << endl;
    
    // TEST 6: Invalid - multiple breaks
    cout << "Test 6: [1, 3, 2]" << endl;
    cout << "        1 < 3? YES (no break)" << endl;
    cout << "        3 > 2? YES (BREAK! breakCount=1)" << endl;
    cout << "        last(2) <= first(1)? NO → FALSE" << endl;
    vector<int> nums6 = {1, 3, 2};
    cout << "Result: " << (check(nums6) ? "true" : "false") << endl << endl;
    
    return 0;
}


/*
============================================
SIMPLE EXPLANATION OF THE LOGIC
============================================

You know:    a[i] >= a[i-1] checks if sorted
Now:         a[i] > a[i+1] checks for BREAK points

WHY BREAK POINTS?

When you rotate a sorted array, you're moving elements from 
the end to the beginning.

ORIGINAL:     [1, 2, 3, 4, 5]
ROTATE 0:     [1, 2, 3, 4, 5]      ← 1 >= 2? No. Still sorted!
ROTATE 1:     [5, 1, 2, 3, 4]      ← 5 > 1? YES! BREAK FOUND
ROTATE 2:     [4, 5, 1, 2, 3]      ← 5 > 1? YES! BREAK FOUND
ROTATE 3:     [3, 4, 5, 1, 2]      ← 5 > 1? YES! BREAK FOUND
ROTATE 4:     [2, 3, 4, 5, 1]      ← 5 > 1? YES! BREAK FOUND

KEY RULE: A valid rotated sorted array has EXACTLY 1 break point
          (where a[i] > a[i+1])

Why only 1 break?
- The original array has 2 parts when rotated: [right part] [left part]
- Right part is sorted: 3 < 4 < 5
- Left part is sorted: 1 < 2  
- Between them: 5 > 1 (THE ONLY BREAK!)

If you have MORE breaks, it means the array itself isn't sorted:
[2, 1, 3, 4]  → 2 > 1 (break), then later 1 < 3 (continuing)
              → This isn't a rotation of a sorted array!

EXTRA CHECK (the last line):
When there's 1 break, we also check: last element <= first element
This is the "wrap around" - the rotated part that went to the back
must be smaller than what's at the front.

[3, 4, 5, 1, 2]
 ↑ first      ↑ last
last (2) <= first (3)? YES → Valid rotation!

============================================
TIME: O(n)  - One loop through array
SPACE: O(1) - Just one variable (breakCount)
============================================
*/
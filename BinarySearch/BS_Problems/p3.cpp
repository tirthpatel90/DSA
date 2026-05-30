// Koko Eating Bananas
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach: check each possible speed from 1 to max pile size and calculate total hours needed.
// Time complexity: O(N * log M) where N is number of piles and M is the maximum pile size (worst case).
// Space complexity: O(1)
// Steps:
// 1) Find the maximum pile size — that's the upper bound for speed.
// 2) For each candidate speed from 1..maxPile, compute total hours needed.
// 3) For a pile, hours = ceil(pile / speed) → implemented as (pile + speed - 1)/speed.
// 4) If total hours <= h, return the candidate speed as minimum feasible.

int minEatingSpeedBruteForce(const vector<int>& piles, int h) {
    int maxPile = 0;
    for (int pile : piles) {
        maxPile = max(maxPile, pile); // Find the maximum pile size
    }

    // Check each possible speed from 1 to maxPile
    for (int speed = 1; speed <= maxPile; ++speed) {
        int hoursNeeded = 0;
        // Step: for each pile, compute how many full hours are needed at this `speed`.
        for (int pile : piles) {
            // Use integer math to compute ceiling division: (pile + speed - 1) / speed
            hoursNeeded += (pile + speed - 1) / speed; // Hours for this pile
            // Early exit: if hours already exceed allowed `h`, no need to check remaining piles.
            if (hoursNeeded > h) break;
        }
        // If total hours fits within `h`, this `speed` is feasible; since we iterate from small to
        // large speeds, the first feasible speed is the minimum required.
        if (hoursNeeded <= h) {
            return speed; // Found the minimum speed that allows Koko to finish in time
        }
    }
    return -1; // This line should never be reached since maxPile is a valid speed
}

// Optimal approach: Use binary search to find the minimum eating speed efficiently.
// Time complexity: O(N * log M) where N is number of piles and M is the maximum pile size (worst case).
// Space complexity: O(1)
// Steps:
// 1) Set search range [low, high] where low=1 and high=max pile size.
// 2) While low<=high, test mid speed. Compute hours needed at `mid`.
// 3) If hoursNeeded <= h, mid is feasible — move left to find smaller feasible speed.
// 4) Else mid is too slow — move right to increase speed.
// 5) After loop, `low` will be the minimum feasible speed.
int minEatingSpeedBinarySearch(const vector<int>& piles, int h) {
    int low = 1; // Minimum possible speed
    int high = 0; // Maximum possible speed (max pile size)
    for (int pile : piles) {
        high = max(high, pile);
    }

    while (low <= high) {
        int mid = low + (high - low) / 2; // Midpoint speed to test
        int hoursNeeded = 0;
        // Compute total hours for this `mid` speed, with early exit if exceeding `h`.
        for (int pile : piles) {
            hoursNeeded += (pile + mid - 1) / mid; // Hours for this pile at speed `mid`
            if (hoursNeeded > h) break; // No need to continue if already impossible
        }
        // If `mid` allows finishing within `h`, it is a candidate; try smaller speeds.
        if (hoursNeeded <= h) {
            high = mid - 1; // Mid is a valid speed, try to find a smaller one
        } else {
            // Mid is too slow; try larger speeds.
            low = mid + 1; // Mid is too slow, try a faster speed
        }
    }
    return low; // Low is the minimum valid speed after binary search completes
}

int main() {
    vector<int> piles = {3, 6, 7, 11}; // Piles of bananas
    int h = 8; // Hours available

    // --- RUN OPTIONS ---
    // Brute force: check each speed from 1 to max pile size
    cout << "Minimum eating speed (Brute Force): " << minEatingSpeedBruteForce(piles, h) << endl;

    // Binary search: efficiently find minimum speed
    cout << "Minimum eating speed (Binary Search): " << minEatingSpeedBinarySearch(piles, h) << endl;

    return 0;
}

// --- SUGGESTED TESTS ---
// 1) piles = {3,6,7,11}, h = 8 -> expected 4
// 2) piles = {30,11,23,4,20}, h = 5 -> expected 30
// 3) piles = {312884470}, h = 968709470 -> large single pile test
// Note: These tests demonstrate brute vs optimal behavior and edge cases.
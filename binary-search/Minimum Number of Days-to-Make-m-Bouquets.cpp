// LeetCode 1482 - Minimum Number of Days to Make m Bouquets
// Topic: Array + Binary Search
// Difficulty: Medium
// Time Complexity: O(nlog(maxDay))

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();

    if ((long long)m * k > n) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = INT_MIN;

    while (low < high) {
        int mid = low + (high - low) / 2;

        int count = 0;
        int bouquets = 0;

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        if (bouquets >= m) {
            ans = mid;
            high = mid-1;   
        } else {
            low = mid + 1; 
        }
    }

    return low;
}
};

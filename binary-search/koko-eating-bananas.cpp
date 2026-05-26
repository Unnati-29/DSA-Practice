// LeetCode 875 - Koko Eating Bananas
// Topic: Array + Binary Search
// Difficulty: Medium
// Time Complexity: O(NlogM)


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
             long long hours = 0;

        for(int i=0;i<piles.size();i++){
            hours += (piles[i] + mid - 1) / mid;
        }

        if (hours <= h) {
            ans = mid;
            high = mid-1; 
        } else {
            low = mid + 1; 
        }
    }

    return ans;
    }
};

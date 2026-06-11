class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int>s;
        vector<int> ans = prices;
        int i=0;
        while(i<n){
            while(!s.empty() && prices[s.top()]>=prices[i]){
                ans[s.top()] -= prices[i];
                s.pop();
            }
            s.push(i);
            i++;
        }
        return ans;
    }
};

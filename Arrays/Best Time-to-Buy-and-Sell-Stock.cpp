// LeetCode 2 - Best Time to Buy and Sell Stock
// Topic: Array + Dynamic Programming
// Difficulty: Easy
// Time Complexity: O(n)


int maxProfit(vector<int>& prices) {
    int mini = prices[0];
    int maxProfit = 0;

    for (int price : prices) {
        mini = min(mini, price);
        maxProfit = max(maxProfit, price - mini);
    }

    return maxProfit;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        vector<int> profits(prices.size(), 0);
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            min_price = min(min_price, prices[i]);
            profits[i] = max(profits[i - 1], prices[i] - min_price);
        }
        int ans = 0;
        int max_price = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--) {
            max_price = max(max_price, prices[i]);
            int t = max_price - prices[i];
            if (i >= 1) t += profits[i - 1];
            ans = max(ans, t);
        }
        return ans;
    }
};
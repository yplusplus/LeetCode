class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int tmp = 0 - prices[0];
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            tmp = max(tmp, ans - prices[i]);
            ans = max(ans, tmp + prices[i]);
        }
        return ans;
    }
};
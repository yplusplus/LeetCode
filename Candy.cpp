class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        vector<int> candys(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candys[i] = max(candys[i], candys[i - 1] + 1);
            }
        }
        int ans = 0;
        for (int i = ratings.size() - 1; i >= 0; i--) {
            if (i + 1 < ratings.size() && ratings[i] > ratings[i + 1]) {
                candys[i] = max(candys[i], candys[i + 1] + 1);
            }
            ans += candys[i];
        }
        return ans;
    }
};
class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& A) {
            int ans = 0;
            int n = A.size();
            vector<unordered_map<long long, int> > dp(n);
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    long long d = (long long)A[i] - A[j];
                    auto it = dp[j].find(d);
                    long long v = 1;
                    if (it != dp[j].end()) {
                        v += it->second;
                        ans += it->second;
                    }
                    dp[i][d] += v;
                }
            }
            return ans;
        }
};

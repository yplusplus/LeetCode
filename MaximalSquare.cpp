class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int n = matrix.size();
            if (n == 0) return 0;
            int m = matrix[0].size();
            if (m == 0) return 0;
            vector<vector<int> > dp(n, vector<int>(m));
            int ans = 0;
            for (int i = 0; i < n; i++) {
                int c = 0;
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == '0') {
                        dp[i][j] = 0;
                    } else {
                        if (i == 0 || j == 0) dp[i][j] = 1;
                        else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                        ans = max(ans, dp[i][j]);
                    }

                }
            }
            return ans * ans;
        }
};

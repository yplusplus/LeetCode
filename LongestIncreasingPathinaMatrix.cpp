class Solution {
public:
    static vector<pair<int, int>> dir;
    int dfs(int x, int y, vector<vector<int>> &dp, const vector<vector<int>> &matrix) {
        if (dp[x][y] != -1) return dp[x][y];
        int res = 0;
        for (const auto &d: dir) {
            int nx = x + d.first;
            int ny = y + d.second;
            if (nx < 0 || nx >= dp.size() || ny < 0 || ny >= dp[0].size()) continue;
            if (matrix[nx][ny] < matrix[x][y]) {
                res = max(res, dfs(nx, ny, dp, matrix));
            }
        }
        dp[x][y] = res + 1;
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, dp, matrix));
            }
        }
        return ans;
    }
};

vector<pair<int, int>> Solution::dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
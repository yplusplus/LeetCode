class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<int> pre(m, 0);
        vector<int> cur(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) cur[0] = 1;
                else if (obstacleGrid[i][j] != 1) {
                    cur[j] = 0;
                    if (i > 0) cur[j] += pre[j];
                    if (j > 0) cur[j] += cur[j - 1];
                } else {
                    cur[j] = 0;
                }
            }
            swap(pre, cur);
        }
        return pre.back();
    }
};
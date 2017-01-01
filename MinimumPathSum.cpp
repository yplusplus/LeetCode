class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<vector<int>> min_value(grid.size());
        for (int i = 0; i < grid.size(); i++) {
            min_value[i] = grid[i];
            for (int j = 0; j < grid[0].size(); j++) {
                int v = -1;
                if (i > 0) {
                    if (v == -1 || v > min_value[i - 1][j]) v = min_value[i - 1][j];
                }
                if (j > 0) {
                    if (v == -1 || v > min_value[i][j - 1]) v = min_value[i][j - 1];
                }
                if (v != -1)
                    min_value[i][j] += v;
            }
        }
        return min_value[grid.size() - 1][grid[0].size() - 1];
    }
};
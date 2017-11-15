class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0') return;
        grid[x][y] = '0';
        dfs(x - 1, y, grid);
        dfs(x + 1, y, grid);
        dfs(x, y - 1, grid);
        dfs(x, y + 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        int islands_num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    islands_num++;
                    dfs(i, j, grid);
                }
            }
        }
        return islands_num;
    }
};
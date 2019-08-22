class Solution {
public:
    int encode(const pair<int, int> &p) {
        return m * p.first + p.second;
    }
    pair<int, int> decode(int x) {
        return pair<int, int>{x / m, x % m};
    }
    int dfs(const vector<vector<int>>& grid, vector<vector<int> > &ways, int t, int mask) {
        if (ways[t][mask] != -1) return ways[t][mask];
        pair<int, int> p = decode(t);
        ways[t][mask] = 0;
        for (int i = 0; i < 4; i++) {
            pair<int, int> np = {p.first + dx[i], p.second + dy[i]};
            if (np.first < 0 || np.first >= n || np.second < 0 || np.second >= m) continue;
            if (grid[np.first][np.second] == -1) continue;
            int nt = encode(np);
            if (~mask >> nt & 1) continue;
            ways[t][mask] += dfs(grid, ways, nt, mask ^ (1 << t));
        }
        return ways[t][mask];
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        vector<vector<int> > ways(n * m, vector<int>(1 << (n * m), -1));
        int s = 0, t = 0;
        int mask = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    s = encode(pair<int, int>{i, j});
                }
                if (grid[i][j] == 2) {
                    t = encode(pair<int, int>{i, j});
                }
                if (grid[i][j] != -1) {
                    mask |= 1 << encode(pair<int, int>{i, j});
                }
            }
        }
        ways[s][1 << s] = 1;
        return dfs(grid, ways, t, mask);
    }
    
    int n, m;
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {-1, 1, 0, 0};
};
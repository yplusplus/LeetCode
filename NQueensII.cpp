class Solution {
public:
    int dfs(int now, int n, vector<bool> &col, vector<bool> &diag, vector<bool> &anti) {
        if (now == n) return 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (col[i] && diag[now - i + n] && anti[i + now]) {
                col[i] = diag[now - i + n] = anti[i + now] = false;
                cnt += dfs(now + 1, n, col, diag, anti);
                col[i] = diag[now - i + n] = anti[i + now] = true;
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        if (n == 0) return 0;
        vector<bool> col(n, true);
        vector<bool> diag(2 * n, true);
        vector<bool> anti(2 * n, true);
        return dfs(0, n, col, diag, anti);
    }
};
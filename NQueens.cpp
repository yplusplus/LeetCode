class Solution {
public:
    bool get_bit(int &mask, int bit) {
        return (mask >> bit & 1) == 1;
    }
    void set_bit(int &mask, int bit) {
        mask |= (1 << bit);
    }
    void reset_bit(int &mask, int bit) {
        mask &= ~(1 << bit);
    }
    void dfs(int now, int n, vector<int> &row, int col, int diag, int anti_diag, vector<vector<string>> &result) {
        if (now == n) {
            string row_str(n, '.');
            vector<string> solution(n);
            for (int i = 0; i < n; i++) {
                row_str[row[i]] = 'Q';
                solution[i] = row_str;
                row_str[row[i]] = '.';
            }
            result.push_back(solution);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!get_bit(col, i) && !get_bit(diag, now - i + n) && !get_bit(anti_diag, i + now)) {
                row[now] = i;
                set_bit(col, i);
                set_bit(diag, now - i + n);
                set_bit(anti_diag, i + now);
                dfs(now + 1, n, row, col, diag, anti_diag, result);
                reset_bit(anti_diag, i + now);
                reset_bit(diag, now - i + n);
                reset_bit(col, i);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if (n == 0) return result;
        vector<int> row(n);
        dfs(0, n, row, 0, 0, 0, result);
        return result;
    }
};
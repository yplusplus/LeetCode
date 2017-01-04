class Solution {
public:
    int indexOfGrid(int i, int j) {
        i /= 3;
        j /= 3;
        return i * 3 + j;
    }
    bool solve(vector<vector<char>> &board, int r, int c, vector<int> &row_masks, vector<int> &col_masks, vector<int> &grid_masks) {
        if (r >= board.size()) {
            return true;
        }
        int nr = r, nc = c + 1;
        if (nc >= board[0].size()) nr++, nc = 0;
        if (board[r][c] != '.') return solve(board, nr, nc, row_masks, col_masks, grid_masks);
        for (int i = 1; i <= 9; i++) {
            int mask = 1 << i;
            if ((row_masks[r] & mask) == 0
                && (col_masks[c] & mask) == 0
                && (grid_masks[indexOfGrid(r, c)] & mask) == 0) {
                row_masks[r] |= mask;
                col_masks[c] |= mask;
                grid_masks[indexOfGrid(r, c)] |= mask;
                board[r][c] = '0' + i;
                if (solve(board, nr, nc, row_masks, col_masks, grid_masks)) return true;
                board[r][c] = '.';
                row_masks[r] ^= mask;
                col_masks[c] ^= mask;
                grid_masks[indexOfGrid(r, c)] ^= mask;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row_masks(9, 0);
        vector<int> col_masks(9, 0);
        vector<int> grid_masks(9, 0);
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    int mask = 1 << (board[i][j] - '0');
                    row_masks[i] |= mask;
                    col_masks[j] |= mask;
                    grid_masks[indexOfGrid(i, j)] |=  mask;
                }
            }
        }
        solve(board, 0, 0, row_masks, col_masks, grid_masks);
    }
};
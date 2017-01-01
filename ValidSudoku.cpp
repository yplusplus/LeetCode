class Solution {
public:
    bool check(vector<vector<char>> &board, int r, int c) {
        int mask = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[r + i][c + j] != '.') {
                    int idx = board[r + i][c + j] - '0';
                    if (mask & (1 << idx)) return false;
                    mask |= (1 << idx);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        // row
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '0';
                    if (mask & (1 << idx)) return false;
                    mask |= (1 << idx);
                }
            }
        }
        // column
        for (int j = 0; j < n; j++) {
            int mask = 0;
            for (int i = 0; i < n; i++) {
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '0';
                    if (mask & (1 << idx)) return false;
                    mask |= (1 << idx);
                }
            }
        }
        // grid
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                if (!check(board, i, j)) return false;
            }
        }
        return true;
    }
};
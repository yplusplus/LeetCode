class Solution {
public:
    bool inBoard(const vector<vector<char>> &board, int x, int y) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }
    bool search(const vector<vector<char>> &board, int x, int y, int now, const string &word, vector<vector<bool>> &used) {
        if (now == word.length()) return true;
        for (int i = 0; i < dirs.size(); i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (!inBoard(board, nx, ny)) continue;
            if (used[nx][ny] || word[now] != board[nx][ny]) continue;
            used[nx][ny] = true;
            if (search(board, nx, ny, now + 1, word, used)) return true;
            used[nx][ny] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0) return true;
        int n = board.size();
        if (n == 0) return false;
        int m = board[0].size();
        vector<vector<bool>> used(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != word[0]) continue;
                used[i][j] = true;
                if (search(board, i, j, 1, word, used)) return true;
                used[i][j] = false;
            }
        }
        return false;
    }
    private:
        static vector<vector<int>> dirs;
};

vector<vector<int>> Solution::dirs{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
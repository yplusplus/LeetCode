class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ships = 0;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    if ((i == 0 || board[i - 1][j] == '.')
                        && (j == 0 || board[i][j - 1] == '.'))
                        ships++;
                }
            }
        }
        return ships;
    }
};
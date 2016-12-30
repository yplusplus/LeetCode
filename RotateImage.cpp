class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int x = i, y = j;
                for (int k = 0; k < 3; k++) {
                    int nx = y, ny = n - 1 - x;
                    x = nx, y = ny;
                    swap(matrix[i][j], matrix[x][y]);
                }
            }
        }
    }
};
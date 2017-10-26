class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        if (m == 0) return;
        bool col0 = false;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) col0 = true;
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (col0)
                matrix[i][0] = 0;
        }
    }
};
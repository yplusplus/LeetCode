class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        if (m == 0) return;
        bool first_col_zero = false;
        bool first_row_zero = false;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) first_col_zero = true;
        }
        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == 0) first_row_zero = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; j++) matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < n; i++) matrix[i][j] = 0;
            }
        }
        if (first_col_zero) {
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
        }
        if (first_row_zero) {
            for (int j = 0; j < m; j++) matrix[0][j] = 0;
        }
    }
};
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int seq = 0;
        int row_begin = 0, row_end = n - 1;
        int col_begin = 0, col_end = n - 1;
        while (row_begin <= row_end && col_begin <= col_end) {
            // right
            for (int i = col_begin; i <= col_end; i++) matrix[row_begin][i] = ++seq;
            if (++row_begin > row_end) break;
            // down
            for (int i = row_begin; i <= row_end; i++) matrix[i][col_end] = ++seq;
            if (col_begin > --col_end) break;
            // left
            for (int i = col_end; i >= col_begin; i--) matrix[row_end][i] = ++seq;
            if (row_begin > --row_end) break;
            // up
            for (int i = row_end; i >= row_begin; i--) matrix[i][col_begin] = ++seq;
            if (++col_begin > col_end) break;
        }
        return matrix;
    }
};
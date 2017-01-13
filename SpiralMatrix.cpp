class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row_begin = 0, row_end = matrix.size() - 1;
        if (row_begin > row_end) return result;
        int col_begin = 0, col_end = matrix[0].size() - 1;
        while (row_begin <= row_end && col_begin <= col_end) {
            // right
            for (int i = col_begin; i <= col_end; i++) result.push_back(matrix[row_begin][i]);
            if (++row_begin > row_end) break;
            // down
            for (int i = row_begin; i <= row_end; i++) result.push_back(matrix[i][col_end]);
            if (--col_end < col_begin) break;
            // left
            for (int i = col_end; i >= col_begin; i--) result.push_back(matrix[row_end][i]);
            if (row_begin > --row_end) break;
            // up
            for (int i = row_end; i >= row_begin; i--) result.push_back(matrix[i][col_begin]);
            ++col_begin;
        }
        return result;
    }
};
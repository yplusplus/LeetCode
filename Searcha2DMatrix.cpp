class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        if (r == 0) return false;
        int c = matrix[0].size();
        if (c == 0) return false;
        int L = 0, R = r *c - 1;
        while (L <= R) {
            int mid = (L + R) / 2;
            int t = matrix[mid / c][mid % c];
            if (t == target) return true;
            else if (t < target) {
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        return false;
    }
};
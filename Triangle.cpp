class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        int n = triangle.size();
        vector<int> cur(triangle.back()), prev(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            swap(cur, prev);
            for (int j = 0; j <= i; j++) {
                cur[j] = min(prev[j], prev[j + 1]) + triangle[i][j];
            }
        }
        return cur[0];
    }
};
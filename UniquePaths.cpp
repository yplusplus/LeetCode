class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre, cur;
        for (int i = 0; i <= (m + n - 2); i++) {
            cur.resize(i + 1);
            cur[0] = cur[i] = 1;
            for (int j = 1; j < i; j++) {
                cur[j] = pre[j] + pre[j - 1];
            }
            swap(pre, cur);
        }
        return pre[min(n, m) - 1];
    }
};
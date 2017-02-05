class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur{1}, pre;
        for (int i = 1; i <= rowIndex; i++) {
            swap(pre, cur);
            cur.resize(i + 1);
            cur[0] = cur[i] = 1;
            for (int j = 1; j < i; j++) {
                cur[j] = pre[j - 1] + pre[j];
            }
        }
        return cur;
    }
};
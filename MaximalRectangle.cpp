class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n <= 0) return 0;
        int m = matrix[0].size();
        vector<int> height(m + 1, 0);
        height[m] = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') height[j] = 0;
                else height[j]++;
            }
            stack<pair<int, int>> st;
            st.push(make_pair(-1, -1));
            for (int j = 0; j <= m; j++) {
                while (st.size() > 1 && st.top().second >= height[j]) {
                    int h = st.top().second;
                    st.pop();
                    ans = max(ans, (j - st.top().first - 1) * h);
                }
                st.push(make_pair(j, height[j]));
            }
        }
        return ans;
    }
};
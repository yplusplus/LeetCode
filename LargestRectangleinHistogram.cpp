class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        st.push(make_pair(-1, -1));
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (st.top().second >= heights[i]) {
                int h = st.top().second;
                st.pop();
                ans = max(ans, (i - st.top().first - 1) * h);
            }
            st.push(make_pair(i, heights[i]));
        }
        while (st.size() > 1) {
            int h = st.top().second;
            st.pop();
            ans = max(ans, ((int)heights.size() - 1 - st.top().first) * h);
        }
        return ans;
    }
};
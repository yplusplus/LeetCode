class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int offset = -1;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    offset = i;
                } else {
                    st.pop();
                }
                int j = st.empty() ? offset : st.top();
                ans = max(ans, i - j);
            }
        }
        return ans;
    }
};
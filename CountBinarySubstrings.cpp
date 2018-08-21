class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int pre = 0;
        int cur = 0;
        for (int i = 0; i < s.length(); i++) {
            cur++;
            if (i + 1 >= s.length() || s[i + 1] != s[i]) {
                ans += min(pre, cur);
                pre = cur;
                cur = 0;
            }
        }
        return ans;
    }
};
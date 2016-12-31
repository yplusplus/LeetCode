class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int L = -1, R = -1;
        int ans = 0;
        while (R + 1 < s.length()) {
            R++;
            while (L < last[s[R]]) {
                L++;
                last[s[L]] = -1;
            }
            last[s[R]] = R;
            ans = max(ans, R - L);
        }
        return ans;
    }
};
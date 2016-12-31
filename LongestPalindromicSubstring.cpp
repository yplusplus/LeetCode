class Solution {
public:
    pair<int, int> calcPalindrome(const string &s, int L, int R) {
        if (R >= s.length() || s[L] != s[R]) return make_pair(0, -1);
        while (L - 1 >= 0 && R + 1 < s.length() && s[L - 1] == s[R + 1]) {
            L--;
            R++;
        }
        return make_pair(R - L + 1, L);
    }
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0) return "";
        if (len == 1) return s;
        pair<int, int> ans;
        for (int i = 0; i < len; i++) {
            ans = max(ans, calcPalindrome(s, i, i));
            ans = max(ans, calcPalindrome(s, i, i + 1));
        }
        return s.substr(ans.second, ans.first);
    }
};
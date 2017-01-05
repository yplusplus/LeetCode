class Solution {
public:
    bool check(char a, char b) {
        if (a == '1') return true;
        if (a == '2' && b <= '6') return true;
        return false;
    }
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            if (i >= 2 && check(s[i - 2], s[i - 1]))
                dp[i] += dp[i - 2];
        }
        return dp.back();
    }
};
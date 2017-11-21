class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int n = s1.length();
        vector<vector<vector<int> > > dp(n + 1, vector<vector<int>>(n, vector<int>(n, -1)));
        return isScramble(s1, s2, n, 0, 0, dp);
    }
    bool isScramble(string s1, string s2, int len, int start1, int start2, vector<vector<vector<int> > > &dp) {
        if (dp[len][start1][start2] != -1)
            return dp[len][start1][start2] == 1 ? true : false;
        
        dp[len][start1][start2] = 1;
        
        bool equal = true;
        for (int i = 0; i < len; i++) {
            if (s1[start1 + i] != s2[start2 + i]) {
                equal = false;
                break;
            }
        }
        if (equal) return true;
        
        if (!isAnagram(s1, s2, len, start1, start2)) {
            dp[len][start1][start2] = 0;
            return false;
        }
        
        for (int i = 1; i < len; i++) {
            if (isScramble(s1, s2, i, start1, start2, dp) && isScramble(s1, s2, len - i, start1 + i, start2 + i, dp))
                return true;
            if (isScramble(s1, s2, i, start1, start2 + len - i, dp) && isScramble(s1, s2, len - i, start1 + i, start2, dp))
                return true;
        }
        
        dp[len][start1][start2] = 0;
        return false;
    }
    bool isAnagram(string s1, string s2, int len, int start1, int start2) {
        vector<int> count(26);
        for (int i = 0; i < len; i++) {
            count[s1[start1 + i] - 'a']++;
            count[s2[start2 + i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
};
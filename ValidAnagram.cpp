class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int cnt[256] = {0};
        for (char ch : s) cnt[ch]++;
        for (char ch : t) {
            if (--cnt[ch] < 0) return false;
        }
        return true;
    }
};
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(256);
        for (char ch : magazine)
            cnt[ch]++;
        for (char ch : ransomNote) {
            if (cnt[ch] > 0)
                cnt[ch]--;
            else
                return false;
        }
        return true;
    }
};
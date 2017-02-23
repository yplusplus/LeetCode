class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> canBreak(s.length() + 1, false);
        canBreak[0] = true;
        for (int i = 0; i < s.length(); i++) {
            if (!canBreak[i]) continue;
            for (int j = 1; i + j <= s.length(); j++) {
                if (wordSet.count(s.substr(i, j)))
                    canBreak[i + j] = true;
            }
        }
        return canBreak.back();
    }
};
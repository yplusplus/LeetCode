class Solution {
public:
    void dfs(int now, const string &s, string restore, int count, vector<string> &result) {
        if (count == 4) {
            if (now == s.length()) result.push_back(restore);
            return;
        }
        for (int i = 0; i < 3 && now + i < s.length(); i++) {
            const string sub = s.substr(now, i + 1);
            int tmp = stoi(sub);
            if (tmp >= 0 && tmp <= 255 && to_string(tmp) == sub) {
                string tmp = restore;
                if (count > 0) tmp += ".";
                tmp += sub;
                dfs(now + i + 1, s, tmp, count + 1, result);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.length() >= 4 && s.length() <= 12)
            dfs(0, s, "", 0, result);
        return result;
    }
};
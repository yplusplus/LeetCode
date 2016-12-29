class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int max_len = 0;
        while (true) {
            bool found = false;
            for (int i = 0; i < strs.size(); i++) {
                if (max_len >= strs[i].length() || strs[i][max_len] != strs[0][max_len]) {
                    found = true;
                    break;
                }
            }
            if (found) break;
            max_len++;
        }
        return strs[0].substr(0, max_len);
    }
};
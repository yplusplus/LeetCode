class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> strs(numRows);
        int dir = 1;
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            strs[index] += s[i];
            if (index + dir < 0 || index + dir >= numRows) {
                dir = -dir;
            }
            index += dir;
        }
        string ans;
        for (int i = 0; i < numRows; i++) {
            ans += strs[i];
        }
        return ans;
    }
};
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (auto ch : s) {
            int n = ch - 'A' + 1;
            res = res * 26 + n;
        }
        return res;
    }
};
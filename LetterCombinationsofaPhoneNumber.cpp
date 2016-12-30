class Solution {
public:
    void dfs(vector<string> &result, int now, const string &digits, string &str) {
        if (now == digits.length()) {
            result.push_back(str);
            return;
        }
        for (auto ch : digital_table[digits[now] - '0']) {
            str[now] = ch;
            dfs(result, now + 1, digits, str);
        }
    }
    vector<string> letterCombinations(string digits) {
        digital_table.resize(10);
        digital_table[2] = "abc";
        digital_table[3] = "def";
        digital_table[4] = "ghi";
        digital_table[5] = "jkl";
        digital_table[6] = "mno";
        digital_table[7] = "pqrs";
        digital_table[8] = "tuv";
        digital_table[9] = "wxyz";
        vector<string> result;
        if (digits.length() > 0) {
            string str(digits.length(), 'x');
            dfs(result, 0, digits, str);
        }
        return result;
    }
private:
    vector<string> digital_table;
};
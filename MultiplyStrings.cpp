class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> ans(num1.length() + num2.length(), 0);
        for (int i = 0; i < num1.length(); i++) {
            for (int j = 0; j < num2.length(); j++) {
                ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0; i < ans.size() - 1; i++) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
        while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
        string ans_str(ans.size(), '0');
        for (int i = 0; i < ans.size(); i++) {
            ans_str[i] += ans[ans.size() - i - 1];
        }
        return ans_str;
    }
};
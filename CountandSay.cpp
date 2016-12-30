class Solution {
public:
    string countAndSay(int n) {
        string str("1"), nstr;
        for (int i = 2; i <= n; i++) {
            nstr.clear();
            for (int j = 0; j < str.length(); j++) {
                int k = j;
                while (k + 1 < str.length() && str[k + 1] == str[j]) k++;
                nstr += (char)(k - j + 1 + '0');
                nstr += str[j];
                j = k;
            }
            swap(str, nstr);
        }
        return str;
    }
};
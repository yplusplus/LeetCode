class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() == 0) return;
        reverse(s.begin(), s.end());
        int pos = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isspace(s[i])) continue;
            int j = i;
            while (j + 1 < s.length() && !isspace(s[j + 1])) j++;
            reverse(s.begin() + i, s.begin() + j + 1);
            if (pos > 0) s[pos++] = ' ';
            for (int k = i; k <= j; k++) s[pos++] = s[k];
            i = j;
        }
        s.resize(pos);
    }
};
class Solution {
public:
    void getNext(string str, vector<int> &next) {
        int n = str.length();
        next.resize(n + 1);
        int i = 0, j = -1;
        next[i] = j;
        while (i < n) {
            if (j == -1 || str[i] == str[j]) {
                i++, j++;
                next[i] = j;
            } else j = next[j];
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        vector<int> next;
        getNext(needle, next);
        int i = 0, j = 0;
        while (i < (int)haystack.length() && j < (int)needle.length()) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++, j++;
            } else {
                j = next[j];
            }
        }
        if (j == needle.length()) return i - j;
        return -1;
    }
};
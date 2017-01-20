class Solution {
public:
    bool isPalindrome(string s) {
        for (int L = 0, R = s.length() - 1; L < R; L++, R--) {
            while (L < R && !isalnum(s[L])) L++;
            while (L < R && !isalnum(s[R])) R--;
            if (tolower(s[L]) != tolower(s[R])) return false;
        }
        return true;
    }
};
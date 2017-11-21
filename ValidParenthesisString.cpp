class Solution {
public:
    bool checkValidString(string s) {
        int left = 0;
        int couple = 0;
        for (char ch : s) {
            if (ch == '(') {
                left++;
                couple++;
            } else if (ch == '*') {
                if (left > 0) left--;
                couple++;
            } else {
                if (left > 0) left--;
                couple--;
                if (couple < 0) return false;
            }
        }
        return left == 0;
    }
};
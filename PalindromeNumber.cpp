class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int base = 1;
        int y = x;
        while (x >= 10) {
            x /= 10;
            base *= 10;
        }
        while (y) {
            if (y / base != y % 10) return false;
            y %= base;
            y /= 10;
            base /= 100;
        }
        return true;
    }
};
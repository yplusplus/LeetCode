class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        for (int i = 16; i >= 0; i--) {
            ans |= (1 << i);
            if (ans > x / ans) ans ^= (1 << i);
        }
        return ans;
    }
};
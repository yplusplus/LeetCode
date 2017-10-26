// m : x x x x 1 m3 m2 m1
// n : x x x x 0 n3 n2 n1
// must exist z(x x x x 1 0 0 0 0) between n and m

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if ((n >> i) == (m >> i)) {
                ans = n >> i << i;
            } else {
                break;
            }
        }
        return ans;
    }
};
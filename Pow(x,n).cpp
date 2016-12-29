class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        bool neg = false;
        long long m = n;
        if (m < 0) {
            neg = true;
            m = -m;
        }
        double ans = 1.0;
        while (m) {
            if (m & 1) ans = ans * x;
            x *= x;
            m >>= 1;
        }
        if (neg) ans = 1 / ans;
        return ans;
    }
};
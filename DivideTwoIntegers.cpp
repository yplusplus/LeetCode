class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        int sign = 1;
        long long a = dividend;
        long long b = divisor;
        if (a < 0) {
            a = -a;
            sign *= -1;
        }
        if (b < 0) {
            b = -b;
            sign *= -1;
        }
        long long c = 0;
        long long fac = 1;
        while (a >= b) {
            fac <<= 1;
            b <<= 1;
        }
        while (b) {
            if (a >= b) {
                a -= b;
                c += fac;
            }
            b >>= 1;
            fac >>= 1;
        }
        c *= sign;
        if (c > INT_MAX) c = INT_MAX;
        return (int)c;
    }
};
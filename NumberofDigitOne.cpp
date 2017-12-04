class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        vector<int> digits;
        int x = n;
        while (x) {
            digits.push_back(x % 10);
            x /= 10;
        }
        vector<int> f(10), g(10);
        g[0] = 1;
        for (int i = 1; i < f.size(); i++) {
            g[i] = g[i - 1] * 10;
            f[i] = f[i - 1] * 10 + g[i - 1];
        }
        int ones = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int d = digits[i];
            ans += d * f[i];
            ans += ones * d * g[i];
            if (d == 1) ones++;
            else if (d > 1) ans += g[i];
        }
        ans += ones;
        return ans;
    }
};
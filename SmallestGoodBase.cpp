// log * log * log
class Solution {
public:
    unsigned long long calc(int d, int k) {;
        unsigned long long x = 1;
        unsigned long long sum = 0;
        for (int i = 0; i < d; i++) {
            sum += x;
            x *= k;
        }
        return sum;
    }
    string smallestGoodBase(string n) {
        unsigned long long m = stoull(n);
        for (int d = 62; d >= 2; d--) {
            if ((1 << d) - 1 <= m) {
                int L = 2, R = pow(m, 1.0 / (d - 1)) + 1.0;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    long long x = calc(d, mid);
                    if (x == m) {
                        return to_string(mid);
                    } else if (x > m) {
                        R = mid - 1;
                    } else {
                        L = mid + 1;
                    }
                }
            }
        }
        return to_string(m - 1);
    }
};
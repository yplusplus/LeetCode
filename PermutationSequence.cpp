class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n);
        fac[0] = 1;
        for (int i = 1; i < n; i++) {
            fac[i] = fac[i - 1] * i;
        }
        vector<bool> used(n + 1, false);
        string ans;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (used[j]) continue;
                if (fac[n - i] >= k) {
                    ans += ('0' + j);
                    used[j] = true;
                    break;
                } else {
                    k -= fac[n - i];
                }
            }
        }
        return ans;
    }
};
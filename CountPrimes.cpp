class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        int primes = 0;
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) {
                primes++;
                for (long long j = (long long)i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return primes;
    }
};
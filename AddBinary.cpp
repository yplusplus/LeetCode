class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        string res(max(n, m) + 1, '0');
        n--, m--;
        int p = res.length() - 1;
        int z = 0;
        while (n >= 0 || m >= 0 || z) {
            z += n >= 0 ? a[n--] - '0' : 0;
            z += m >= 0 ? b[m--] - '0' : 0;
            res[p--] = (z & 1) + '0';
            z >>= 1;
        }
        if (p >= 0) res = res.substr(1);
        return res;
    }
};
class Solution {
    public:
        int pow(int x, int y) {
            int res = 1;
            for (int i = 0; i < y; i++) res *= x;
            return res;
        }
        int calc(vector<int> &digits, int index, bool flag_2569, bool end) {
            if (index == -1) return flag_2569 ? 1 : 0;
            if (!end) {
                int res = pow(7, index + 1);
                if (!flag_2569) {
                    res -= pow(3, index + 1);
                }
                return res;
            }
            int res = 0;
            for (int i = 0; i < 10 && i <= digits[index]; i++) {
                if (i == 3 || i == 4 || i == 7) continue;
                bool nflag_2569 = flag_2569 || i == 2 || i == 5 || i == 6 || i == 9;
                bool nend = end && (i == digits[index]);
                res += calc(digits, index - 1, nflag_2569, nend);
            }
            return res;
        }
        int rotatedDigits(int N) {
            if (N <= 0) return 0;
            vector<int> digits;
            while (N) {
                digits.push_back(N % 10);
                N /= 10;
            }
            return calc(digits, (int)digits.size() - 1, false, true);
        }
};

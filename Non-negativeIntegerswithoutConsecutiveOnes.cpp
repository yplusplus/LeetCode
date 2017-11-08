class Solution {
public:
    int findIntegers(int num) {
        const int BITS_OF_INT = 32;
        vector<int> f(BITS_OF_INT);
        f[0] = 1; f[1] = 2;
        for (int i = 2; i < BITS_OF_INT; i++) 
            f[i] = f[i - 1] + f[i - 2];
		
        int ans = 0;
        for (int i = BITS_OF_INT - 1; i >= 0; i--) {
            int cur_bit = num >> i & 1;
            if (cur_bit == 1) {
                ans += f[i];
                if ((num >> (i + 1) & 1) == 1) {
                    // n is invalid
                    ans--;
                    break;
                }
            }
        }
        return ans + 1;
    }
};
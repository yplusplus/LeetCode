class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& A) {
            if (A.size() <= 2) return 0;
            int ans = 0;
            int j = 0;
            int n = A.size();
            for (int i = 0; i < n - 1; i++) {
                j = max(j, i + 1);
                while (j + 1 < n && A[j - 1] + A[j + 1] == 2 * A[j]) j++;
                ans += j - i - 1;
            }
            return ans;
        }
};

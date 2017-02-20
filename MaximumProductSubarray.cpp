class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ma = nums[0], mi = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int nma = nums[i], nmi = nums[i];
            if (nums[i] >= 0) {
                nma = max(nma, ma * nums[i]);
                nmi = min(nmi, mi * nums[i]);
            } else {
                nma = max(nma, mi * nums[i]);
                nmi = min(nmi, ma * nums[i]);
            }
            ma = nma;
            mi = nmi;
            ans = max(ans, ma);
        }
        return ans;
    }
};
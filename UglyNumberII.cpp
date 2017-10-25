class Solution {
    public:
        int nthUglyNumber(int n) {
            vector<int> nums(n);
            int c2 = 0, c3 = 0, c5 = 0;
            nums[0] = 1;
            for (int i = 1; i < n; i++) {
                nums[i] = min(nums[c2] * 2, min(nums[c3] * 3, nums[c5] * 5));
                if (nums[i] == nums[c2] * 2) c2++;
                if (nums[i] == nums[c3] * 3) c3++;
                if (nums[i] == nums[c5] * 5) c5++;
            }
            return nums[n - 1];
        }
};

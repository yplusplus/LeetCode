class NumArray {
    public:
        NumArray(vector<int> nums) {
            sums.resize(nums.size());
            for (int i = 0; i < nums.size(); i++) {
                sums[i] = nums[i];
                if (i > 0) sums[i] += sums[i - 1];
            }
        }

        int sumRange(int i, int j) {
            int ans = sums[j];
            if (i > 0) ans -= sums[i - 1];
            return ans;
        }
    private:
        vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

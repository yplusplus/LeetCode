class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int i = nums.size() - 2;
        for (; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                break;
        }
        reverse(nums.begin() + i + 1, nums.end());
        if (i == -1) return;
        auto it = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
        swap(*it, nums[i]);
    }
    
};
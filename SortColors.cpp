class Solution {
public:
    void sortColors(vector<int>& nums) {
        int L = -1, R = nums.size();
        for (int i = 0; i < R; i++) {
            if (nums[i] == 1) continue;
            if (nums[i] == 0) {
                swap(nums[i], nums[++L]);
                if (L < i) i--;
            } else {
                swap(nums[i], nums[--R]);
                i--;
            }
        }
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        for (int i = 0; i <= cover && i < nums.size(); i++) {
            cover = max(cover, nums[i] + i);
        }
        return cover >= nums.size() - 1;
    }
};
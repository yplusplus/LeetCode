class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (len > 0 && nums[i] == nums[len - 1])
                continue;
            nums[len] = nums[i];
            len++;
        }
        return len;
    }
};
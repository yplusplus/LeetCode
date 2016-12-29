class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) continue;
            nums[len] = nums[i];
            len++;
        }
        return len;
    }
};
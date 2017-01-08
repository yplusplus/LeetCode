class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || nums[i] > nums.size()) continue;
            if (nums[nums[i] - 1] == nums[i]) continue;
            swap(nums[nums[i] - 1], nums[i]);
            i--;
        }
        int ans = nums.size() + 1;
        for (int i = 1; i <= nums.size(); i++) {
            if (nums[i - 1] != i) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
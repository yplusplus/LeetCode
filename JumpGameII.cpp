class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> min_steps(nums.size());
        min_steps[0] = 0;
        int max_cover = 0;
        for (int i = 0; i <= max_cover && max_cover < nums.size() - 1; i++) {
            for (int j = max_cover + 1; j <= i + nums[i] && j < nums.size(); j++) {
                min_steps[j] = min_steps[i] + 1;
            }
            max_cover = max(max_cover, i + nums[i]);
        }
        return min_steps.back();
    }
};
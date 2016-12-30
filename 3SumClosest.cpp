class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2] - target;
        for (int i = 0; i < nums.size(); i++) {
            int L = i + 1, R = nums.size() - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R] - target;
                if (abs(sum) < abs(ans))
                    ans = sum;
                if (sum > 0) {
                    R--;
                } else if (sum < 0) {
                    L++;
                } else {
                    break;
                }
            }
        }
        return ans + target;
    }
};
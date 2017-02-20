class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size() - 2] < nums.back()) return nums.size() - 1;
        int L = 1, R = nums.size() - 2;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (nums[mid] >= nums[mid - 1] && nums[mid] >= nums[mid + 1])
                return mid;
            else if (nums[mid] < nums[mid - 1]) R = mid - 1;
            else L = mid + 1;
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int>{-1, -1};
        }
        int left, right, mid;
        int first = -1;
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
                if (nums[mid] == target) first = mid;
            } else {
                left = mid + 1;
            }
        }
        if (first == -1) {
            return vector<int>{-1, -1};
        }
        left = 0, right = nums.size() - 1;
        int last = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
                if (nums[mid] == target) last = mid;
            } else {
                right = mid - 1;
            }
        }
        return vector<int>{first, last};
    }
};
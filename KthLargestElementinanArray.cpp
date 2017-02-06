class Solution {
public:
    int findKthLargest(vector<int> &nums, int L, int R, int k) {
        int i = L, j = R;
        while (i < j) {
            while (i < j && nums[i] <= nums[j]) j--;
            if (i < j) swap(nums[i++], nums[j]);
            while (i < j && nums[i] <= nums[j]) i++;
            if (i < j) swap(nums[i], nums[j--]);
        }
        if (i - L + 1 == k) return nums[i];
        else if (i - L >= k) return findKthLargest(nums, L, i - 1, k);
        else return findKthLargest(nums, i + 1, R, k - (i - L + 1));
    }
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, nums.size() + 1 - k);
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k %= nums.size();
        if (k) {
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + k);
            reverse(nums.begin() + k, nums.end());
        }
    }
};
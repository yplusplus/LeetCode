class Solution {
public:
    Solution(vector<int> nums) {
        nums_.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            nums_[i] = make_pair(nums[i], i);
        }
        sort(nums_.begin(), nums_.end());
    }
    
    int pick(int target) {
        int cnt = 0;
        int res = -1;
        auto it = lower_bound(nums_.begin(), nums_.end(), make_pair(target, 0));
        for (; it != nums_.end(); it++) {
            if (it->first > target) break;
            if (++cnt == 1 || rand() % cnt == 0) res = it->second;
        }
        return res;
    }
private:
    std::vector<pair<int, int> > nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
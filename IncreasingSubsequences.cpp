class Solution {
    public:
        void findSubsequences(const vector<int> &nums, int now, vector<int> &seq) {
            if (seq.size() >= 2) result.push_back(seq);
            unordered_set<int> hash;
            for (int i = now; i < nums.size(); i++) {
                if ((seq.empty() || seq.back() <= nums[i]) && hash.count(nums[i]) == 0) {
                    hash.insert(nums[i]);
                    seq.push_back(nums[i]);
                    findSubsequences(nums, i + 1, seq);
                    seq.pop_back();
                }
            }
        }
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            if (!nums.empty()) {
                vector<int> seq;
                findSubsequences(nums, 0, seq);
            }
            return result;
        }
    private:
        vector<vector<int>> result;
};

//class Solution {
//    public:
//        void dfs(vector<int> &nums, int now) {
//            if (now >= nums.size()) {
//                result.push_back(nums);
//                return;
//            }
//            for (int i = now; i < nums.size(); i++) {
//                bool found = false;
//                for (int j = now; j < i; j++) {
//                    if (nums[i] == nums[j])
//                        found = true;
//                }
//                if (found) continue;
//                swap(nums[i], nums[now]);
//                dfs(nums, now + 1);
//                swap(nums[i], nums[now]);
//            }
//        }
//        vector<vector<int>> permuteUnique(vector<int>& nums) {
//            if (nums.empty()) return result;
//            sort(nums.begin(), nums.end());
//            dfs(nums, 0);
//            return result;
//        }
//    private:
//        vector<vector<int>> result;
//};

class Solution {
    public:
        void dfs(vector<int> &nums, int now) {
            if (now >= nums.size()) {
                result.push_back(nums);
                return;
            }
            unordered_set<int> hash;
            for (int i = now; i < nums.size(); i++) {
                if (i > now && hash.count(nums[i]) > 0) continue;
                hash.insert(nums[i]);
                swap(nums[i], nums[now]);
                dfs(nums, now + 1);
                swap(nums[i], nums[now]);
            }
        }
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            if (nums.empty()) return result;
            sort(nums.begin(), nums.end());
            dfs(nums, 0);
            return result;
        }
    private:
        vector<vector<int>> result;
};

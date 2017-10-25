class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> hash;
            for (int i = 0; i < nums.size(); i++) {
                int x = nums[i];
                auto it = hash.find(x);
                if (it != hash.end() && (it->second + k) >= i) {
                    return true;
                }
                hash[x] = i;
            }
            return false;
        }
};

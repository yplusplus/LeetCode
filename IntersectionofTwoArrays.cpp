class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); i++) {
            auto it = num_set.find(nums2[i]);
            if (it != num_set.end()) {
                result.push_back(*it);
                num_set.erase(it);
            }
        }
        return result;
    }
};
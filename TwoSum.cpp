class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > indexs(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            indexs[i] = make_pair(nums[i], i);
        }
        sort(indexs.begin(), indexs.end());
        vector<int> result;
        int L = 0, R = indexs.size() - 1;
        while (L < R) {
            int sum = indexs[L].first + indexs[R].first;
            if (sum == target) {
                result.push_back(indexs[L].second);
                result.push_back(indexs[R].second);
                break;
            } else if (sum > target) {
                R--;
            } else {
                L++;
            }
        }
        if (result[0] > result[1]) swap(result[0], result[1]);
        return result;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> lc;
        int ans = 0;
        for (auto num : nums) {
            if (lc.count(num)) continue;
            int left = lc.count(num - 1) ? lc[num - 1] : 0;
            int right = lc.count(num + 1) ? lc[num + 1] : 0;
            int sum = left + right + 1;
            ans = max(ans, sum);
            lc[num] = sum;
            lc[num - left] = sum;
            lc[num + right] = sum;
        }
        return ans;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = -1;
        int cnt = 0;
        for (auto num : nums) {
            if (cnt == 0 || ans == num) {
                cnt++;
                ans = num;
            } else {
                cnt--;
            }
        }
        return ans;
    }
};
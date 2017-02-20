class Solution {
public:
    static bool cmp(int a, int b) {
        string ab = to_string(a) + to_string(b);
        string ba = to_string(b) + to_string(a);
        return ab > ba;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) return "0";
        string ans;
        for (auto num : nums) {
            ans += to_string(num);
        }
        return ans;
    }
};
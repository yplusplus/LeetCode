// o(nlogn)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums.front() == nums.back()) return 0;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            ans += i * (nums[i - 1] - nums[i]);
        }
        return ans;
    }
};

// o(n)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int cur = nums[0];
        int ex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (ex + nums[i] >= cur) {
                int k = ex + nums[i] - cur;
                ans += k;
                cur = ex + nums[i];
                ex += k;
            } else {
                int k = cur - ex - nums[i];
                ans += k * i;
                cur = ex + nums[i] + k * i;
                ex += k * i;
            }
        }
        return ans;
    }
};

// o(n)
// increasing (n - 1) elements by 1 is equivalent to decreasing one elements by 1
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int min_num = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            min_num = min(min_num, nums[i]);
        }
        return sum - nums.size() * min_num;
    }
};
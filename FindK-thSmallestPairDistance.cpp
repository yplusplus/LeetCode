class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int L = 0, R = nums.back() - nums.front();
        int ans = -1;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            int count = countPairs(nums, mid);
            if (count >= k) {
                R = mid - 1;
                ans = mid;
            } else {
                L = mid + 1;
            }
        }
        return ans;
    }
    int countPairs(vector<int> &nums, int gap) {
        int p = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (p < i && nums[i] - nums[p] > gap) p++;
            count += i - p;
        }
        return count;
    }
};
class Solution {
    public:
        int maximumGap(vector<int>& nums) {
            if (nums.size() < 2) return 0;
            if (nums.size() == 2) return abs(nums[0] - nums[1]);
            int max_num = *max_element(nums.begin(), nums.end());
            int min_num = *min_element(nums.begin(), nums.end());
            int n = nums.size();
            int k = max(1, (max_num - min_num) / (n - 1));
            int buckets_num = (max_num - min_num) / k + 1;
            vector<pair<int, int> > buckets(buckets_num, {-1, -1});
            for (auto it = nums.begin(); it != nums.end(); it++) {
                int idx = (*it - min_num) / k;
                if (buckets[idx].first == -1 || buckets[idx].first > *it)
                    buckets[idx].first = *it;
                if (buckets[idx].second == -1 || buckets[idx].second < *it)
                    buckets[idx].second = *it;
            }
            int prev = buckets[0].second;
            int ans = 0;
            for (int i = 1; i < buckets.size(); i++) {
                if (buckets[i].first == -1) continue;
                ans = max(ans, buckets[i].first - prev);
                prev = buckets[i].second;
            }
            return ans;
        }
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        int min_num = nums[0];
        int max_num = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < min_num) min_num = nums[i];
            if (nums[i] > max_num) max_num = nums[i];
        }
        int bucket_size = (max_num - min_num) / ((int)nums.size() - 1);
        if (bucket_size == 0) bucket_size = 1;
        int bucket_num = (max_num - min_num) / bucket_size + 1;
        
        vector<int> bucket_min(bucket_num, -1);
        vector<int> bucket_max(bucket_num, -1);
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int idx = (x - min_num) / bucket_size;
            if (bucket_min[idx] == -1 || bucket_min[idx] > x) bucket_min[idx] = x;
            if (bucket_max[idx] == -1 || bucket_max[idx] < x) bucket_max[idx] = x;
        }
        
        int ans = 0;
        int last_max = -1;
        for (int i = 0; i < bucket_num; i++) {
            if (bucket_min[i] == -1) continue; // skip empty bucket
            if (last_max != -1) {
                ans = max(ans, bucket_min[i] - last_max);
            }
            last_max = bucket_max[i];
        }
        return ans;
    }
};
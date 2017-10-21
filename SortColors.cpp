class Solution {
public:
    void sortColors(vector<int>& nums) {
        int next_less_pos = 0;
        int next_bigger_pos = nums.size() - 1;
        int next_scan_pos = 0;
        while (next_scan_pos <= next_bigger_pos) {
            if (nums[next_scan_pos] < 1) {
                swap(nums[next_less_pos++], nums[next_scan_pos++]);
            } else if (nums[next_scan_pos] > 1) {
                swap(nums[next_bigger_pos--], nums[next_scan_pos]);
            } else {
                next_scan_pos++;
            }
        }
   }
};

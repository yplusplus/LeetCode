// O(nlogn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int L = 1, R = nums.size();
        int ans = -1;
        while (L <= R) {
            int mid = (L + R) / 2;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) cnt++;
            }
            if (cnt > mid) {
                R = mid - 1;
                ans = mid;
            }
            else L = mid + 1;
        }
        return ans;
    }
};

// o(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // now we meet in cycle
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
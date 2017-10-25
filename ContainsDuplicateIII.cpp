// O(nlogn)
class Solution {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
            set<int> s;
            for (int i = 0; i < nums.size(); i++) {
                if (i > k) s.erase(nums[i - k - 1]);
                auto it = s.lower_bound(nums[i]);
                if (it != s.end() && *it <= nums[i] + t) return true;
                if (it != s.begin()) {
                    it--;
                    if (nums[i] <= *it + t) return true;
                }
                s.insert(nums[i]);
            }
            return false;
        }
};

// O(n)
class Solution {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
            if (t < 0) return false;
            unordered_map<int, int> hash;
            int y = t + 1;
            for (int i = 0; i < nums.size(); i++) {
                if (i > k) hash.erase(getID(nums[i - k - 1], y));
                int x = getID(nums[i], y);
                if (hash.count(x) > 0) return true;
                auto it = hash.find(x - 1);
                if (it != hash.end() && it->second + t >= nums[i]) return true;
                it = hash.find(x + 1);
                if (it != hash.end() && nums[i] + t >= it->second) return true;
                hash[x] = nums[i];
            }
            return false;
        }
    private:
        inline int getID(int x, int y) {
            if (x >= 0)
                return x / y;
            else
                return (x + 1) / y - 1;
        }    
};

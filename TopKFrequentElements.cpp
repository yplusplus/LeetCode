class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int x : nums) {
            count[x]++;
        }
        set<pair<int, int>> s;
        for (auto it = count.begin(); it != count.end(); it++) {
            s.insert(make_pair(it->second, -(it->first)));
            while (s.size() > k) s.erase(s.begin());
        }
        vector<int> result;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            result.push_back(-it->second);
        }
        return result;
    }
};
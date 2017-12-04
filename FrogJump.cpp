class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;
        map<int, unordered_set<int> > dp;
        for (int i = 1; i < n; i++) {
            dp[stones[i]];
        }
        dp[1].insert(1);
        int target = stones.back();
        for (auto it = dp.begin(); it != dp.end(); it++) {
            int pos = it->first;
            unordered_set<int> &last_jumps = it->second;
            for (int last_jump : last_jumps) {
                for (int i = -1; i <= 1; i++) {
                    if (last_jump + i > 0 && i + last_jump <= target - pos) {
                        int next_pos = pos + i + last_jump;
                        auto next_pos_it = dp.find(next_pos);
                        if (next_pos_it == dp.end()) continue;
                        next_pos_it->second.insert(last_jump + i);
                    }
                }
            }
        }
        return !dp[target].empty();
    }
};
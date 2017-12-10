class Solution {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
            if (pairs.empty()) return 0;
            sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b){ return a.back() < b.back(); });
            int ans = 1;
            int end = pairs[0].back();
            for (int i = 1; i < pairs.size(); i++) {
                if (pairs[i].front() > end) {
                    ans++;
                    end = pairs[i].back();
                }
            }
            return ans;
        }
};

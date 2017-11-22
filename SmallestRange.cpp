class Solution {
public:
    typedef vector<int>::iterator vit;
    struct cmp {
        bool operator()(const pair<vit, vit> &lhs,
                const pair<vit, vit> &rhs) const {
            return *lhs.first > *rhs.first;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<vit, vit>, vector<pair<vit, vit>>, cmp> heap;
        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i][0];
            heap.push({nums[i].begin(), nums[i].end()});
            lo = min(lo, value);
            hi = max(hi, value);
        }
        vector<int> ans{lo, hi};
        while (true) {
            auto e = heap.top();
            heap.pop();
            e.first++;
            if (e.first == e.second) break;
            hi = max(hi, *e.first);
            heap.push(e);
            lo = *heap.top().first;
            if (hi - lo < ans[1] - ans[0])
                ans = {lo, hi};
        }
        return ans;
    }
};

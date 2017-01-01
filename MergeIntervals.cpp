/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    class cmp {
    public:
        bool operator()(const Interval &lhs, const Interval &rhs) const {
            if (lhs.start != rhs.start)
                return lhs.start < rhs.start;
            return lhs.end < rhs.end;
        }
    };
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.empty()) return result;
        sort(intervals.begin(), intervals.end(), cmp());
        for (int i = 0; i < intervals.size(); i++) {
            if (!result.empty() && intervals[i].start <= result.back().end) {
                result.back().end = max(result.back().end, intervals[i].end);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
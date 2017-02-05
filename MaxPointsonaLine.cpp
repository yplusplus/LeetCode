/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 1) return (int)points.size();
        int ans = 1;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> cnt;
            int same = 1;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same++;
                } else {
                    int d = __gcd(points[i].x - points[j].x, points[i].y - points[j].y);
                    int x = (points[i].x - points[j].x) / d;
                    int y = (points[i].y - points[j].y) / d;
                    cnt[make_pair(x, y)]++;
                }
            }
            int t = 0;
            for (auto it = cnt.begin(); it != cnt.end(); it++) t = max(t, it->second);
            ans = max(ans, same + t);
        }
        return ans;
    }
};
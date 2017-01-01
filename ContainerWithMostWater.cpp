class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int L = 0, R = height.size() - 1;
        while (L < R) {
            ans = max(ans, (R - L) * min(height[L], height[R]));
            if (height[L] < height[R]) L++;
            else R--;
        }
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int ans = 0;
        int L = 0, R = height.size() - 1;
        int h = 0;
        while (L < R) {
            if (height[L] < height[R]) {
                h = max(h, height[L]);
                ans += h - height[L];
                L++;
            } else {
                h = max(h, height[R]);
                ans += h - height[R];
                R--;
            }
        }
        return ans;
    }
    
};
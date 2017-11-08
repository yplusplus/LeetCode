class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y) return false;
        if (z == x || z == y || z == x + y) return true;
        return z % __gcd(x, y) == 0;
    }
};
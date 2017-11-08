class Solution {
public:
    int dightSquareSum(int n) {
        int sum = 0;
        while (n) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        int slow = n, fast = n;
        do {
            slow = dightSquareSum(slow);
            fast = dightSquareSum(dightSquareSum(fast));
        } while (slow != fast);
        return slow == 1;
    }
};
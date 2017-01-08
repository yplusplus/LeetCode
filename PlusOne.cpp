class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back() += 1;
        for (int i = digits.size() - 2; i >= 0; i--) {
            digits[i] += digits[i + 1] / 10;
            digits[i + 1] %= 10;
        }
        if (digits.front() >= 10) {
            digits.front() = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
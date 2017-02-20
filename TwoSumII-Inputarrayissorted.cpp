class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0, R = numbers.size() - 1;
        vector<int> result;
        while (L < R) {
            int sum = numbers[L] + numbers[R];
            if (sum == target) {
                result.push_back(L+1);
                result.push_back(R+1);
                break;
            } else if (sum < target) {
                L++;
            } else {
                R--;
            }
        }
        return result;
    }
};
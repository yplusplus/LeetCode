class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int L = 1, R = n;
        for (int i = 0; i < k; i++) {
            if (i % 2 == 0)
                result.push_back(L++);
            else
                result.push_back(R--);
        }
        if (k % 2 == 0) { 
            for (int i = R; i >= L; i--) {
                result.push_back(i);
            }
        } else {
            for (int i = L; i <= R; i++) {
                result.push_back(i);
            }
        }
        return result;
    }
};
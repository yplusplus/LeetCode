class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows <= 0) return result;
        result.push_back(vector<int>{1});
        for (int i = 1; i < numRows; i++) {
            vector<int> vec(i + 1);
            vec[0] = vec[i] = 1;
            for (int j = 1; j < i; j++) {
                vec[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(vec);
        }
        return result;
    }
};
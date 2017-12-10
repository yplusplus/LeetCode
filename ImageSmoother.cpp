class Solution {
    public:
        vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
            if (M.empty() || M[0].empty()) return {{}};
            vector<int> dir={0, -1, 1};
            vector<vector<int>> result(M.size(), vector<int>(M[0].size()));
            for (int i = 0; i < M.size(); i++) {
                for (int j = 0; j < M[0].size(); j++) {
                    int sum = 0, count = 0;
                    for (int dx: dir) {
                        if (i + dx >= 0 && i + dx < M.size()) {
                            for (int dy: dir) {
                                if (j + dy >= 0 && j + dy < M[0].size()) {
                                    sum += M[i+dx][j+dy];
                                    count++;
                                }
                            }
                        }
                    }
                    result[i][j] = sum / count;
                }
            }
            return result;
        }
};

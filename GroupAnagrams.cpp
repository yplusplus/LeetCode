class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        unordered_map<string, int> sstr2index;
        for (auto &str : strs) {
            string sstr(str);
            sort(sstr.begin(), sstr.end());
            if (sstr2index.count(sstr) == 0) {
                sstr2index[sstr] = result.size();
                result.push_back(vector<string>{str});
            } else {
                result[sstr2index[sstr]].push_back(str);
            }
        }
        return result;
    }
};
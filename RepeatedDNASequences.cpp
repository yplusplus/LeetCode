class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> pos;
        vector<string> result;
        for (int i = 0; i + 10 <= s.length(); i++) {
            const string sub = s.substr(i, 10);
            if (++pos[sub] == 2) result.push_back(sub);
        }
        return result;
    }
};
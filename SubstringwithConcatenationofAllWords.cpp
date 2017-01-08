class Solution {
public:
    void update(unordered_map<string, int> &targets, unordered_map<string, int> &count, int &cc, const string &str, int v) {
        auto it = targets.find(str);
        if (it == targets.end()) return;
        if (v > 0) {
            if (count[str] < targets[str]) cc++;
            else cc--;
        } else {
            if (count[str] > targets[str]) cc++;
            else cc--;
        }
        count[str] += v;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.length() == 0) return result;
        unordered_map<string, int> targets;
        for (const auto &str : words) {
            targets[str]++;
        }
        int len = words[0].length();
        for (int i = 0; i < len; i++) {
            unordered_map<string, int> count;
            int cc = 0;
            for (int k = 0; i + k * len < s.length(); k++) {
                update(targets, count, cc, s.substr(i + k * len, len), 1);
                int start = i + (k - words.size() + 1) * len;
                if (cc == words.size()) result.push_back(start);
                if (start >= 0)
                    update(targets, count, cc, s.substr(start, len), -1);
            }
        }
        return result;
    }
};
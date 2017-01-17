class Solution {
public:
    void update(vector<int> &need, vector<int> &curr, int &cc, int idx, int v) {
        if (need[idx] == 0) return;
        if (v > 0) {
            curr[idx]++;
            if (curr[idx] <= need[idx]) cc++;
        } else {
            curr[idx]--;
            if (curr[idx] < need[idx]) cc--;
        }
    }
    string minWindow(string s, string t) {
        if (t.length() == 0) return "";
        vector<int> need(256, 0);
        vector<int> curr(256, 0);
        for (char ch : t) {
            int pos = ch;
            need[pos]++;
        }
        int start = -1, len = s.length() + 1;
        int p = -1;
        int cc = 0;
        for (int i = 0; i < s.length(); i++) {
            while (p + 1 < s.length() && cc < t.length()) {
                p++;
                update(need, curr, cc, s[p], 1);
            }
            if (cc < t.length()) break;
            if (p - i + 1 < len) {
                len = p - i + 1;
                start = i;
            }
            update(need, curr, cc, s[i], -1);
        }
        string str;
        if (start != -1) str = s.substr(start, len);
        return str;
    }
};
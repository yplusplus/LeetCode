class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> cnt(256);
        for (char ch: s) cnt[ch]++;
        string ans;
        set<char> st;
        for (int i = 0; i < n; i++) {
            if (st.count(s[i])) {
                cnt[s[i]]--;
                continue;
            }
            while (!ans.empty() && ans.back() > s[i] && cnt[ans.back()] > 1) {
                cnt[ans.back()]--;
                st.erase(ans.back());
                ans.pop_back();
            }
            ans += s[i];
            st.insert(s[i]);
        }
        return ans;
    }
};

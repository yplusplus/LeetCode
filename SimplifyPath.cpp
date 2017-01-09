class Solution {
public:
    vector<string> split(const string &str, char ch) {
        vector<string> res;
        int prev = 0;
        int pos = 0;
        while (pos < str.length()) {
            pos = str.find(ch, prev);
            if (pos == string::npos) break;
            if (pos - prev > 0) res.push_back(str.substr(prev, pos - prev));
            prev = pos + 1;
        }
        if (prev < str.length()) res.push_back(str.substr(prev));
        return res;
    }
    string simplifyPath(string path) {
        vector<string> dirs = split(path, '/');
        stack<string> st;
        for (const auto &str : dirs) {
            if (str == ".") continue;
            if (str == "..") {
                if (!st.empty()) st.pop();
            } else {
                st.push(str);
            }
        }
        string res;
        while (!st.empty()) {
            if (res.length() > 0) res = "/" + res;
            res = st.top() + res;
            st.pop();
        }
        res = "/" + res;
        return res;
    }
};
// KMP, O(n)
class Solution {
    public:
        string shortestPalindrome(string s) {
            string rev(s);
            reverse(rev.begin(), rev.end());
            string ns = s + '#' + rev;
            vector<int> next(ns.length() + 1);
            int i = 0, j = -1;
            next[0] = -1;
            while (i < ns.length()) {
                if (j == -1 || ns[i] == ns[j]) {
                    i++;
                    j++;
                    next[i] = j;
                } else j = next[j];
            }
            return rev.substr(0, s.length() - next.back()) + s;
        }
};

// Manacher, O(n)

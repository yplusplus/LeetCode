class Solution {
public:
    bool isRight(char ch) {
        return ch == ')' || ch == ']' || ch == '}';
    }
    bool isMatch(char left, char right) {
        if (left == '(' && right == ')') {
            return true;
        } else if (left == '[' && right == ']') {
            return true;
        } else if (left == '{' && right == '}') {
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if (isRight(ch)) {
                if (st.empty() || !isMatch(st.top(), ch)) return false;
                st.pop();
            } else {
                st.push(ch);
            }
        }
        return st.empty();
    }
};
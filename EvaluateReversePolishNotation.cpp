class Solution {
public:
    int calc(int left, int right, char op) {
        switch (op) {
            case '+': return left + right;
            case '-': return left - right;
            case '/': return left / right;
            case '*': return left * right;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto &str : tokens) {
            if (str.length() == 1 && !isdigit(str[0])) {
                int right = st.top(); st.pop();
                int left = st.top(); st.pop();
                st.push(calc(left, right, str[0]));
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
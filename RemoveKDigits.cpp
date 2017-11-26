class Solution {
    public:
        string removeKdigits(string num, int k) {
            vector<char> vec;
            for (int i = 0; i < num.length(); i++) {
                char ch = num[i];
                while (!vec.empty() && k > 0 && vec.back() > ch) {
                    vec.pop_back();
                    k--;
                }
                if (ch == '0' && vec.empty()) continue;
                vec.push_back(ch);
            }
            if (k >= vec.size()) return "0";
            return string(vec.data(), vec.size() - k); 
        }
};

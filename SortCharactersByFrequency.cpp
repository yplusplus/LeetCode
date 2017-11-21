class Solution {
public:
    string frequencySort(string s) {
        int cnt[256] = {0};
        for (char ch : s) {
            cnt[ch]++;
        }
        vector<pair<int, int>> vec;
        for (int i = 0; i < 256; i++) {
            if (cnt[i] > 0) vec.push_back(make_pair(cnt[i], i));
        }
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        string res;
        for (const pair<int, int> &ele : vec) {
            res += string(ele.first, ele.second);
        }
        return res;
    }
    
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty() || n == 0) return (int)tasks.size();
        vector<int> cnt(26);
        int target = 0, target_num = 0;
        for (int i = 0; i < tasks.size(); i++) {
            int index = tasks[i] - 'A';
            cnt[index]++;
            if (cnt[index] > target) {
                target = cnt[index];
                target_num = 1;
            } else if (cnt[index] == target) {
                target_num++;
            }
        }
        int min_idle = max(0, (n + 1) * (target - 1) - ((int)tasks.size() - target_num));
        return min_idle + (int)tasks.size();
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (n == 0) return -1;
        int sum = 0;
        int mi = gas[0] - cost[0];
        for (int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
            mi = min(mi, sum);
        }
        if (sum < 0) return -1;
        for (int i = 0; i < n; i++) {
            if (mi >= 0) return i;
            mi -= gas[i] - cost[i];
        }
        return -1;
    }
};
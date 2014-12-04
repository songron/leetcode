class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        /* https://oj.leetcode.com/problems/gas-station/
        there is a valid starting index, iff sum_of_gas >= sum_of_cost
        */
        
        const int n = gas.size(), m = cost.size();
        assert(n == m);
        
        int start = 0, tank = 0, total = 0;
        
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        
        return total >= 0 ? start : -1;
    }
};
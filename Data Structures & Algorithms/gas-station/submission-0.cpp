class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int surplus = 0;
        for(int j = 0; j < gas.size(); ++j){
            surplus += (gas[j] - cost[j]);
        }
        if(surplus < 0) return -1;
        int tank = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); ++i){
            tank += (gas[i] - cost[i]);
            if(tank < 0){
                start = i+1;
                tank = 0;
            }
        }
        return start;
    }
};
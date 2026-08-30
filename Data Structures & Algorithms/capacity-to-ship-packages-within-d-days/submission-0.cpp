class Solution {
public:
    bool checkDays(vector<int>& weights, int days, int capacity){
        int n = weights.size();
        int idx = 0;

        for(int d = 0; d < days; ++d){
            int budget = capacity;
            while(budget >= 0 && idx < n){
                budget -= weights[idx];
                if(budget < 0) break;
                ++idx;
            }
        }
        return idx >= n;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int d = 0;
        int end = 0;
        int maxW = 0;
        for(auto w : weights){
            end += w;
            maxW = max(maxW, w);
        }
        int minW = INT_MAX;
        int start = maxW;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(checkDays(weights, days, mid)){
                end = mid - 1;
                minW = min(minW, mid);
            }else{
                start = mid + 1;
            }
        }


        return minW;
    }
};
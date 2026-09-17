class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int tSum = 0;
        for(auto s : stones){
            tSum += s;
        }

        int target = tSum / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        int largest = 0;
        for(auto x : stones){
            for(int w = target; w >= x; --w){
                dp[w] = dp[w] || dp[w - x];
                if(dp[w]) largest = max(largest, w);
            }
        }

        return ((tSum - largest) - largest);
    }
};
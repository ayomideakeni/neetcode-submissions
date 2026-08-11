class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int curSum = 0;
        int maxSum = INT_MIN;

        for(int x : nums){
            curSum = max(x, curSum + x);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
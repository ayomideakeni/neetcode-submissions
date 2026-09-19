class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();
        int maxSum = nums[0];
        int minSum = nums[0];

        int curSumMax = nums[0];
        int curSumMin = nums[0];

        int totalSum = nums[0];

        for(int i = 1; i < n; ++i){
            curSumMax = max(nums[i], curSumMax + nums[i]);

            curSumMin = min(nums[i], curSumMin + nums[i]);

            totalSum += nums[i];

           maxSum = max(maxSum, curSumMax);
           minSum = min(minSum, curSumMin);
        }

        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
        
    }
};
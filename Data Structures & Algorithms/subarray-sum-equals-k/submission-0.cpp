class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> preSums;
        preSums[0] = 1;


        int result = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(preSums.find(sum - k) != preSums.end()){
                result += preSums[sum - k];
            }
            ++preSums[sum];
            
        }


        return result;

    }
};
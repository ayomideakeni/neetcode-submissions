class Solution {
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        int maxJump = INT_MIN;
        if(n == 1)return 0;
        if(nums[0] >= n-1) return 1;

        int steps = 0;
        int currentEnd = 0;


       for(int i = 0; i < n -1 ; ++i){
            maxJump = max(maxJump, i+nums[i]);
            if(i == currentEnd){
                ++steps;
                currentEnd = maxJump;
                if(currentEnd >= n-1) return steps;
            }
             
        }
        return steps;
    
        


        
    }
};
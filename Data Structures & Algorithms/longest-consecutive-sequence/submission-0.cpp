class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());

        for(auto x : numSet){
            if(numSet.find(x - 1) == numSet.end()){
                int currentNum = x;
                int bestStreak = 1;

                while(numSet.count(currentNum + 1) != 0){
                    currentNum += 1;
                    bestStreak += 1;
                }
                longest = max(longest, bestStreak);
            }
        }
        return longest;
        


        

        
        return longest;
    }
};
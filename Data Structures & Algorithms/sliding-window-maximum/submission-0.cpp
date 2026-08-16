class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        int n = nums.size();
        int left = 0;
        vector<int> result;
        

        for(int i = 0; i < n; ++i){
            
            if(!(window.empty()) && window.front() <= i - k){
                window.pop_front();
            }
            while(!(window.empty()) && nums[i] > nums[window.back()]){
                window.pop_back();
            }

            window.push_back(i);

            if(i >= k - 1){
                result.push_back(nums[window.front()]);
            }
    
        }
        
        return result;
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        int n = nums.size();
        if( n < 2 || k < 1) return false;
        unordered_multiset<int> window;
        int right = 0;
        int left = 0;
        while(left < n){
            while(window.size() <= k && right < n){
                if(window.find(nums[right]) != window.end()) return true;
                window.insert(nums[right]);
                ++right;
            }
            window.erase(nums[left]);
            ++left;
        }
        return false;
    }
};
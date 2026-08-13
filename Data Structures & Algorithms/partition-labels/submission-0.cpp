class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        unordered_map<int, int> freq;

        for(size_t i{}; i < s.size(); ++i){
            freq[s[i] - 'a'] = i;
        }

        bool extending = false;
        int extendSize = 0;
        int end = 0;
        int start = 0;
        for(int x = 0; x < s.size(); ++x){
            end = max(end, freq[s[x] - 'a']);
            if(x == end){
                result.push_back(end - start + 1);
                start = x +1;
            }
        }
        return result;
        
    }
};
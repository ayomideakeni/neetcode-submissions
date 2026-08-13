class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        map<int,int> freq;
        
        for(auto nums : hand){
            freq[nums]++;
        }

        for(auto const& [card,count] : freq){
            if(count > 0){
                if(freq[card] == 0) continue;
                int startCount = freq[card];
               for (int i = 0; i <= groupSize-1; ++i){
                if(freq.find(card+i) == freq.end() || freq[card+i] < startCount) return false;
                freq[card+ i] -= startCount;
               }
            }
        }
        return true;
        
    }
};
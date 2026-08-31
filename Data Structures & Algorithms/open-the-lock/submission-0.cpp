class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        string comb = "0000";
        unordered_set<string> blocked;
        unordered_set<string> visited;
        queue<pair<string,int>> q;
        if(target == comb) return 0;
        for(auto d : deadends){
            if(d == "0000") return -1;
            blocked.insert(d);
        }

        q.push({comb, 0});
        visited.insert(comb);

        while(!q.empty()){
            auto [lock, stops] = q.front();
            q.pop();
            if(lock == target) return stops;
            for(int n = 0; n < lock.size(); ++n){
                string upLock = lock;
                string downLock = lock;
                auto num = lock[n];
                upLock[n] = (num - '0' + 1) % 10 + '0';
                if(upLock == target) return stops+1;
                if((blocked.find(upLock) == blocked.end() && visited.find(upLock) == visited.end())){
                    q.push({upLock, stops+1});
                    visited.insert(upLock);
                }
                downLock[n] = (num - '0' - 1 + 10) % 10 + '0';
                if(downLock == target) return stops+1;
                if(blocked.find(downLock) == blocked.end() && visited.find(downLock) == visited.end()){
                    q.push({downLock, stops+1});
                    visited.insert(downLock);
                }
                
            }
        }
        return -1;

    }
};
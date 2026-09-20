class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {

        priority_queue<int, vector<int>, greater<>> available;
        priority_queue<pair<long long,int>, vector<pair<long long ,int>>, greater<>> used;
        //store end times and rooms

        
        unordered_map<int,int> roomUses;

        vector<vector<int>> meetings = m;

        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});

        for(int i = 0; i < n; ++i){
            available.push(i);
            roomUses[i] = 0;
        }

        //store delayed meetings when room becomes free meeting start - delayed start and add it to both ends of delayed
        for(auto meet : meetings){
            long long start = meet[0], end = meet[1];

            while(!used.empty() && used.top().first <= start){
                int room = used.top().second;
                used.pop();
                available.push(room);
            }

            if(!available.empty()){
                int room = available.top();
                available.pop();

                used.push({end, room});
                ++roomUses[room];

            }else{
                auto [soonestEnd, room] = used.top();
                used.pop();
                used.push({(end - start) + soonestEnd ,room});
                ++roomUses[room];
                
                
            }
        }

        int mostBookedIdx = 0;
        for(auto r : roomUses){
            if(r.second > roomUses[mostBookedIdx]) mostBookedIdx = r.first;
            else if(r.second == roomUses[mostBookedIdx]) mostBookedIdx = min(r.first, mostBookedIdx);
        }

        return mostBookedIdx;
        
    }
};
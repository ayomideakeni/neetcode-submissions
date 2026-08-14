class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        vector<int> result(queries.size(), -1);

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0];});

        vector<pair<int,int>> sortedQueries;
        for(int j = 0; j < queries.size(); ++j){
            sortedQueries.push_back({queries[j], j});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        int i = 0;
        for(auto [q,pos] : sortedQueries){
            while(i < intervals.size() && intervals[i][0] <= q){
                    minHeap.push({intervals[i][1]-intervals[i][0]+1,intervals[i][1]});
                ++i;
            }
            
                
            
            while(!minHeap.empty() && minHeap.top().second < q){
                    minHeap.pop();
                }
                if(!minHeap.empty()){
                    result[pos] = minHeap.top().first;
                }
            
        }

        return result;

    }
};
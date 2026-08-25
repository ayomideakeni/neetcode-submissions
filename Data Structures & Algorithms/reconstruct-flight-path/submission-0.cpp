class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<>>> adj;
        vector<string> result;

        for(auto t : tickets){
            adj[t[0]].push(t[1]);
        }
        stack<string> stack;

        stack.push("JFK");

        while(!stack.empty()){
            auto node = stack.top();
            if(!adj[node].empty()){
                auto next = adj[node].top();
                adj[node].pop();
                stack.push(next);
            }else{
                result.push_back(node);
                stack.pop();
            }
            
        }
        reverse(result.begin(), result.end());
        return result;

    }
};
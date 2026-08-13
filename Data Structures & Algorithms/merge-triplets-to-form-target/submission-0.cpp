class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<vector<int>> validTriplets;

            

        for(int j = 0; j < n; ++j){
            int a = triplets[j][0];
            int b = triplets[j][1];
            int c = triplets[j][2];

            if(a > target[0] || b > target[1] || c > target[2]){
                continue;
            }
            validTriplets.push_back({a,b,c});
        }
        if(validTriplets.empty()) return false;
        bool fA = false;
        bool fB = false;
        bool fC = false;


        for(int i = 0; i < validTriplets.size(); ++i){
            auto trip = validTriplets[i];
            if(trip[0] == target[0]) fA = true;
            if(trip[1] == target[1]) fB = true;
            if(trip[2] == target[2]) fC = true;
            
        }
        return(fA && fB && fC);
        
    }
};
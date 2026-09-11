class Solution {
public:
    int calPoints(vector<string>& operations) {
        int result = 0;
        vector<int> scores;
        for(auto s : operations){
            if(s == "D"){
                scores.push_back(scores.back() * 2);
            }else if (s == "C"){
                scores.pop_back();
            }else if( s == "+"){
                int last = scores.size() - 1;
                scores.push_back(scores[last] + scores[last - 1]);
            }
            else{
                scores.push_back(stoi(s));
            }
        }
        for(auto n : scores){
            result += n;
        }
        return result;
    }
};
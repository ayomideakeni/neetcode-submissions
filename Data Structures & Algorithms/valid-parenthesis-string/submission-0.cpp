class Solution {
public:
    bool checkValidString(string s) {
        int hi = 0;
        int lo = 0;

        for(int i{}; i < s.size(); ++i){
            if(s[i] == '('){
                ++hi;
                ++lo;
            }else if(s[i] == ')'){
                --hi;
                --lo;
            }else{
                ++hi;
                --lo;
            }
            if(hi < 0) return false;
            if(lo < 0) lo = 0;
        }
        return (lo == 0);

    }
    
};
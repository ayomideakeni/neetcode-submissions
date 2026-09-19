class Solution {
public:
    bool checkPalindrome(int left, int right, string s){
        while(left < right){
            if(s[left] != s[right]) return false;

            ++left;
            --right;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        //if(s.size() == 1) return true;
        //if(s.empty())return false;

        int i = 0;
        int j = s.size() - 1;

        while(i < j){

            if(s[i] != s[j]){
                return (checkPalindrome(i, j - 1, s) || checkPalindrome(i + 1, j, s));
            }else{
                i++;
                j--;
            }

            
        }
        
        return true;
        
    }
};
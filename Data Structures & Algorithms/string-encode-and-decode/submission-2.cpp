class Solution {
public:
// Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;

        for (string str : strs) {
            auto c = to_string(str.size());
            result += ((c += "#") + str);
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        string current;
        string scount;
        int sc;

        int read = 0;
        int write = 0;
        while(write < s.size()){
            while(isdigit(s[read])){
            scount += s[read];
            ++read;
        }
        if(scount.size() != 0){
        sc = stoi(scount) + read;
        scount.clear();
        }
        



        if(sc >= 0){
            if(sc == 0){
                result.push_back(current);
            }else{
                write = read + 1;
                read = sc + 1; 
                while(write <= sc){
                    current.push_back(s[write]);
                    ++write;
                }
            }
            result.push_back(current);
            current.clear();
        }
        

        }
        

        return result;
    }

};

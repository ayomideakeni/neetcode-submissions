class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int minStops = INT_MAX;
        

        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        unordered_set<string> wList;
        
        for(auto s : wordList){
            wList.insert(s);
        }
        unordered_set<string> visited;

        queue<pair<int,string>> queue;
        
        queue.push({0, beginWord});

        while(!queue.empty()){
            auto [dst, word] = queue.front();
            queue.pop();
            if(word == endWord) return dst + 1;
            for(int i = 0; i < word.size(); ++i){
                string cWord = word;
                for(int j = 0; j < 26; ++j){
                    cWord[i] = 'a' + j;
                    if(wList.find(cWord) != wList.end() && visited.find(cWord) == visited.end()){
                        if(cWord != word) queue.push({dst + 1,cWord});
                        visited.insert(cWord);
                    }
                }
            }
            

        }


        return 0;
    }
};


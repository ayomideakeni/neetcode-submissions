class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> adj;
        string result = "";

        for (string word : words) {
            for (char c : word) {
                if (indegree.find(c) == indegree.end()) {
                    indegree[c] = 0;
                    adj[c] = {};
                }
            }
        }

        for (int j = 0; j < words.size() - 1; ++j) {
            string w = words[j];
            string w1 = words[j + 1];
            auto minLen = min(w.size(), w1.size());
            if (w.size() > w1.size() && w.substr(0, minLen) == w1.substr(0, minLen)) return "";
            unordered_set<char> checked;
            for (int i = 0; i < minLen; ++i) {
                char u = w[i];
                char v = w1[i];
                if (u != v) {
                    if (adj[u].find(v) == adj[u].end()) {
                        adj[u].insert(v);
                        indegree[v]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for (auto& [ch, degree] : indegree) {
            if (degree == 0) q.push(ch);
        }
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;
            for (char neighbour : adj[curr]) {
                --indegree[neighbour];
                if (indegree[neighbour] == 0) q.push(neighbour);
            }
        }

        if (result.size() < indegree.size())
            return "";
        else
            return result;
    }
};
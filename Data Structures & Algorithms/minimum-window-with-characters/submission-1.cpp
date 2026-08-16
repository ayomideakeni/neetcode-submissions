class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int left = 0;
        int right = 0;

        int matches = 0;
        int minStart = 0;
        int minLength = INT_MAX;

        unordered_map<char, int> nFreq;

        for (char ch : t) {
            nFreq[ch]++;
        }

        while (right < n) {
            auto it = nFreq.find(s[right]);

            if (it != nFreq.end()) {
                if (it->second > 0) {
                    matches++;
                }

                it->second--;
            }

            while (matches == t.size()) {
                int windowLength = right - left + 1;

                if (windowLength < minLength) {
                    minStart = left;
                    minLength = windowLength;
                }

                auto leftIt = nFreq.find(s[left]);

                if (leftIt != nFreq.end()) {
                    leftIt->second++;

                    if (leftIt->second > 0) {
                        matches--;
                    }
                }

                left++;
            }

            right++;
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(minStart, minLength);
    }
};
class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        int n = intervals.size();
        int overlapCount = 0;

        int prevEnd = intervals[0][1];

        for (int i = 1; i < n; ++i) {
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];

            if (curStart < prevEnd) {
                ++overlapCount;
                prevEnd = min(prevEnd, curEnd);
            } else {
                prevEnd = curEnd;
            }
        }
        return overlapCount;
    }
};
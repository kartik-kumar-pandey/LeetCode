class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end());
        v.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            vector<int>& last = v.back();
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            if (currentStart <= last[1]) {
                last[1] = max(last[1], currentEnd);
            } else {
                v.push_back(intervals[i]);
            }
        }
        return v;
    }
};
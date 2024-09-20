class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        
        // Sort the intervals based on the start time
        sort(intervals.begin(), intervals.end());

        for (auto interval : intervals) {
            // If mergedIntervals is empty or there is no overlap, add the interval to mergedIntervals
            if (mergedIntervals.empty() || mergedIntervals.back()[1] < interval[0]) {
                mergedIntervals.push_back(interval);
            } else {
                // If there is an overlap, merge the intervals by updating the end time
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
            }
        }

        return mergedIntervals;
    }
};

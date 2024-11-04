class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using P = pair<int, pair<int, int>>;
        priority_queue<P, vector<P>, greater<P>> pq;
        int maxVal = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        int rangeStart = -100000, rangeEnd = 100000;
        while (true) {
            auto [val, pos] = pq.top();
            pq.pop();
            int listIdx = pos.first, idx = pos.second;

            if (maxVal - val < rangeEnd - rangeStart) {
                rangeStart = val;
                rangeEnd = maxVal;
            }

            if (idx + 1 == nums[listIdx].size()) break;

            int nextVal = nums[listIdx][idx + 1];
            pq.push({nextVal, {listIdx, idx + 1}});
            maxVal = max(maxVal, nextVal);
        }

        return {rangeStart, rangeEnd};
    }
};

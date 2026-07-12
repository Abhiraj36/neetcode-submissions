class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        // Step 1: Sort intervals by start
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        // Step 2: Traverse and merge
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                // Overlaps → merge
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // No overlap → push as is
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};

class Solution {
public:
    void backtrack(vector<int>& nums, int target, vector<int>& comb, vector<vector<int>>& res, int start) {
        if (target == 0) {
            res.push_back(comb);  // found a valid combination
            return;
        }
        if (target < 0) return;  // exceed target

        for (int i = start; i < nums.size(); i++) {
            comb.push_back(nums[i]);           // choose nums[i]
            backtrack(nums, target - nums[i], comb, res, i);  // i instead of i+1 allows reuse
            comb.pop_back();                   // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(nums, target, comb, res, 0);
        return res;
    }
};

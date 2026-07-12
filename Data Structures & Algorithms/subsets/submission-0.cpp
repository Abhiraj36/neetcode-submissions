class Solution {
public:
    vector<vector<int>> results;

    void solve(vector<int>& nums, int i, vector<int>& temp) {
        if (i >= nums.size()) {
            results.push_back(temp);
            return;
        }

        // Include nums[i]
        temp.push_back(nums[i]);
        solve(nums, i + 1, temp);

        // Backtrack
        temp.pop_back();

        // Exclude nums[i]
        solve(nums, i + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0, temp);
        return results;
    }
};

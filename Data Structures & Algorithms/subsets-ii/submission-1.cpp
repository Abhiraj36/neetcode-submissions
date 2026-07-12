class Solution {
public:
    vector<vector<int>> results;

    void solve(vector<int>& nums, int index, vector<int>& temp) {
        results.push_back(temp);

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);
            solve(nums, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        //results.clear();
        solve(nums, 0, temp);
        return results;
    }
};

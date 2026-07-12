class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
        }

        int longest = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            // Only start counting if it's the beginning of a sequence
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int count = 1;

                while (s.find(currentNum + 1) != s.end()) {
                    currentNum += 1;
                    count += 1;
                }

                if (count > longest) {
                    longest = count;
                }
            }
        }

        return longest;
    }
};

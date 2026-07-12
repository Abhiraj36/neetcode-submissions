class Solution { 
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end()); // build set directly
        int longest = 0;

        for (int num : s) {   // iterate over set, not nums (avoids duplicates)
            // only start counting if it's the beginning of a sequence
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int count = 1;

                while (s.find(currentNum + 1) != s.end()) {
                    currentNum += 1;
                    count += 1;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int totalJumps = 0;
        int coverage = 0;
        int lastJumpIndex = 0;
        int destination = nums.size() - 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            coverage = max(coverage, i + nums[i]);

            if (i == lastJumpIndex) { // must jump now
                totalJumps++;
                lastJumpIndex = coverage;

                if (coverage >= destination)
                    return totalJumps;
            }
        }

        return totalJumps;
    }
};


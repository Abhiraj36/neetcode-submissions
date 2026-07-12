class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int l = 0, maxCount = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxCount = max(maxCount, count[s[r] - 'A']); 

            // if more than k replacements are needed, shrink window
            while ((r - l + 1) - maxCount > k) {
                count[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};

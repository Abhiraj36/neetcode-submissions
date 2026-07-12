class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if (t.length() > n) return "";

        unordered_map<char, int> mp;
        for (char &ch : t) {
            mp[ch]++;
        }

        int requiredCount = t.length();
        int i = 0, j = 0;

        int windowSize = INT_MAX;
        int start_i = 0;

        while (j < n) {
            char ch = s[j];

            // If this char is still needed
            if (mp[ch] > 0) {
                requiredCount--;
            }

            mp[ch]--; // Decrease count in all cases
           
            // When all characters are matched
            while (requiredCount == 0) {
                int currWindowSize = j - i + 1;
                if (windowSize > currWindowSize) {
                    windowSize = currWindowSize;
                    start_i = i;
                }

                // Try to shrink the window
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    requiredCount++;
                }
                i++;
            }
            j++;
        }

        return windowSize == INT_MAX ? "" : s.substr(start_i, windowSize);
    }
};


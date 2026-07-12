class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> result;
        vector<int> lastIndex(26, -1);

        // Store last occurrence of each character
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        int i = 0;
        while (i < n) {
            int end = lastIndex[s[i] - 'a'];
            int j = i;

            // Expand the window until all chars in it are contained
            while (j <= end) {
                end = max(end, lastIndex[s[j] - 'a']);
                j++;
            }

            // Store length of this partition
            result.push_back(j - i);
            i = j;
        }

        return result;
    }
};


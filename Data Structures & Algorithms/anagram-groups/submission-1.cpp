class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            vector<int> count(26, 0);

            // Count frequency of each character
            for (int j = 0; j < s.size(); ++j) {
                count[s[j] - 'a']++;
            }

            // Build key like "a2b1c1"
            string key = "";
            for (int k = 0; k < 26; ++k) {
                if (count[k] > 0) {
                    key += (char)('a' + k);         // character
                    key += to_string(count[k]);     // frequency
                }
            }

            // Push original string to corresponding group
            mp[key].push_back(s);
        }

        // Convert map values to result vector
        vector<vector<string>> result;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            result.push_back(it->second);
        }

        return result;
    }
};


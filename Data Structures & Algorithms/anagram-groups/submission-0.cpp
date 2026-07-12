class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            vector<int> count(26, 0);

            for (int j = 0; j < s.size(); ++j) {
                count[s[j] - 'a']++;
            }

            string key = to_string(count[0]);
            for (int k = 1; k < 26; ++k) {
                key += "," + to_string(count[k]);
            }

            res[key].push_back(s); 
        }

        vector<vector<string>> result;
        unordered_map<string, vector<string>>::iterator it;
        for (it = res.begin(); it != res.end(); ++it) {
            result.push_back(it->second);
        }

        return result;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       unordered_map<int, int> freq;

for (int i : nums)
    freq[i]++;

for (auto &p : freq)
    if (p.second == 1)
        return p.first;

    }
};

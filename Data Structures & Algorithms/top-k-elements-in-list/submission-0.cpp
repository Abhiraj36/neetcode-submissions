class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freqMap;
        for(int num : nums) {
            freqMap[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n+1);
          
        unordered_map<int,int> :: iterator it;
        for(it = freqMap.begin(); it!= freqMap.end(); it++){
            int num = it->first;
            int freq = it->second;
            buckets[freq].push_back(num);
        }  

        vector<int> result;
         for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int j = 0; j < buckets[i].size(); ++j) {
                result.push_back(buckets[i][j]);
                if (result.size() == k)
                    break;
            }
        }

        return result;

    }
};

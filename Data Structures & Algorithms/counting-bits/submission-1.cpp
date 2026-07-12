class Solution {
public:
    vector<int> countBits(int n) {
        //int x = n;
        vector<int> results;
        
        results.push_back(0);

        for(int i = 1; i <= n; i++) {
            int y = i;
            int count = 0;
            while(i!= 0){
                count += (i%2);
                i = (i/2);
            }
            results.push_back(count);
            i = y;
        }
        return results;
    }
};

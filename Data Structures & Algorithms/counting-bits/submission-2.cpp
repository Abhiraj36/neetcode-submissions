class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> results(n+1);

        results[0] = 0;
        if (n == 0) return results;

        for(int i =0; i<=n; i++){
            if(i%2 != 0){
                results[i] = results[i/2]+1;
            } else {
                results[i] = results[i/2];
            }
        } return results;
    }
};

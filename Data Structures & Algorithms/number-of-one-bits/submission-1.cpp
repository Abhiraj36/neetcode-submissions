class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        int i = 0;
        while( i<=32) {
            if(n%2 == 1) {
                count++;
            }
            n = n >>1;
            i++;
        } return count;
    }  //can also do it with n = n & (n-1)
};
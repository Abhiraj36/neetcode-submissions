class Solution {
public:
    vector<int> countBits(int n) {
         vector<int> nums;
        for(int j =0;j<=n;j++) {
            nums.push_back(j);
        }

        for(int k=0; k <nums.size(); k++) {
            int x = nums[k];
            int count=0, i = 0;
            while(i <= 32) {   
                if ((x%2)==1){
                                count++;
                               }  
                 x = x >> 1; 
                 i++;     
   } 
   nums[k] = count;
   }
 return nums;
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low = 0;
        int high = heights.size()-1;
        int maxarea = 0;
        int area = 0;   
        while (low < high) {
              area = (high-low)*min(heights[high], heights[low]);
              maxarea = max(maxarea,area);

              if(heights[low] < heights[high]) {
                low++;
              }
              else{
                high --;
              }
        }
        return maxarea;
    }
};

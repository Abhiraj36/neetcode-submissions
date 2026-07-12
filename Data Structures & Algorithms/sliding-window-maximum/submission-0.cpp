#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> deq;  //  declare the deque

        for (int i = 0; i < n; i++) {
            // Remove elements out of current window
            while (!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }

            // Maintain decreasing order in deque
            while (!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }

            // Add current index
            deq.push_back(i);

            // Once window reaches size k, record the max
            if (i >= k - 1) {
                result.push_back(nums[deq.front()]);
            }
        }

        return result;
    }
};

